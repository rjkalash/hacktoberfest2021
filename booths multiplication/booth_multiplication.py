 ## MAIN
 def booths_algorithm():
 #Gets Multiplicand
 multiplicand_dec = getInput("Mutiplicand")
 #Gets Multiplier
 multiplier_dec = getInput("Multiplier")
 #Converts Multiplicand
 multiplicand_bin = convertDec(multiplicand_dec)
 #Converts Multiplier
 multiplier_bin = convertDec(multiplier_dec)
 #Perform Booth's algorithm
 boothsTriumph(multiplicand_bin,multiplier_bin)
 print("\nDecimal Result: " +
 str(int(multiplier_dec)*int(multiplicand_dec)))
## Parent function for logical process
def boothsTriumph(mcand, plier):
#Create full product line for Booth's Algorithm
print("\n\n---------[  multipcand: " + mcand + " multiplier: " +
plier+"  ]----------\n\n")
product = "00000000" + plier + "0"
print("Product: " + product+"\n")
#Display product line to user
print(buildLine(0,mcand,product))
#Iterate through Booth's Algorithm
for i in range(1,9):
operation = product[len(product)-2:]
product = perform_operation(product,mcand,operation)
  print(buildLine(i,mcand,product))
 #Print out final value in binary and decimal
 product = shift(product)
 product = product[9:17]
 print("\nProduct: " + product)
 return
 ## Perform the necessary algorithmic operation
 def perform_operation(product,mcand,operation):
 if operation == "00":
 product = shift(product)
 print("No Operation\n")
 return product
 elif operation == "01":
 ##Product = Product + mcand
 temp = binAdd(product[0:8],mcand)
 product = temp + product[8:]
 product = shift(product)
 print("Add B\n")
 return product
 elif operation == "10":
 ##Product = Product - mcand
 product = subtraction(product,mcand)
 product = shift(product)
 print("Add b*+1\n")
 return product
 elif operation == "11":
 else:
product = shift(product)
 print("No Op")
return product
  print("An error has occured when choosing operation: Exiting
 program")
 return 0
 ## Performs Subtraction operation
 def subtraction(product,mcand):
 carry = 0
 prime_product = product[:8]

  final_product = ""
 for i in range(len(prime_product)-1,-1,-1):
 if (mcand[i] == "0" and prime_product[i] == "0"):
 if (carry == 1):
 else:
final_product = "1" + final_product
  final_product = "0" + final_product
 elif (mcand[i] == "1" and prime_product[i] == "0"):
 if (carry == 1):
 final_product = "0" + final_product
 else:
 final_product = "1" + final_product
 carry = 1
 elif (mcand[i] == "0" and prime_product[i] == "1"):
 if (carry == 1):
 else:
final_product = "0" + final_product
 carry = 0
  final_product = "1" + final_product
 elif (mcand[i] == "1" and prime_product[i] == "1"):
 if (carry == 1):
 final_product = "1" + final_product
 #Again, not sure if this is what really happens to carry
 carry = 1
 else:
 final_product = "0" + final_product
 else:
 print("An error has occurred when subtracting: Exiting
 program")
 return 0
 return final_product + product[8:]
 ## Shifts in left
 def shift(product):
 product = "0"+product[:len(product)-1]

  return product
 ##Adds the two binary strings
 def binAdd(num, num2):
 product = ""
 carry = "0"
 for i in range(len(num)-1,-1,-1):
 if carry == "0":
 if num[i] == "0" and num2[i] == "0":
 product = "0" + product
 elif num[i] == "1" and num2[i] == "1": #case 1 and 1
 product = "0" + product
 carry = "1"
 else:
 product = "1" + product
 elif carry == "1":
 if num[i] == "0" and num2[i] == "0":
 product = "1" + product
 carry = "0"
 elif num[i] == "1" and num2[i] == "1": #case 1 and 1
 product = "1" + product
 carry = "1"
 else:
 product = "0" + product
 carry = "1"
 return product
 ## Shows step-by-step process
 def buildLine(iteration, mcand, product):
 line = "Step: " + str(iteration) + " | Multiplicand: " + mcand + " |
 Product: " \
 + product[0:8] + " | " + product[8:16] + " | " + product[16]
 return line
 ## Formats numbers from decimal to binary
 def convertDec(dec):
 # If the value is negative, calls twos_complement
 if int(dec)<0:

  bin = twos_complement(int(dec))
 # Else simply converts to binary
 else:
 bin = "{0:b}".format(int(dec))
 # Iterates through and makes the binary value 8
 for i in range(8-len(bin)):
 bin = "0" + bin
 return bin
 ## Gets input for for algorithm
 def getInput(varName):
 #Request input
 boothIn = input('Please enter your ' + varName + ": ")
 #Parse input
 while int(boothIn)>127 or int(boothIn)<-128:
 print("Absolute value too big, please try again")
 boothIn = input('Please enter your ' + varName + ": ")
 return boothIn
 ## Converts negative numbers
 def twos_complement(dec):
 #Convert to dec, adding 1, then removing negative
 adjusted = abs(int(dec) + 1)
 #Turns into binary number
 binint = "{0:b}".format(adjusted)
 #Flip bits
 flipped = flip(binint)
 # Iterates through and makes the binary value 8
 for i in range(8-len(flipped)):
 flipped = "1" + flipped
 return flipped

 ## Flips the bits into a string
 def flip(string):
 flipped_string = ""
 for bit in string:
    if bit == "1":
 flipped_string += "0"
 else:
 
return flipped_string
Output for Booth’s Multiplication : 1. Multiply 20 X -5 :

## CALL MAIN
flipped_string += "1"
  booths_multiplication()