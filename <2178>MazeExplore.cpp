#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int column, row;
char maze[100][100];
bool visited[100][100];
queue<pair<int, int>> movable_route;

void Print(){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < column; j++){
			cout << maze[i][j] << " ";
		}cout << endl;
	}
	while(!movable_route.empty()){
		cout << movable_route.front().first << " " << movable_route.front().second << endl;
		movable_route.pop();
	}
}

void Initializing(){
	for(int i = 0; i < 100; i++){
		memset(maze[i], 0, 100 * sizeof(char));
	}
	for(int i = 0; i < 100; i++){
		memset(visited[i], 0, 100 * sizeof(bool));
	}
	
	cin >> row >> column;
	
	for(int i = 0; i < row; i++){
		for(int j = 0; j < column; j++){
			cin >> maze[i][j];
		}
	}
}

void Push(int x, int y, int time){
	visited[x][y] = true;
	int pos = x * column + y;
	movable_route.push(make_pair(pos, time));
}


void Push_Adjacency_Cell(){
	int pos = movable_route.front().first;
	int x = pos / column;
	int y = pos % column;
	int time = movable_route.front().second;
	movable_route.pop();
	
	if(x - 1 >= 0 && visited[x - 1][y] == false && maze[x - 1][y] == '1'){
		Push(x - 1, y, time + 1);
	}
	if(y + 1 < column && visited[x][y + 1] == false && maze[x][y + 1] == '1'){	
		Push(x, y + 1, time + 1);
	}
	if(x + 1 < row && visited[x + 1][y] == false && maze[x + 1][y] == '1'){
		Push(x + 1, y, time + 1);
	}
	if(y - 1 >= 0 && visited[x][y - 1] == false && maze[x][y - 1] == '1'){
		Push(x, y - 1, time + 1);
	}
}

bool Is_Maze_Exit(int pos){
	if(pos / column == row - 1 && pos % column == column - 1) return true;
	else return false;
}

void Find_Min_Route(){
	Push(0, 0, 1);
	while(1){
		if(Is_Maze_Exit(movable_route.front().first)){
			cout << movable_route.front().second << "\n";
			break;
		}
		Push_Adjacency_Cell();
	}	
	return;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	
	Initializing();
	Find_Min_Route();
}
