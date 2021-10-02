'''please accept this using hacktoberfest-accepted label'''
class Solution:
    # @param A : string
    # @param B : string
    # @return an integer
    def numDistinct(self, A, B):
        s1=A
        s2=B
        n1=len(s2)
        n2=len(s1)
        t=[[0 for i in range(n2+1)] for j in range(n1+1)]
        for i in range(n2+1):
            t[0][i]=1
        for i in range(1,n1+1):
            for j in range(1,n2+1):
                if s2[i-1]==s1[j-1]:
                    t[i][j]=t[i-1][j-1]+t[i][j-1]
                else:
                    t[i][j]=t[i][j-1]
        return t[n1][n2]
