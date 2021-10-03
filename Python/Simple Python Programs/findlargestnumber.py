# To find the largest number among the three numbers in Python


# First take 3 inputs for 3 numbers
num1 = float(input("Enter first number: "))
num2 = float(input("Enter second number: "))
num3 = float(input("Enter third number: "))
 
# then apply simple conditions
  
if (num1 > num2) and (num1 > num3):
   largest = num1
elif (num2 > num1) and (num2 > num3):
   largest = num2
else:
   largest = num3
 
# print the result

print("The largest number is",largest)
