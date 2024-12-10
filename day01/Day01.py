a = []

first = list()
second = list()

for line in open('input.txt', 'r') :
    a = line.split()
    first.append(a[0])
    second.append(a[1])

print(sum([int(i) * second.count(i) for i in first]))
# print(b)