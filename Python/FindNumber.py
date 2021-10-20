N = int(input())
numset1 = input().split()
M = int(input())
numset2 = input().split()
length = len(numset1) - 1
numset1.sort()

def binary_search(first, last ,tar):
    mid = (first + last) // 2
    if first > last:
        return '0'
    if numset1[mid] == tar:
        return '1'
    elif numset1[mid] < tar:
        return binary_search(mid + 1, last, tar)
    else:
        return binary_search(first, mid - 1, tar)

for i in numset2:
    print(binary_search(0, length, i))
