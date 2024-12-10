res = 0
def isSafe(array):
    if array != sorted(array) and array[::-1] != sorted(array): return 0
    for i in range(len(array) - 1):
        if abs(int(array[i + 1]) - int(array[i])) < 1 or abs(int(array[i + 1]) - int(array[i])) > 3: return 0
    return 1

for line in open('input.txt', 'r'):
    array = [int(x) for x in line.split()]
    for i in range(len(array)):
        if isSafe(array[:i]+array[i+1:]):
            res += 1
            break
print(res)