CASE=$1
TIMESTAMP=$(date +"%Y%m%d_%H%M%S")
OUT_DIR="./AHC/043/out/$CASE/$TIMESTAMP"
SCORE_DIR="./AHC/043/score/$CASE/$TIMESTAMP"
mkdir -p "$SCORE_DIR"
mkdir -p "$OUT_DIR"

for infile in ./AHC/043/in/$CASE/*.txt; do
  outfile="$OUT_DIR/$(basename "$infile")"
  scorefile="$SCORE_DIR/$(basename "$infile")"
  ./problem.exe < "$infile" > "$outfile" 2> "$scorefile"
done

python3 -u "/home/cyan/competitive-programming/AHC/043/check.py" $CASE
