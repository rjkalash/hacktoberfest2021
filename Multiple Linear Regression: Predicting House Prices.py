# question link : https://www.hackerrank.com/challenges/predicting-house-prices/problem

# Enter your code here. Read input from STDIN. Print output to STDOUT
# Enter your code here. Read input from STDIN. Print output to STDOUT
import numpy as np
import pandas as pd
from sklearn.linear_model import LinearRegression
from sklearn.ensemble import RandomForestRegressor


n = input()
F = int(n.split()[0])
N = int(n.split()[1])

model = LinearRegression()


X = []
y = []
for i in range(N):
    data = [float(N) for N in input().split()]
    X.append(data[0: len(data) - 1])
    y.append(data[len(data) - 1])    
model.fit(X,y)


if __name__ =='__main__':
     
    N = int(input())
    x_test = []
    for i in range(N):
        data_test = [float(N) for N in input().split()]
        x_test.append(data_test)

    pred = model.predict(x_test)
    for i in pred:
        print(round(i,2))
