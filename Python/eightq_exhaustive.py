"""
Author : Divya Ganesh
04 October 2021
Hacktoberfest 2021
Cummins College of Engineering for Women Pune
"""
import numpy as np

def disp(board):
	#prints the possible board configurations in a readable form 
	print("__|A|B|C|D|E|F|G|H|")
	for i in range (0,8):
		print(i+1, end=" |")
		for j in range (0,8):
			if (board[i][j]==0):
				print("-|", end="")
			else :
				print("Q|", end="")
		print("")
	print("")

def diacheck(p, q, board):
	#checks all the four diagonal directions for already present queens
	if (p>=0 and q>=0 and p<=7 and q<=7):			
			if (board[p][q]==1):
				return True
	return False
def check(x,y, board):
	#checks if the square under consideration is under attack
	#by any already placed queens
	#Check returns TRUE if square is *NOT* under attack
	flag=False
	#flag stores the value TRUE if the square *IS* under attack
	#I realize this is confusing but I'm too lazy to change it so suffer <3 :)
	
    #this loop checks for queens in vertical and horizontal ranges
	for i in range (0,8):
		if (board[x][i]==1):
			flag=True
			break
		if (board[i][y]==1):
			flag=True
			break
	if flag:
		return False

	#This one checks for queens in all the diagonal directions	
	for i in range (1,8):
		flag = diacheck(x-i,y-i,board)	
		if (flag==False):
			flag = diacheck(x-i,y+i,board)
			if (flag==False):
				flag = diacheck(x+i,y-i,board)
				if (flag==False):
					flag = diacheck(x+i,y+i,board)
		if flag:
			return False		

	else :
		return True

#this is a beautiful recursive function that took me waay too long to figure out
#i hope you need longer <3 :)
def row(i, board, flag):
	#this section just makes sure that none of the configs are repeated 
	if i>7:
		for b in boards: 
			if (np.array_equal(b, board)):
				return 0
		return 1
	#this is the main code that generates configs
	for j in range (0,8):
		if check(i, j, board):	
			board[i][j]=1		
			flag=row(i+1, board, flag)
			if (flag==0):
				board[i][j]=0
	return flag	


#stores all the generated configs for the boards
boards=[]
#counts the number of iterations of the while loop 
i=1

while(True):
	board = np.zeros(shape=(8,8), dtype=int)
	row(0,board,0)
	if (np.sum(board)==0):
		break
	print (i)
	disp(board)
	boards.append(board)
	i+=1
#loop terminates when array with no queen, that is full of only zeros is returned
print("No more possible solutions\nExiting\nTotal Solutions:", i-1)