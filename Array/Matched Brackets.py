n = int(input())
a = list(map(int,input().split()))
count = 0
maxD=0
maxIndex=0
longSeq=0
longIndex=0
depth=0
depthIdx=0
for i in range(n):
    depth+=1
    if a[i]==1:
        if count==0:
            depthIdx=i
        count+=1
    else:
        count-=1
    if count>maxD:
            maxD=count
            maxIndex=i+1
    if count==0:
        if depth > longSeq:
            longSeq = depth
            longIndex = depthIdx+1
        depth=depthIdx=0
print(maxD,maxIndex,longSeq,longIndex)