TIMESTAMP=$(date +"%Y%m%d_%H%M%S")
OUT_DIR="./AHC/043/out/$TIMESTAMP"
SCORE_DIR="./AHC/043/score/$TIMESTAMP"
mkdir -p "$SCORE_DIR"
mkdir -p "$OUT_DIR"

for infile in ./AHC/043/in/*.txt; do
  outfile="$OUT_DIR/$(basename "$infile")"
  scorefile="$SCORE_DIR/$(basename "$infile")"
  ./problem.exe < "$infile" > "$outfile" 2> "$scorefile"
done
