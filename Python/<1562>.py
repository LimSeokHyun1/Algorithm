import sys

N = 0
dp = []

def checkNum(stairNum, idx, num, bitmask):
    global N, dp
    result = 0

    stairNum[idx] = num
    bitmask |= (1 << num)

    if dp[idx][num][bitmask] >= 0:
        return dp[idx][num][bitmask]

    if idx == N - 1:
        if bitmask == 1023: 
            # print(bitmask)
            # print(stairNum)
            # print()
            return 1
        else:
            return 0
    

    if num >= 1:
        result += checkNum(stairNum, idx + 1, num - 1, bitmask)
    if num < 9:
        result += checkNum(stairNum, idx + 1, num + 1, bitmask)
    
    dp[idx][num][bitmask] = result
    return result
        

N = int(sys.stdin.readline())

idx = 0
result = 0
dp = [[[-1 for _ in range(1024)] for _ in range(10)] for _ in range(N)]
for num in range(1, 10):
    stairNum = [-1] * N
    result += checkNum(stairNum, idx, num, 0)
print(result % 1000000000)

# 비트마스크 사용해서 현재까지 사용된 숫자(bitmask), 자릿수(idx), 해당 자릿수에 들어가는 숫자(num)을 메모이제이션
# => 이에 따라, 현재까지 사용된 숫자가 같을 때 - 자릿수, 숫자까지 동일하면 DP로 가져옴
