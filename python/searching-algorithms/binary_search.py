# author : mani-barathi

def Binary_search(arr,first,last,search):
	if first<=last:
		mid=int((last+first)/2)
		if search == arr[mid]:
			return mid		
		elif search<arr[mid]:
			return Binary_search(arr,first,mid-1,search)
		elif search>arr[mid]:
			return Binary_search(arr,mid+1,last,search)
	else:
		return None


# binary search needs the array in a sorted manner
arr=[0,1,2,3,4,5,6,7,8,9]
search=int(input('Enter element to search: '))

result=Binary_search(arr,0,len(arr)-1,search)

if result is None:
	print(f"{search} does'nt exists in the array")
else:
	print(f"{search} exists in the index {result}")