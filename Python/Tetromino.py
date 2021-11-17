import collections
import sys

def find_max(board, N, M):
    res = collections.deque()
    max = 0
    for i in range(N):
        for j in range(M):
            if max < board[i][j]:
                max = board[i][j]
    for i in range(N):
        for j in range(M):
            if board[i][j] == max:
                res.append((i, j))
    return res

def find_around_index(board, visited, N, M, cur_idx):
    res = []
    dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]
    for x, y in cur_idx:
        for i in range(4):#4directions
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < N and 0 <= ny < M:
                if visited[nx][ny] == 0:
                    res.append((nx, ny))
                    visited[nx][ny] = 1
    for i in range(N):
        for j in range(M):
            if visited[i][j] == 1:
                visited[i][j] = 0
    return res

def greedy_search(board, N, M, max_list):
    result = []
    for x, y in max_list:
        visited = [[0] * M for _ in range(N)]
        cur_idx = [(x, y)]
        visited[x][y] = 2
        res = 0
        for _ in range(4):
            max = 0
            around_idx = find_around_index(board, visited, N, M, cur_idx)
            for a, b in around_idx:
                if max < board[a][b]:
                    max = board[a][b]
            for a, b in around_idx:
                if max == board[a][b]:
                    cur_idx.append((a, b))
                    visited[a][b] = 2
                    break
        for i in range(4):
            res += board[cur_idx[i][0]][cur_idx[i][1]]
        result.append(res)
    max = 0
    for i in result:
        if max < i:
            max = i
    return max

N, M = map(int, sys.stdin.readline().split())
max = 0
board = [list(map(int, input().split())) for _ in range(N)]
max_list = find_max(board, N, M)
print(greedy_search(board, N, M, max_list))

