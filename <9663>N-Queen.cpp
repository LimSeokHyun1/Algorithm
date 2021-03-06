// 첫 시도 답은 맞으나 시간 초과
#include <iostream>
#include <string.h>

using namespace std;

int N, result = 0;
int** board;

void Set(int x, int y){
	int tx, ty;
	for(int i = 0; i < N; i++){
		board[x][i] = 1;
	}
	for(int i = 0; i < N; i++){
		board[i][y] = 1;
	}
	tx = x;
	ty = y;
	while((tx >= 0 && tx < N) && (ty >= 0 && ty < N)){
		board[tx][ty] = 1;
		tx--;
		ty--;
	}
	tx = x;
	ty = y;
	while((tx >= 0 && tx < N) && (ty >= 0 && ty < N)){
		board[tx][ty] = 1;
		tx++;
		ty++;
	}
	tx = x;
	ty = y;
	while((tx >= 0 && tx < N) && (ty >= 0 && ty < N)){
		board[tx][ty] = 1;
		tx++;
		ty--;
	}
	tx = x;
	ty = y;
	while((tx >= 0 && tx < N) && (ty >= 0 && ty < N)){
		board[tx][ty] = 1;
		tx--;
		ty++;
	}
}

void NQueen(int queen, int p, int q){
	/*cout << endl;
	cout << endl;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	*/
	int** temp = new int*[N];
	for(int i = 0; i < N; i++){
		temp[i] = new int[N];
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			temp[i][j] = board[i][j];
		}
	}
	
	if(queen == 0){
		//cout << "HERE!!!\n";
		result++;
		for(int i = 0; i < N; ++i){
			delete[] temp[i];
		}
		delete[] temp;
		return;
	}
	int i, j;
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			if(i < p) continue;
			if(i == p && j <= q) continue;
			if(board[i][j] == 0){
				//cout << "\ni: " << i << " j: " << j << endl;
				Set(i, j);
				NQueen(queen - 1, i, j);
				for(int a = 0; a < N; a++){
					for(int b = 0; b < N; b++){
						board[a][b] = temp[a][b];
					}
				}
			}
		}
		j = 0;
	}
	
	for(int i = 0; i < N; ++i){
		delete[] temp[i];
	}
	delete[] temp;
	
	return;
}

int main(){
	cin >> N;
	
	board = new int*[N];
	for(int i = 0; i < N; i++){
		board[i] = new int[N];
	}
	for(int i = 0; i < N; i++){
		memset(board[i], 0, sizeof(int) * N);
	}


	NQueen(N, -1, -1);
	cout << result << "\n";
	
	for(int i = 0; i < N; ++i){
		delete[] board[i];
	}
	delete[] board;
}

//****************두 번째 시도****************

#include <iostream>
#include <cstring>

using namespace std;

int N, result = 0, sum, sub, start;
int** board;

void Print(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}cout << endl;
}

bool Find(int x, int y){
	for(int i = 0; i < N; i++){
		//cout << "2x: " << i << " y: " << y << endl;
		if(board[i][y] == 1)
			return false;
	}
	
	sum = x + y;
	if(N - sum > 0){
		for(int i = 0; i < sum + 1; i++){
			if(board[i][sum - i] == 1)
				return false;
		}
	}
	else{
		for(int i = sum - N + 1; i < N; i++){
			if(board[i][sum - i] == 1)
				return false;
		}
	}

	sub = x - y;
	
	if(sub <= 0){
		for(int i = 0; i < N + sub; i++){
			if(board[i][i - sub] == 1)
				return false;
		}
	}
	else{
		for(int i = sub; i < N; i++){
			if(board[i][i - sub] == 1)
				return false;
		}
	}
	
	
	return true;
}


void NQueen(int queen, int x_pre, int y_pre){
	//cout << "queen: " << queen << endl;
	//Print();
	
	if(queen == 0){
		result++;
		return;
	}
	
	for(int i = x_pre + 1; i < N; i++){
		for(int j = 0; j < N; j++){
			if(j == y_pre || j == y_pre - 1 || j == y_pre + 1) continue;
			if(Find(i, j)){
				board[i][j] = 1;
				NQueen(queen-1, i, j);
				board[i][j] = 0;
			}
		}
	}
	return;
}

int main(){
	cin >> N;
	//시간 중요할 때는 정적이 좋음.
	board = new int*[N];
	for(int i = 0; i < N; i++){
		board[i] = new int[N];
	}
	for(int i = 0; i < N; i++){
		memset(board[i], 0, sizeof(int) * N);
	}


	NQueen(N, -1, -2);
	cout << result << "\n";
	
	for(int i = 0; i < N; ++i){
		delete[] board[i];
	}
	delete[] board;
}

***********세번째 시도***********

// 속도 중요할 때는 정적 할당이 유리
// visit buffer에 masking 

#include <iostream>
#include <cstring>

using namespace std;


//시간 중요할 때는 정적이 좋음.

int N, result = 0, next, num;
int board[14][14];

int y_visit[14];
int r_visit[27];	// 2*N - 1, sum
int l_visit[27];	// 2*N - 1, subtract + N - 1

void Print(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}cout << endl;
	cout << "********************" << endl;
}


int Set(int x, int y, int state){
	if(state == 1){
		if(y_visit[y] == 0 && r_visit[x + y] == 0 && l_visit[x - y + N - 1] == 0){
			board[x][y] = 1;
			y_visit[y] = 1;
			r_visit[x + y] = 1;
			l_visit[x - y + N - 1] = 1;
			return 1;
		}	
		else return 0;
	}
	else{
		board[x][y] = 0;
		y_visit[y] = 0;
		r_visit[x + y] = 0;
		l_visit[x - y + N - 1] = 0;
	}
	return 1;
}



void NQueen(int depth){
	//Print();
	
	if(depth == N){
		result++;
		return;
	}
	
	
	for(int i = 0; i < N; i++){
		if(Set(depth, i, 1)){
			NQueen(depth + 1);
			Set(depth, i, 0);
		}
	}
	
	return;
}

int main(){
	cin >> N;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			board[i][j] = 0;
		}
		y_visit[i] = 0;
	}
	for(int i = 0; i < 2*N-1; i++){
		r_visit[i] = 0;
		l_visit[i] = 0;
	}
	
	NQueen(0);
	
	cout << result << "\n";
}
