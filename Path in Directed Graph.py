'''please accept this using hacktoberfest-accepted label'''

import sys
sys.setrecursionlimit(1000000)
from collections import defaultdict
class Graph:
    def __init__(self,v):
        self.V=v
        self.d=defaultdict(list)

    def addedge(self,u,v):
        self.d[u].append(v)

    def dfs(self,visited,start,end):
        visited[start]=True
        if start==end:
            return True
        for p in self.d[start]:
            if not visited[p]:
                if self.dfs(visited,p,end):
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
        visited=[False for i in range(A+1)]
        return 1 if g.dfs(visited,1,A) else 0
