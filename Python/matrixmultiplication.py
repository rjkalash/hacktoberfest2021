X = [[22, 62, 32],
    [23, 27, 31],
    [11, 16, 69]]
    
Y = [[41, 22, 66],
    [1, 55, 54],
    [78, 2, 3]]
     
A = [[0, 0, 0],
    [0, 0, 0],
    [0, 0, 0]]
 

for i in range(len(X)):
 
    for j in range(len(Y[0])):
 
        for k in range(len(Y)):
            A[i][j] += X[i][k] * Y[k][j]
 
for l in A:
    print(l)
