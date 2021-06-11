# author : mani-barathi

def insertion_sort(arr):
  size = len(arr)
  for i in range(1,size):
    for j in range(i,0,-1):
      if arr[j] < arr[j-1]:
          arr[j],arr[j-1] = arr[j-1], arr[j]

arr = [64, 34, 25, 12,12, 22, 11, 90]
print("Before: ",arr)
insertion_sort(arr)
print("After : ",arr)