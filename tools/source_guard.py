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

RAW_POINTER_ERROR = (
    "Access of struct fields through raw pointer math is not allowed. Don't try to rewrite it in a "
    "hacky way just to get it to compile. You must use proper field access or virtual function calls"
)
ASM_ERROR = "Inline asm is prohibited."


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