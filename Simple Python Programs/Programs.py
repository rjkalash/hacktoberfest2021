while True:
      str1 = input("Enter a string: ")
      n = len(str1)
      print()
      print("Main Menu")
      print("-----------------------------------------")
      print("1. Reverse string")
      print("2. Alternate characters caps and small")
      print("3. Find the repeating characters in the string")
      print("4. Encode the string by adding 2 to each ASCII value")
      print("----------------------------------------")
      print()

      opt = int(input("Enter your option: "))
      
      if opt == 1:
            for i in range(-1,-n-1,-1):
                  print(str1[i],end="")
            print()
            print()     
      if opt == 2:
            str2 = ""
            for i in range(n):
                  if i % 2 ==0:
                        str2 = str2 + str1[i].upper()
                  else:
                        str2 = str2 + str1[i].lower()
            print(str2)
            print()
      if opt == 3:
            for i in range(n):
                  ctr = 1
                  for j in range(i+1,n):
                        if str1[i] == str1[j]:
                              ctr = ctr + 1
                              str1 = str1[:j] + ' ' + str1[j+1:]
                              
                  if ctr>1 and str1[i] != ' ':
                        print(str1[i], end=" ")
            print()
      if opt == 4:
            str2 = ""
            for i in range(n):
                  asc = chr(ord(str1[i]) + 2)
                  str2 = str2 + asc
            print(str2)
            print()
            
      
                        
            

      
