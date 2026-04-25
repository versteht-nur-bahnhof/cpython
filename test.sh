#! /bin/sh
set -e
python3 Tools/wasm/wasi make-host --quiet
wasmtime wizer -S cli=y --dir /workspace::/ cross-build/wasm32-wasip1/python.wasm -o cross-build/wasm32-wasip1/python.init.wasm
weval weval -i cross-build/wasm32-wasip1/python.init.wasm -o cross-build/wasm32-wasip1/python.wevaled.wasm

if test "$1" = benchmark; then
    results_file="$(mktemp -u results-XXX.json)"
    hyperfine -w 3 --export-json "$results_file" \
              'wasmtime run --dir /workspace::/ cross-build/wasm32-wasip1/python.wasm main.py' \
              'wasmtime run --dir /workspace::/ cross-build/wasm32-wasip1/python.init.wasm' \
              'wasmtime run --dir /workspace::/ cross-build/wasm32-wasip1/python.wevaled.wasm' \
              'cross-build/x86_64-redhat-linux-gnu/python main.py'
    echo "results in $results_file"
else
    wasmtime run --dir /workspace::/ cross-build/wasm32-wasip1/python.wevaled.wasm
fi
