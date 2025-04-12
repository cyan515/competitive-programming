CASE=$1
TIMESTAMP=$(date +"%Y%m%d_%H%M%S")
OUT_DIR="./AHC/044/out/$CASE/$TIMESTAMP"
SCORE_DIR="./AHC/044/score/$CASE/$TIMESTAMP"
mkdir -p "$SCORE_DIR"
mkdir -p "$OUT_DIR"

for infile in ./AHC/044/in/$CASE/*.txt; do
  outfile="$OUT_DIR/$(basename "$infile")"
  scorefile="$SCORE_DIR/$(basename "$infile")"
  ./problem.exe < "$infile" > "$outfile" 2> "$scorefile"
done

python3 -u "/home/cyan/competitive-programming/AHC/044/check.py" $CASE
