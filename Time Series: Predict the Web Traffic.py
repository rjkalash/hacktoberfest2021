# question link: https://www.hackerrank.com/challenges/time-series-prediction/problem


# Enter your code here. Read input from STDIN. Print output to STDOUT
import pandas as pd
import numpy as np

n = int(input())

df = []

for i in range(n):
    df.append(int(input()))


for i in range(30):
    df.append(np.nan)

df = pd.DataFrame(list(df), columns = ['Values'])


df = df.interpolate(method = 'cubic', limit_direction = 'backward')



for i in range(n,n+30):

    print(df.iloc[i,0])
