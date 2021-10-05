#Monte Carlo integration - a method used to approximate a definite integral using random point generation
# We will see two problems :-
#1) Approximate the value of the number pi by generating samples of size 100, 1000 and 10000. 
#2) Approximate the integral 1/(1+x^2) from limits 0 to 1 by generating samples of size 100, 1000 and 10000.
#Complexity of problems is pretty much high O(10000^2) so it will take time to compute . Have patience till then.
import numpy as np
import math
#1
def Q1():
 s = [100,1000,10000] 
 for i in range(len(s)):
  x = np.random.uniform(-1,1 ,s[i] )
  y = np.random.uniform(-1,1,s[i] )

  x = [round(val, 3) for val in x]
  y = [round(val, 3) for val in y]
  cnt =0
  for j in x:
     for k in y:
         if (j**2+k**2<=1):
             cnt=cnt+1
  print( 'Value of pie for size =',s[i],'is',4*cnt/(s[i]*s[i]))

#2
def Q2():
 s = [100,1000,10000] 
 for i in range(len(s)):
  x = np.random.uniform(0,1 ,s[i] )
  y = np.random.uniform(0,2,s[i] )
 #print(x)
  x = [round(i, 3) for i in x]
  y = [round(i, 3) for i in y]
  cnt =0
  for j in x:
     for k in y:
         if (k-2/(1+j*j)<=0):
             cnt=cnt+1
  print('Value of integral for size =',s[i],'is',2*cnt/(s[i]*s[i]))

Q1()
print("--------------------------------------------------------------------------------------------------------------------------------------------")
Q2()
