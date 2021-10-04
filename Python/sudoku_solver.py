import numpy as np
import time
import re  

sudoku=[]

def block_check(x, y, n, sudoku):
	check = [[3,3], [3,6], [3,9], [6,3], [6,6], [6,9], [9,3], [9,6], [9,9]]
	b=[]
	for i in check:
		if (x in range (i[0]-3, i[0]) and y in range (i[1]-3, i[1])):
			b=sudoku[(i[0]-3): i[0] , (i[1]-3): i[1]]
			break
	b=np.reshape(b, (1,9))
	b=b[0]
	if n in b:
		return(False)
	return(True)


#x and y indicate position and  
#n indicates number proposed at that position
def check(x,y,n,sudoku):
	flag = True				#flag is false if number cannot be placed
	
	#checking rows and columns
	for i in range(0,9):
		if(sudoku[i][y]==n or sudoku[x][i]==n):
			flag = False
			break
	if (not flag):
		return flag

	#checking blocks
	flag=block_check(x,y,n,sudoku)
	return flag


def list_input():
	global sudoku
	print("Enter sudoku row wise. Use 0 to indicate a cell not already filled\n")			#empty list will store integer values 9*9
	for i in range (0,9):
		l = np.array(list(re.sub(r"[^0-9]","",input())))
		#l = np.array(input().split(" "))
		l = l.astype(int)
		sudoku.append(list(l))

def solve(x, y, sudoku, flag):

	if (sudoku[x][y]==0):
		for i in range (1,10):
			if(check(x,y,i,sudoku)):
				sudoku[x][y]=i
				if (x==8 and y==8):
					return 1
				if (y==8):
					flag=solve(x+1,0,sudoku,0)
				else:
					flag=solve(x,y+1,sudoku,0)
				if (flag==0):
					sudoku[x][y]=0
					continue
				if(sudoku[x][y]!=0):
					flag=1
					break
		
	elif (x==8 and y==8):
		return 1
	else:
		if (y==8):
			flag=solve(x+1,0,sudoku,0)
		else:
			flag=solve(x,y+1,sudoku,0)	
	return flag 		




'''
copy paste this with input prompt to test
sudoku=[[2, 0, 0, 0, 0, 0, 9, 5, 1],
		[0, 0, 0, 0, 0, 0, 0, 0, 7],
		[8, 7, 6, 0, 0, 5, 2, 0, 0],
		[3, 0, 4, 0, 2, 8, 0, 0, 0], 
		[0, 0, 0, 0, 0, 0, 5, 0, 9],
		[0, 0, 5, 0, 0, 1, 3, 0, 4],
		[0, 2, 0, 0, 8, 4, 0, 1, 0],
		[0, 0, 0, 0, 1, 0, 0, 9, 8],
		[0, 0, 0, 0, 0, 0, 0, 0, 0]]
sudoku=np.array(sudoku)
#^sample
soln  =[[2, 4, 3, 8, 7, 6, 9, 5, 1],
		[9, 5, 1, 2, 4, 3, 8, 6, 7],
		[8, 7, 6, 1, 9, 5, 2, 4, 3],
		[3, 9, 4, 5, 2, 8, 1, 7, 6],
		[1, 6, 2, 4, 3, 7, 5, 8, 9],
		[7, 8, 5, 9, 6, 1, 3, 2, 4],
		[6, 2, 9, 3, 8, 4, 7, 1, 5],
		[5, 3, 7, 6, 1, 2, 4, 9, 8],
		[4, 1, 8, 7, 5, 9, 6, 3, 2]]
soln	=np.array(soln)
#soln for sample 1
'''
list_input();
sudoku=np.array(sudoku)
print("Unsolved")
print (sudoku)

start_time = time.time()
solve(0, 1, sudoku, 0)



if 0 in sudoku:
	print ("\n\nUnsolvable sudoku")
else:
	print ("\n\nSolved")
	print (sudoku)


print("Executed in %s sec" % (time.time() - start_time))

