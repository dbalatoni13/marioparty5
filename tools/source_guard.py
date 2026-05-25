#!/usr/bin/env python3

import argparse
import re
import sys
from pathlib import Path

RAW_POINTER_REGEX = re.compile(
    r"(?:"
    r"cast<[^>]*\*[^>]*>\(.*\)"  # C++: cast<T*>(ptr)
    r"|"
    r"\([^)]*\*\s*\)[^+]*"       # C: (T*)ptr
    r")"
    r"\s*\+\s*0x"
)
ASM_REGEX = re.compile(r"\basm\b")
REGISTER_REGEX = re.compile(r"\bregister\b")
VOLATILE_REGEX = re.compile(r"\bvolatile\b")
DECLSPEC_SECTION_REGEX = re.compile(r"__declspec\s*\(\s*section.*")
FLOAT_GLOBAL_REGEX = re.compile(r"(float|double) lbl_1_rodata.*=\s*\d+.*;")

RAW_POINTER_ERROR = (
    "Access of struct fields through raw pointer math is not allowed. Don't try to rewrite it in a "
    "hacky way just to get it to compile. You must use proper field access or virtual function calls"
)
ASM_ERROR = "Inline asm is prohibited."
REGISTER_ERROR = (
    "The register keyword is prohibited, the devs didn't use it. To fix regalloc, make sure that "
    "variables are declared in a register-descending order, var_r31, var_r30, var_r29, etc., same for float variables."
)
VOLATILE_ERROR = "The volatile keyword is prohibied, the devs didn't use it."
DECLSPEC_SECTION_ERROR = (
    "You aren't allowed to use declspec to force globals into a specific data section. "
    "Figure out the proper C/C++ way, for example applying the const modifier for rodata."
)
FLOAT_GLOBAL_ERROR = "You must plug float constants directly into functions."

def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Guard source files against AI slop."
    )
    parser.add_argument("src_file", help="Path to file to be guarded against AI slop")
    parser.add_argument("stamp", help="Output stamp path")
    return parser.parse_args()


def check_file(source_file: Path) -> list[tuple[int, str]]:
    violations: list[tuple[int, str]] = []
    text = source_file.read_text(encoding="utf-8")

    for line_number, line in enumerate(text.splitlines(), start=1):
        if RAW_POINTER_REGEX.search(line):
            violations.append((line_number, RAW_POINTER_ERROR))
        if ASM_REGEX.search(line):
            violations.append((line_number, ASM_ERROR))
        if REGISTER_REGEX.search(line):
            violations.append((line_number, REGISTER_ERROR))
        if VOLATILE_REGEX.search(line):
            violations.append((line_number, VOLATILE_ERROR))
        if DECLSPEC_SECTION_REGEX.search(line):
            violations.append((line_number, DECLSPEC_SECTION_ERROR))
        if FLOAT_GLOBAL_REGEX.search(line):
            violations.append((line_number, FLOAT_GLOBAL_ERROR))

    return violations


def main() -> int:
    args = parse_args()
    src_file = Path(args.src_file)
    stamp = Path(args.stamp)

    if not src_file.is_file():
        print(f"Missing source file: {src_file}")
        return 1

    failures = 0

    for line_number, message in check_file(src_file):
        print(f"{src_file}:{line_number}: {message}")
        failures += 1

    if failures > 0:
        return 1

    stamp.parent.mkdir(parents=True, exist_ok=True)
    stamp.write_text("ok\n", encoding="utf-8")
    return 0


if __name__ == "__main__":
    sys.exit(main())
