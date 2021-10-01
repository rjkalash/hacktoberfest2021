'''please accept this using hacktoberfest-accepted label'''
class Solution:
    # @param A : string
    # @return an integer
    def anytwo(self, A):
        s1=A
        s2=A
        n1=len(s1)
        n2=len(s2)
        t=[[0 for i in range(n2+1)] for j in range(n1+1)]
        for i in range(1,n1+1):
            for j in range(1,n2+1):
                if s1[i-1]==s2[j-1] and i!=j:
                    t[i][j]=1+t[i-1][j-1]
                else:
                    t[i][j]=max(t[i-1][j],t[i][j-1])
        if t[n1][n2]>=2:
            return 1
        else:
            return 0
