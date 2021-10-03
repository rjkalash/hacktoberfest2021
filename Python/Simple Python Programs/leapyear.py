#To see if a year is leap year or not.
print("Enter the Year: ")
y = int(input())

if y%4==0 and y%100!=0:
    print("\nIt is a Leap Year")
elif y%400==0:
    print("\nIt is a Leap Year")
else:
    print("\nIt is not a Leap Year")
