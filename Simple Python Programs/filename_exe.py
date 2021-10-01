#  write a python program to accept a filename from the user and print the extension of that

filename = input("Enter the filename:")
f_extns = filename.split(".")
print ("The extension of the file is:" + repr(f_extns[-1]))
