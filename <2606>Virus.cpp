#include <iostream>
#include <cstring>

#define START	0

using namespace std;

int computer_num, connection, result = 0;
bool network[100][100];
bool visited[100];

void Initialize(){
	for(int i = 0; i < 100; i++){
		memset(network[i], false, 100 * sizeof(bool));
	}
	memset(visited, false, 100 * sizeof(bool));
	
	int x, y;
	for(int i = 0; i < connection; i++){
		cin >> x >> y;
		network[x - 1][y - 1] = true;
		network[y - 1][x - 1] = true;
	}
}

void DFS(int cur_com){
	for(int i = 0; i < computer_num; i++){
		if(visited[i] == false && network[cur_com][i] == 1){
			visited[i] = true;
			result++;
			DFS(i);
		}
	}
}

void Find_Computers_with_Virus(){
	visited[START] = true;
	DFS(START);
	cout << result << "\n";
}

int main(){
	cin >> computer_num >> connection;
	Initialize();
	Find_Computers_with_Virus();
}

