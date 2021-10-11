import pandas as pd
import matplotlib.pyplot as plt
from datetime import date
def addNewBook():
    bookid = int(input("Enter a book id : "))
    title = input("Enter book title : ")
    author = input("Enter author of the book : ")
    publisher = input("Enter book publisher : ")
    edition = input("Enter edition of book : ")
    cost = int(input("Enter cost of the book : "))
    category = input("Enter category of book : ")
    bdf = pd.read_csv("books.csv")
    n = bdf["bookid"].count()
    bdf.at[n] = [bookid,title,author,publisher,edition,cost,category]
    bdf.to_csv("books.csv",index = False)
    print("Book added successfully")

def login():
    uname = input("Enter Username : ")
    pwd = input("Enter Password : ")
    df = pd.read_csv("users.csv")
    df = df.loc[df["username"] == uname]
    if df.empty:
        print("Invalid Username given")
        return False
    else:
        df = df.loc[df["password"] == pwd]
        if df.empty:
            print("Invalid Password")
            return False
        else:
            print("Username and Password matched successfully")
            return True

def searchBook():
    name = input("Enter book title to be searched : ")
    bdf = pd.read_csv("books.csv")
    df = bdf.loc[bdf["title"] == name]
    if df.empty:
        print("No book found with given title")
        return False
    else:
        print("Book details are ")
        print(df)
        return True

def deleteBook():
    name = input("Enter book title to be deleted : ")
    bdf = pd.read_csv("books.csv")
    bdf = bdf.drop(bdf[bdf["title"] == name].index)
    bdf.to_csv("books.csv",index = False)
    print("Book Deleted Successfully")

def showBooks():
    bdf = pd.read_csv("books.csv")
    print(bdf)


def addNewMember():
    mid = int(input("Enter Member id : "))
    name = input("Enter name of the member : ")
    phone = input("Enter phone number : ")
    email = input("Enter email id : ")
    address = input("Enter address : ")
    number = 0
    mdf = pd.read_csv("members.csv")
    n = mdf["Memberid"].count()
    mdf.at[n] = [mid, name, phone, email, address]
    mdf.to_csv("members.csv", index=False)
    print("Member added successfully")


def searchMember():
    name = input("Enter member name to be searched : ")
    mdf = pd.read_csv("members.csv")
    df = mdf.loc[mdf["name"] == name]
    if df.empty:
        print("No member found with given name")
        return False
    else:
        print("Member details are ")
        print(df)
        return True


def deleteMember():
    name = input("Enter member name to be deleted : ")
    mdf = pd.read_csv("members.csv")
    mdf = mdf.drop(mdf[mdf["name"] == name].index)
    mdf.to_csv("members.csv", index=False)
    print("Member Deleted Successfully")

def showMembers():
    mdf = pd.read_csv("members.csv")
    print(mdf)


def issueBook():
    bname = input("Enter Book name to be searched : ")
    df = pd.read_csv("books.csv")
    df = df.loc[df["title"] == bname]
    if df.empty:
        print("No Book Found in the Library")
        return

    mname = input("Enter member name to be searched : ")
    df = pd.read_csv("members.csv")
    df = df.loc[df["Name"] == mname]
    if df.empty:
        print("No such Member Found")
        return

    idf = pd.read_csv("issuedbooks.csv")
    book_issue = [bname,mname,date.today(),""]
    n = idf["book_name"].count()
    idf.at[n] = book_issue
    idf.to_csv("issuedbooks.csv",index = False)
    print("Book Issued Successfully")
    df = pd.read_csv("members.csv")


def showIssuedBooks():
    idf = pd.read_csv("issuedbooks.csv")
    print(idf)
def returnBook():
    bname = input("Enter Book to be returned : ")
    mname = input("Enter Member who has the book : ")
    idf = pd.read_csv("issuedbooks.csv")
    idf = idf.loc[idf["book_name"] == bname]
    if idf.empty:
        print("The book is not issued in records")
    else:
        idf = idf.loc[idf["member_name"] == mname]
        if idf.empty:
            print("The book is not issued to the member")
        else:
            print("Book can be returned")
            ans = input("Are you sure you want to return the book : ")
            if ans.lower() == "yes":
                idf = pd.read_csv("issuedbooks.csv")
                idf = idf.drop(idf[idf["book_name"] == bname].index)
                idf.to_csv("issuedbooks.csv", index=False)
                print("Book Returned Successfully")
            else:
                print("Return operation cancelled")

def showchart():
    print("Press 1 - Books and their Cost")
    print("Press 2 for seeing edition of books in the form of line chart")
    ch = int(input("Enter your choice : "))
    if ch == 1:
        bdf = pd.read_csv("books.csv")
        plt.bar(bdf["bookid"],bdf["cost"],label="cost vs books")
        plt.xlabel("title")
        plt.ylabel("cost")
        plt.legend(loc="upper right")
        plt.show()
    if ch==2:
        bdf = pd.read_csv("books.csv")
        plt.plot(bdf["bookid"],bdf["edition"],'g',marker='d',markersize=5,markeredgecolor='red')
        plt.xlabel("bookid")
        plt.ylabel("edition")
        plt.title("Edition /year in which the book was published")
        plt.show()
            
def showMenu():
    print("-----------------------------")
    print("       ABC LIBRARY MGT       ")
    print("-----------------------------")
    print("Press 1 - Add a New Book")
    print("Press 2 - Search for a Book")
    print("Press 3 - Delete a Book")
    print("Press 4 - Show All Books")
    print("Press 5 - Add a New Member")
    print("Press 6 - Search for a Member")
    print("Press 7 - Delete a Member")
    print("Press 8 - Show All Members")
    print("Press 9 - Issue a Book")
    print("Press 10 - Return a Book")
    print("Press 11 - Show All Issued Books")
    print("Press 12 - To view Charts")
    print("Press 13 - To Exit")
    choice = int(input("Enter your choice : "))
    return choice

if login():
    while True:
        ch = showMenu()
        if ch == 1:
            addNewBook()
        elif ch == 2:
            searchBook()
        elif ch == 3:
            deleteBook()
        elif ch == 4:
            showBooks()
        elif ch == 5:
            addNewMember()
        elif ch == 6:
            searchMember()
        elif ch == 7:
            deleteMember()
        elif ch == 8:
            showMembers()
        elif ch == 9:
            issueBook()
        elif ch == 10:
            returnBook()
        elif ch == 11:
            showIssuedBooks()
        elif ch == 12:
            showchart()
        elif ch == 13:
            print("THANK YOU !!HOPE THIS PROJECT OVERWHELMED YOU")
            print("I HOPE FOE THE BEST")
            break
        else:
            print("Invalid Option Selected")
