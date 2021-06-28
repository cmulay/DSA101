# author : mani-barathi

def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]


def partition(arr, l, r):
    pivot = arr[r]
    i = l - 1
    j = l
    for j in range(l, r):
        if arr[j] < pivot:
            i += 1
            swap(arr, i, j)
    i += 1
    swap(arr, i, r)
    return i


def quick_sort(arr, l, r):
    if l < r:
        newIndex = partition(arr, l, r)
        quick_sort(arr, newIndex + 1, r)
        quick_sort(arr, l, newIndex - 1)


arr = [64, 34, 25, 12, 12, 22, 11, 90]
print("Before:", arr)
quick_sort(arr, 0, len(arr) - 1)
print('After :', arr)
