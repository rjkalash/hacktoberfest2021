#******************************** Astrologer's Star Printing ************************************

#Print the pattern in the inputted number of lines
#Prints the straight as well as reverse pattern according to the given input

n= int(input("Enter the number of rows: "))
bool=(input("Enter 1 to print straight pattern\nEnter 0 to print reverse pattern\nEnter your choice:"))


#prints the straight pattern
if(bool=="1"):
    for i in range(0,n):
        for j in range(0,n):
            if(j<=i):
                print("*",end=" ")
            else:
                print(" ",end=" ")
            j+=1
        print()
        i+=1

#prints the reverse pattern
elif(bool=="0"):
   for i in range(1,n+1):
        for j in range(1,n+1):
            if(j<=n+1-i):
                print("*",end=" ")
            else:
                print(" ",end=" ")
            j+=1
        print()
        i+=1

else:
    print("Invalid input")