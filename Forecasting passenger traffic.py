# question link : https://www.hackerrank.com/challenges/forecasting-passenger-traffic/submissions/code/232119079
# Enter your code here. Read input from STDIN. Print output to STDOUT
import pandas as pd
import numpy as np
from sklearn.linear_model import Ridge,LinearRegression
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsRegressor
from statsmodels.tsa.arima_model import ARIMA
from statsmodels.tsa.statespace.sarimax import SARIMAX
import warnings
warnings.filterwarnings('ignore')

def predicttraffic(m,cars):
    df = pd.DataFrame()
    n = []
    for i in range(0,m):
        n.append(i)
    
    df['num'] = n
    df['total'] = cars
    t = df['total'].str.split("\t",n = 1, expand = True)
    df['traff'] = t[1]
    
    df.set_index(df['num'],inplace=True)
    df.drop(columns=['num','total'],inplace=True)
    
    std = StandardScaler()
    df['traff'] = std.fit_transform(df[['traff']])


    model = SARIMAX(df['traff'],order=(1,1,2),seasonal_order=(0,0,0,12), trend = 'ct')
    model_fit = model.fit(disp=0)
    
    f = n[-1]+1
    z = []
    for i in range(12):
        z.append(f)
        f += 1
    return(std.inverse_transform(model_fit.predict(start = z[0],end=z[11])))

if __name__ == "__main__":
    m = int(input())

    cars = []
    for i in range(0,m):
        cars.append(input())
   
    pred = predicttraffic(m,cars)
    for i in pred:
        print(int(i))
    
