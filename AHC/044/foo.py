import os
import sys

# スコアフォルダのパス
SCORE_DIR = "./AHC/043/score/full"

# フォルダ一覧を取得し、ディレクトリのみを抽出
folders = sorted([
    f for f in os.listdir(SCORE_DIR)
    if os.path.isdir(os.path.join(SCORE_DIR, f))
])

# 比較のために最低2つのフォルダが必要
if len(folders) < 2:
    print("比較対象が足りません。2つ以上のスコアフォルダを作成してください。")
    sys.exit(1)

# 最新とその一つ前のフォルダ
latest_folder = os.path.join(SCORE_DIR, folders[-1])
prev_folder = os.path.join(SCORE_DIR, folders[-2])

# スコアを読み込む関数
def load_scores(folder):
    scores = {}
    for file in sorted(os.listdir(folder)):
        path = os.path.join(folder, file)
        if os.path.isfile(path) and file.endswith(".txt"):  # ファイルのみ処理
            with open(path, "r") as f:
                try:
                    scores[file] = float(f.read().strip())  # スコアを数値として取得
                except ValueError:
                    continue  # 読み取れない場合はスキップ
    return scores

# それぞれのフォルダからスコアを取得
latest_scores = load_scores(latest_folder)
prev_scores = load_scores(prev_folder)

# 改善したスコアのファイル名を表示
print("\n■ 改善したスコア一覧")
enhanced = [
    f"{file}: {prev_scores[file]} → {latest_scores[file]} ({(latest_scores[file] - prev_scores[file]) / prev_scores[file]})"
    for file in latest_scores
    if file in prev_scores and latest_scores[file] > prev_scores[file]
]
li = [
    (latest_scores[file]-prev_scores[file])/prev_scores[file]
    for file in latest_scores
    if file in prev_scores and latest_scores[file] > prev_scores[file]
]
print(len(li))
# print(sum(li)/len(li))
# print(max(li))

# if enhanced:
#     print("\n".join(enhanced))
# else:
#     print("スコアが改善したファイルはありません。")

# 悪化したスコアのファイル名を表示
print("\n■ 悪化したスコア一覧")
worsened = [
    f"{file}: {prev_scores[file]} → {latest_scores[file]} ({(latest_scores[file] - prev_scores[file]) / prev_scores[file]})"
    for file in latest_scores
    if file in prev_scores and latest_scores[file] < prev_scores[file]
]
li = [
    (latest_scores[file]-prev_scores[file])/prev_scores[file]
    for file in latest_scores
    if file in prev_scores and latest_scores[file] < prev_scores[file]
]
print(len(li))
# print(sum(li)/len(li))
# print(min(li))

# if worsened:
#     print("\n".join(worsened))
# else:
#     print("スコアが悪化したファイルはありません。")

# 変化率の計算
change_rates = []
for file in latest_scores:
    if file in prev_scores and prev_scores[file] != 0:  # 0除算防止
        change_rate = (latest_scores[file] - prev_scores[file]) / prev_scores[file] * 100
        change_rates.append(change_rate)

# 変化率の平均を計算
average_change_rate = sum(change_rates) / len(change_rates) if change_rates else 0.0

# 平均変化率の表示
print("\n■ 平均スコア変化率")
print(f"{average_change_rate:.2f} %")

if average_change_rate > 0:
    print("🟢 スコアが平均的に向上！")
elif average_change_rate < 0:
    print("🔴 スコアが平均的に低下…")
else:
    print("⚪ ほぼ変化なし。")
