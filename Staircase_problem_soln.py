def countWays(n, m):
     
    temp = 0
    res = [1]
     
    for i in range(1, n + 1):
        s = i - m - 1
        e = i - 1
        if (s >= 0):
            temp -= res[s]
        temp += res[e]
        res.append(temp)
         
    return res[n]
 
n=int(input())
m=int(input())

print('Number of ways to climb the stairs are:',countWays(n,m))
