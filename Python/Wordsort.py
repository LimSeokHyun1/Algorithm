import sys

N = int(input())

wordlist = list()
for _ in range(N):
    wordlist.append(input())

wordset = set(wordlist)
wordlist = list(wordset)# 중복제거

wordlist = sorted(wordlist)#sorted는 stable sort
wordlist = sorted(wordlist, key=lambda word: len(word))#lambda식 활용하여 길이로 sort한번 더

for i in range(len(wordlist)):
    print(wordlist[i])
