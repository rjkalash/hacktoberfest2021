#a simple calculator built with python

while True:
   print("1. Addition")
   print("2. Subtraction")
   print("3. Multiplication")
   print("4. Division")
   print("5. Exit")
   print("Enter Your Choice (1-5): ", end="")
   ch = int(input())
   if ch>=1 and ch<=4:
      print("\nEnter Two Numbers: ", end="")
      numOne = float(input())
      numTwo = float(input())
   if ch==1:
      res = numOne + numTwo
      print("\nResult =", res)
   elif ch==2:
      res = numOne - numTwo
      print("\nResult =", res)
   elif ch==3:
      res = numOne * numTwo
      print("\nResult =", res)
   elif ch==4:
      res = numOne / numTwo
      print("\nResult =", res)
   elif ch==5:
      break
   else:
      print("\nInvalid Input!..Try Again!")
   print("------------------------")
