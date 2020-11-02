#include <iostream>
#include <cstring>

using namespace std;

char board[20][20];
char visited[20][20];
char pre[26];
int R, C, result = 0;	// result를 최신화 시켜야 되는 것 뿐 아니라 돌고 나올때마다 1씩 줄여줬어야 해서 cnt늘리고 줄이는 중에 최대를 저장

void DFS(int i, int j, int cnt){
	visited[i][j] = 1;
	pre[board[i][j] - 65] = 1;
	
	if(i - 1 >= 0 && visited[i - 1][j] == 0 && pre[board[i - 1][j] - 65] == 0){ // 상
		DFS(i - 1, j, ++cnt);
		visited[i - 1][j] = 0;
		pre[board[i - 1][j] - 65] = 0;
		cnt--;
	}
	if(i + 1 < R && visited[i + 1][j] == 0 && pre[board[i + 1][j] - 65] == 0){ // 하
		DFS(i + 1, j, ++cnt);
		visited[i + 1][j] = 0;
		pre[board[i + 1][j] - 65] = 0;
		cnt--;
	}
	if(j - 1 >= 0 && visited[i][j - 1] == 0 && pre[board[i][j - 1] - 65] == 0){ // 좌
		DFS(i, j - 1, ++cnt);
		visited[i][j - 1] = 0;
		pre[board[i][j - 1] - 65] = 0;
		cnt--;
	}
	if(j + 1 < C && visited[i][j + 1] == 0 && pre[board[i][j + 1] - 65] == 0){ // 우
		DFS(i, j + 1, ++cnt);
		visited[i][j + 1] = 0;
		pre[board[i][j + 1] - 65] = 0;
		cnt--;
	}
	if(result < cnt) result = cnt;
	return;
}

int main(){
	int cnt = 1;	// R: 세로, C: 가로
	char alphabet;
	for(int i = 0; i < 20; i++){
		memset(board[i], 0, sizeof(char) * 20);
		memset(visited[i], 0, sizeof(char) * 20);
	}
	memset(pre, 0, sizeof(char) * 26);
	
	cin >> R >> C;
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			cin >> alphabet;
			board[i][j] = alphabet;
		}
	}
	DFS(0, 0, cnt);
	cout << result << "\n";
}
