#!/usr/bin/env sh

asm_file="$1"
ctx_base="$2"
output_file="$3"
extra="$4"
extra2="$5"

if [ -z "$asm_file" ] || [ -z "$ctx_base" ] || [ -z "$output_file" ]; then
    echo "Usage: $0 <asm_file> <ctx_base> <output_file> [extra] [extra2]"
    exit 1
fi

python3 ./tools/decompctx2.py "$ctx_base" --m2c -o /tmp/ctx.cpp

python3 ../m2c/m2c.py \
    -t ppc-mwcc-c++ \
    --unk-underscore \
    --no-casts \
    --reg-vars r14,r15,r16,r17,r18,r19,r20,r21,r22,r23,r24,r25,r26,r27,r28,r29,r30,r31,f14,f15,f16,f17,f18,f19,f20,f21,f22,f23,f24,f25,f26,f27,f28,f29,f30,f31 \
    --knr \
    --descending-regs \
    --backwards-bss \
    --no-stack-spill \
    --context /tmp/ctx.cpp \
    "$asm_file" > "$output_file"

python3 ./tools/m2c_cleanup.py "$asm_file" "$output_file"
clang-format -i "$output_file"
sed -i 's/^/\/\//' "$output_file"
cat ./dummy_ctx_base.c "$output_file" > /tmp/decomp_tmp && mv /tmp/decomp_tmp "$output_file"