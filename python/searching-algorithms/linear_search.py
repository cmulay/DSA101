# author : mani-barathi

def linear_search(arr, search):
    for i in range(len(arr)):
        if arr[i] == search:
            return i
    return None


arr = [0, 1, 4, 6, 5, 7, 3, 8, 2, 9]
search = int(input('Enter element to search: '))

result = linear_search(arr, search)

if result is None:
    print(f"{search} does'nt exists in the array")
else:
    print(f"{search} exists in the index {result}")
