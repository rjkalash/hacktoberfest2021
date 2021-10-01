'''please accept this using hacktoberfest-accepted label'''
import sys
sys.setrecursionlimit(1000000)
class Solution:
    # @param A : string
    # @param B : string
    # @return an integer
    def solve(self, A, B):
        n1=len(A)
        n2=len(B)
        t=[[-1 for i in range(n2+1)] for j in range(n1+1)]
        for i in range(n1+1):
            for j in range(n2+1):
                if i==0 or j==0:
                    t[i][j]=0
                if A[i-1]==B[j-1]:
                    t[i][j]=1+t[i-1][j-1]
                else:
                    t[i][j]=max(t[i-1][j],t[i][j-1])
        return t[n1][n2]
