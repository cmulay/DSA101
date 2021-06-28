# author : mani-barathi

def merge(arr, l, m, r):
    i = l  # starting index of left sub array
    j = m + 1  # starting index of right sub array
    k = 0  # starting index of temp arr
    temp = ['' for i in range(l, r + 1)]
    while i <= m and j <= r:
        if arr[i] < arr[j]:
            temp[k] = arr[i]
            i += 1
        else:
            temp[k] = arr[j]
            j += 1
        k += 1

    while i <= m:  # if left subarray has more element
        temp[k] = arr[i]
        i += 1
        k += 1

    while j <= r:  # if right subarray has more element
        temp[k] = arr[j]
        j += 1
        k += 1

    k = 0
    for p in range(l, r + 1):
        arr[p] = temp[k]
        k += 1


def merge_sort(arr, l, r):
    if l < r:
        m = (l + r) // 2
        merge_sort(arr, l, m)
        merge_sort(arr, m + 1, r)
        merge(arr, l, m, r)


arr = [64, 34, 25, 12, 12, 22, 11, 90]
print('Before: ', arr)
merge_sort(arr, 0, len(arr) - 1)
print('After : ', arr)
