

arr: list[int] = [1, 2, 3, 4, 5]

# 1)
print(f"{arr=}")

# 2)
print(f"{arr[::-1]=}")  # Output: [5, 4, 3, 2, 1]

# 3)
print(f"{sum(arr)=}")  # Output: 15
print(f"{sum(arr)/len(arr)=}")

# 3)
print(f"{3}")


# 4)
[print(x) for x in arr if x % 2 == 0] # Output: 2 4
[print(x) for x in arr if x % 2 != 0] # Output: 1 3 5

# 6)
n = int(input("Inserisci il numero da cercare: "))
print(f"Numero torvato in pos: {arr.index(n)}")

# 7)
n = int(input("Inserisci un elemento da eliminare: "))
arr.remove(n)
print(f"Array dopo la rimozione: {arr}")

print(f"prima {arr}")

for i in range(0, len(arr) - 1, 2):
    print(f"{i=}")
    temp = arr[i]
    arr[i] = arr[i + 1]
    arr[i + 1] = temp

print(f"Primo metodo: {arr}")

def swap(arr, p1, p2):
    temp = arr[p1]
    arr[p1] = arr[p2]
    arr[p2] = temp

[swap(arr, i, i + 1) for i in range(0, len(arr) - 1, 2)]

print(f"secondo metodo: {arr}")

# 9)
arr.sort()