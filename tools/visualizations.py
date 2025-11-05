import matplotlib.pyplot as plt
import pandas as pd
import json
import re
from pathlib import Path


json_pathname = Path('build/benchmarks/is_space_bench.json')
out_directory = Path('tools/report')
out_directory.mkdir(parents=True, exist_ok=True)

if not json_pathname.exists():
  raise RuntimeError(f'Missing the benchmark {json_pathname.name} .json file')

with open(json_pathname, 'r') as f:
  data = json.load(f)

rows = data.get('benchmarks', [])

df = pd.json_normalize(rows)


name_re = re.compile(r"BM_is_space_(find|traits)<([^>]+)>(?:/(\d+))?")
df = df[df["name"].str.match(name_re)]

parsed = df["name"].str.extract(r"BM_is_space_(find|traits)<([^>]+)>(?:/(\d+))?")
parsed.columns = ["impl", "type", "size"]
df = pd.concat([df, parsed], axis=1)
df["size"] = pd.to_numeric(df["size"], errors="coerce")


df = df[df["aggregate_name"].isin(["mean", "median"]) | df["aggregate_name"].isna()]


idx = df.groupby(["type", "impl"])["size"].idxmax()
reduced = df.loc[idx].copy()

pivot = reduced.pivot(index="type", columns="impl", values="bytes_per_second").sort_index()
pivot["speedup_traits_over_find"] = pivot["traits"] / pivot["find"]


csv_path = out_directory / "is_space_summary.csv"
pivot.to_csv(csv_path)


# plot
ax = pivot[["find", "traits"]].plot(kind="bar", figsize=(9, 4))
ax.set_ylabel("Throughput (bytes/s) – higher is better")
ax.set_title("is_space: std::find vs char_traits::find (largest size per type)")
ax.legend(title="impl")
plt.tight_layout()
png_path = out_directory / "is_space_chart.png"
plt.savefig(png_path, dpi=160)
plt.close()


# print summary
print(pivot.to_string(float_format=lambda x: f"{x:,.0f}"))
print(f"\nWrote {csv_path}")
print(f"Wrote {png_path}")