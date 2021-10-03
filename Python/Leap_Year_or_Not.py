year = int(input())

if year%4 == 0 and year%100 !=0:
    print("Leap year")
elif year%400 == 0:
    print("Leap year")
else:
    print("Not leap year")
    
