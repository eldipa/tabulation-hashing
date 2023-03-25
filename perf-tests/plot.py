import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

import sys

fname, = sys.argv[1:]

df = pd.read_csv(fname)

# Evolution of 32-32 full in 32k cache (little use)
df2 = df[(df.table == '32-32') & (df.cache_sz == 32768) & (df.himpl == 'f') & (df.cache_asso==0)]
fig,  (ax1, ax2) = plt.subplots(1, 2, subplot_kw=dict(yscale='log'))
sns.scatterplot(data=df2, x=df2.order, y=df2.D1mr, ax=ax1)
sns.scatterplot(data=df2, x=df2.order, y=df2.D1mw, ax=ax2)
fig.tight_layout()


# 32-32 vs 64-64 full in 32k cache
df2 = df[(df.cache_sz == 32768) & (df.himpl == 'f') & (df.cache_asso==0)]
fig,  (ax1, ax2) = plt.subplots(1, 2, subplot_kw=dict(yscale='log'))
sns.scatterplot(data=df2, x=df2.order, hue=df2.table, y=df2.D1mr, ax=ax1)
sns.scatterplot(data=df2, x=df2.order, hue=df2.table, y=df2.D1mw, ax=ax2)
fig.tight_layout()


# f vs b 64-64 in 32k cache
df2 = df[(df.table == '64-64') & (df.cache_sz == 32768) & (df.cache_asso==0)]
fig,  (ax1, ax2) = plt.subplots(1, 2, subplot_kw=dict(yscale='log'))
sns.scatterplot(data=df2, x=df2.order, hue=df2.himpl, y=df2.D1mr, ax=ax1)
sns.scatterplot(data=df2, x=df2.order, hue=df2.himpl, y=df2.D1mw, ax=ax2)
fig.tight_layout()


# f vs b 64-64 in 16k cache (with batch len of 1)
df2 = df[(df.table == '64-64') & (df.cache_sz == 16384) & (df.blen == 1) & (df.cache_asso==0)]
fig,  (ax1, ax2) = plt.subplots(1, 2, subplot_kw=dict(yscale='log'))
sns.scatterplot(data=df2, x=df2.order, hue=df2.himpl, y=df2.D1mr, ax=ax1)
sns.scatterplot(data=df2, x=df2.order, hue=df2.himpl, y=df2.D1mw, ax=ax2)
fig.tight_layout()


# batch length for 64-64 in 16k cache (hard to read)
df2 = df[(df.table == '64-64') & (df.cache_sz == 16384) & (df.himpl == 'b') & (df.cache_asso==0)]
fig,  (ax1, ax2) = plt.subplots(1, 2, subplot_kw=dict(yscale='log'))
sns.scatterplot(data=df2, x=df2.order, hue=df2.blen.astype("category"), y=df2.D1mr, ax=ax1)
sns.scatterplot(data=df2, x=df2.order, hue=df2.blen.astype("category"), y=df2.D1mw, ax=ax2)
fig.tight_layout()

# batch length for 64-64 in 16k cache; order 22; blen < 64; compare with f
df2 = df[(df.table == '64-64') & (df.cache_sz == 16384) & (df.order == 22) & (df.cache_asso==0) & (df.blen < 60)]
fig,  (ax1, ax2) = plt.subplots(1, 2)
sns.scatterplot(data=df2, x=df2.blen, y=df2.D1mr, hue=df2.himpl, ax=ax1)
sns.scatterplot(data=df2, x=df2.blen, y=df2.D1mw, hue=df2.himpl, ax=ax2)
fig.tight_layout()


# batch length for 64-64 in 16k cache; order 22; blen < 64; compare with asso and himpl
df2 = df[(df.table == '64-64') & (df.cache_sz == 16384) & (df.order == 22) & (df.blen < 60)]
fig,  (ax1, ax2) = plt.subplots(1, 2)
sns.scatterplot(data=df2, x=df2.blen, y=df2.D1mr, hue=df2[['cache_asso', 'himpl']].apply(tuple, axis=1), ax=ax1)
sns.scatterplot(data=df2, x=df2.blen, y=df2.D1mw, hue=df2[['cache_asso', 'himpl']].apply(tuple, axis=1), ax=ax2)
fig.tight_layout()

