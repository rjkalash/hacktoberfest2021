#Python program to implement Binary Search

def binarySearch(arr,target):
    start = 0
    end  = len(arr)-1

    #finding whether the array is sorted in ascending order or descending order
    if arr[start]<arr[end]:
        isAsc  = True
    else:
        isAsc = False

    while start <= end:
        mid  = int(start + ((end - start)/2)) #finding the middle element

        if arr[mid]==target:
            return mid #target found

        if isAsc:  #for array sorted in ascending order
            if arr[mid]<target:
                start = mid + 1
            else:
                end  = mid -1
        else:      #for array sorted in descending order
            if arr[mid]>target:
                start = mid + 1
            else:
                end  = mid -1
    return -1  #target not present in the array

#driver code
arr = [7,6,5,4,3,2,1]
target = 4
result = binarySearch(arr,target)
print("Index of target element=",result)
