# author : mani-barathi

def smallest(arr):
    return min(arr)


def selection_sort(arr):
    for i in range(len(arr)):
        current = arr[i]
        small_index = arr.index(smallest(arr[i:]))
        arr[i] = arr[small_index]
        arr[small_index] = current
    return arr


arr = [64, 34, 25, 12, 12, 22, 11, 90]
print("Before:", arr)
selection_sort(arr)
print('After :', arr)
