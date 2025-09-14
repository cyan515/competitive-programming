#!/usr/bin/env python3
import subprocess
import sys
from pathlib import Path

NUM_LINES = 14
START = 0
END = 100  # inclusive
EXE = "../../problem.exe"
IN_DIR = Path("./in")
OUT_FILE = Path("averages.txt")

sums = [0.0] * NUM_LINES
runs = 0

for i in range(START, END + 1):
    infile = IN_DIR / f"{i:04d}.txt"
    if not infile.exists():
        print(f"[ERROR] input file not found: {infile}", file=sys.stderr)
        sys.exit(1)

    print(f"Running {EXE} {infile} ...", flush=True)
    # run the program, capture stderr as text, ignore stdout
    try:
        proc = subprocess.run([EXE, str(infile)],
                              stdout=subprocess.DEVNULL,
                              stderr=subprocess.PIPE,
                              text=True,
                              check=False)
    except FileNotFoundError:
        print(f"[ERROR] executable not found: {EXE}", file=sys.stderr)
        sys.exit(1)
    except Exception as e:
        print(f"[ERROR] failed to run {EXE} on {infile}: {e}", file=sys.stderr)
        sys.exit(1)

    stderr_text = proc.stderr.rstrip("\n")
    lines = stderr_text.splitlines() if stderr_text != "" else []

    if len(lines) != NUM_LINES:
        print(f"[ERROR] expected {NUM_LINES} lines on stderr but got {len(lines)} for {infile}", file=sys.stderr)
        print("---- stderr begin ----", file=sys.stderr)
        print(stderr_text, file=sys.stderr)
        print("---- stderr  end  ----", file=sys.stderr)
        sys.exit(1)

    # parse and accumulate
    for idx, line in enumerate(lines):
        try:
            val = float(line.strip())
        except ValueError:
            print(f"[ERROR] could not parse float on line {idx+1} for {infile}: '{line}'", file=sys.stderr)
            sys.exit(1)
        sums[idx] += val

    runs += 1

if runs == 0:
    print("[ERROR] no runs were processed.", file=sys.stderr)
    sys.exit(1)

averages = [s / runs for s in sums]

# write averages to file
with OUT_FILE.open("w", encoding="utf-8") as f:
    for avg in averages:
        f.write(f"{avg:.12g}\n")  # 12 significant digits, remove trailing zeros

print(f"Processed {runs} runs. Averages written to {OUT_FILE}.")
