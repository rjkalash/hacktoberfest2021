# question link: https://www.hackerrank.com/challenges/missing-stock-prices/problem

# Enter your code here. Read input from STDIN. Print output to STDOUT
import numpy as np
import pandas as pd
from scipy import interpolate

m = int(input())
n = []
data = []
for i in range(0,m):
    data.append(input())
for i in range(0,m):
    n.append(i)
df = pd.DataFrame()
df['num'] = n
df['d'] = data

t = df['d'].str.split("\t",n = 1, expand = True)
df['d_new'] = t[1]

df.d_new = pd.to_numeric(df.d_new,errors='coerce')
d_miss = df.d_new.isna()
d_interp = df.d_new.interpolate(method='cubic')

for i in range(df.shape[0]):
    if d_miss[i]:
        print(round(d_interp[i],2))
