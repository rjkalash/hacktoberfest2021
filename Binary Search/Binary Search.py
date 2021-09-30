while True:
      l1 =[]
      a = int(input("How many no's do you wish to enter: "))
      for i in range(a):
            b = int(input("Enter a number: "))
            l1.append(b)
      l1.sort()
      print(l1)
      n = len(l1)
      
      print()
      
      print("Main Menu")
      print("-----------")
      print("1.Binary search(normal function)")
      print("2. Binary search(recursive funtion)")
      print("-----------")
      print()
      opt = int(input("Enter your option: "))
      if opt == 1:
            def binary(l1,val):
                  start,end,pos = 0,n-1,'x'
                  while end >= start:
                        mid = (start+end)//2
                        if l1[mid] == val:
                              pos = mid
                              return True,pos
                        elif val < l1[mid]:
                              end = mid - 1
                        else:
                              start = mid + 1
                  return False,pos
            pos=0
            val = int(input("Enter value to be searched: "))
            flag,pos = binary(l1,val)
            if flag == True:
                  print("Element found at",pos+1,"position")
            else:
                  print("Element not found")
      print()
      if opt == 2:
            def binary1(l1,start,end,val):
                  if end >= start:
                        mid = (start+end)//2
                        if l1[mid] == val:
                              return mid
                        elif val < l1[mid]:
                              return binary1(l1,mid-1,start,val)
                        else:
                              return binary1(l1,end,start+1,val)
                  else:
                        return -1
            start,end = 0,n-1
            val = int(input("Enter value to be searched: "))
            pos = binary1(l1,start,end,val)
            if pos != -1:
                  print("Value found at",pos+1,"position")
            else:
                  print("Value not found")
      print()
      
