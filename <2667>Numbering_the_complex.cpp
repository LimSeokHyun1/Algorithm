#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX_SIZE	25

using namespace std;

int map_size, complex_size, result_idx = 0;
char map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int result[(MAX_SIZE * MAX_SIZE) / 2];

void Initialize(){
	for(int i = 0; i < MAX_SIZE; i++){
		memset(map[i], 0, sizeof(char) * MAX_SIZE);
	}
	for(int i = 0; i < MAX_SIZE; i++){
		memset(visited[i], false, sizeof(bool) * MAX_SIZE);
	}
	for(int i = 0; i < map_size; i++){
		for(int j = 0; j < map_size; j++){
			cin >> map[i][j];
		}
	}
}

void Find_Complex_Size(int x, int y){
	visited[x][y] = true;
	complex_size++;
	if(x - 1 >= 0 && visited[x - 1][y] == false && map[x - 1][y] == '1')	Find_Complex_Size(x - 1, y);
	if(y + 1 < map_size && visited[x][y + 1] == false && map[x][y + 1] == '1')	Find_Complex_Size(x, y + 1);
	if(x + 1 < map_size && visited[x + 1][y] == false && map[x + 1][y] == '1')	Find_Complex_Size(x + 1, y);
	if(y - 1 >= 0 && visited[x][y - 1] == false && map[x][y - 1] == '1')	Find_Complex_Size(x, y - 1);
	return;
}

void Find_House_Complex(){
	for(int i = 0; i < map_size; i++){
		for(int j = 0; j < map_size; j++){
			if(map[i][j] == '1' && visited[i][j] == false){
				complex_size = 0;
				Find_Complex_Size(i, j);
				result[result_idx++] = complex_size;
			}
		}
	}
	
	cout << result_idx << "\n";
	
	sort(result, result + result_idx);
	for(int i = 0; i < result_idx; i++){
		cout << result[i] << "\n";
	}
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	
	cin >> map_size;
	Initialize();
	Find_House_Complex();
}

