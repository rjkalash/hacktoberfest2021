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
    def cycleditact(self,s,visited,restack):
        visited[s]=True
        restack[s]=True
        for p in self.d[s]:
            if visited[p]==False:
                if self.cycleditact(p,visited,restack):
                    return True
            elif restack[p]==True:
                return True
        restack[s]=False
        return False
    def cycle(self):
        visited=[False for i in range(self.V+1)]
        restack=[False for i in range(self.V+1)]
        for i in range(self.V+1):
            if visited[i]==False:
                if self.cycleditact(i,visited,restack):
                    return True
        return False
class Solution:
    # @param A : integer
    # @param B : list of list of integers
    # @return an integer
    def solve(self, A, B):
        g=Graph(A)
        for p in B:
            g.addedge(p[0],p[1])
        return 1 if g.cycle() else 0
