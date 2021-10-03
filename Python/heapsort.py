def heap(arr, n, i):
	a = i 
	l = 2 * i + 1
	r = 2 * i + 2	
	if l < n and arr[i] < arr[l]:
		a = l
	if r < n and arr[a] < arr[r]:
		a = r
	if a != i:
		arr[i],arr[a] = arr[a],arr[i] 
		heap(arr, n, a)
def hS(arr):
	n = len(arr)

	for i in range(n // 2 - 1, -1, -1):
		heap(arr, n, i)

	for i in range(n-1, 0, -1):
		arr[i], arr[0] = arr[0], arr[i]
		heap(arr, i, 0)

arr = [ 12, 1, 33, 25, 63, 17]
hS(arr)
n = len(arr)
print ("Sorted array =")
for i in range(n):
	print ("%d" %arr[i])
