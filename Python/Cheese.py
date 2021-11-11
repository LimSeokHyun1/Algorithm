import collections
import sys

def is_all_melt(board, row, column):
    for i in range(row):
        for j in range(column):
            if board[i][j] == 1:
                return False
    return True

def remove_edge(board, row, column, holes):
    for i in range(row):
        for j in range(column):
            flag = 0
            if board[i][j] == 1:
                if i - 1 >= 0 and i - 1 < row and board[i - 1][j] == 0:
                    fflag = 0
                    for p in holes:
                        if p == (i-1, j):
                            fflag = 1
                            break
                    if fflag == 0:
                        board[i][j] = 2
                        flag = 1
                    
                if i + 1 >= 0 and i + 1 < row and board[i + 1][j] == 0 and flag == 0:
                    fflag = 0
                    for p in holes:
                        if p == (i+1, j):
                            fflag = 1
                            break
                    if fflag == 0:
                        board[i][j] = 2
                        flag = 1
                if j - 1 >= 0 and j - 1 < column and board[i][j - 1] == 0 and flag == 0:
                    fflag = 0
                    for p in holes:
                        if p == (i, j-1):
                            fflag = 1
                            break
                    if fflag == 0:
                        board[i][j] = 2
                        flag = 1
                if j + 1 >= 0 and j + 1 < column and board[i][j + 1] == 0 and flag == 0:
                    fflag = 0
                    for p in holes:
                        if p == (i, j+1):
                            fflag = 1
                            break
                    if fflag == 0:
                        board[i][j] = 2
                        flag = 1
    for i in range(row):
        for j in range(column):
            if board[i][j] == 2:
                board[i][j] = 0

def bfs(board, row, column, visited, bfs_queue):
    while bfs_queue:
        i, j = bfs_queue.pop()
        if i - 1 >= 0 and i - 1 < row and visited[i - 1][j] == 0 and board[i - 1][j] == 0:
            visited[i - 1][j] = 1
            bfs_queue.append((i - 1, j))
        if i + 1 >= 0 and i + 1 < row and visited[i + 1][j] == 0 and board[i + 1][j] == 0:
            visited[i + 1][j] = 1
            bfs_queue.append((i + 1, j))
        if j - 1 >= 0 and j - 1 < column and visited[i][j - 1] == 0 and board[i][j - 1] == 0:
            visited[i][j - 1] = 1
            bfs_queue.append((i, j - 1))
        if j + 1 >= 0 and j + 1 < column and visited[i][j + 1] == 0 and board[i][j + 1] == 0:
            visited[i][j + 1] = 1
            bfs_queue.append((i, j + 1))

def find_hole(board, row, column):
    hole = []
    visited = [[0 for col in range(column)] for row in range(row)]
    bfs_queue = collections.deque()
    bfs_queue.append((0, 0))
    visited[0][0] = 1
    bfs(board, row, column, visited, bfs_queue)

    for i in range(row):
        for j in range(column):
            if visited[i][j] == 0 and board[i][j] == 0:
                hole.append((i, j))
    return hole

def get_piece_num(board, row, column):
    result = 0
    for i in range(row):
        for j in range(column):
            if board[i][j] == 1:
                result += 1
    return result



holes = []
row, column = map(int, sys.stdin.readline().split())
board = [[0 for col in range(column)] for row in range(row)]
pre_board = [[0 for col in range(column)] for row in range(row)]
for i in range(row):
    num = list(map(int, sys.stdin.readline().split()))
    for j in range(column):
        board[i][j] = num[j]

time = 0
while not is_all_melt(board, row, column):
    time += 1
    piece_num = get_piece_num(board, row, column)
    holes = find_hole(board, row, column)
    remove_edge(board, row, column, holes)

# print("")
# for i in range(row):
#     for j in range(column):
#         print(board[i][j], end=' ')
#     print("")

print(time)
print(piece_num)




