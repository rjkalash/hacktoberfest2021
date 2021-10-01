'''please accept this using hacktoberfest-accepted label'''


import sys
sys.setrecursionlimit(1000000)
from collections import defaultdict
class Graph:
    def __init__(self,v):
        self.d=defaultdict(list)
        self.V=v
    def addedge(self,u,v):
        self.d[u].append(v)
    def dfsut(self,s,count,visited):
        global maxcount,x
        visited[s]=True
        count+=1
        for p in self.d[s]:
            if visited[p]==False:
                if count>maxcount:
                    maxcount=count
                    x=p
                self.dfsut(p,count,visited)

    def dia(self,node):
        visited=[False for i in range(self.V+1)]
        count=0
        self.dfsut(node,count,visited)

    def solve(self):
        global x,maxcount
        self.dia(1)
        self.dia(x)
        return maxcount
class Solution:
    # @param A : list of integers
    # @return an integer
    def solve(self, A):
        g=Graph(len(A))
        global maxcount
        maxcount=0
        global x
        x=0
        for i in range(len(A)):
            if A[i]!=-1:
                g.addedge(A[i],i)
                g.addedge(i,A[i])
        return g.solve()
