#include <stdio.h>

char **matrix = NULL;
int vertex = 0;
int r = 0, front = 0, rear = 0;

int Dequeue(int* queue){
	int pre = 0;
	if(front == rear) printf("EMPTY\n");
	else{
		pre = front;
		front = (front + 1) % 1000;
		return queue[pre];
	}
}
void Enqueue(int* queue, int i){
	if((rear + 1) % 1000 == front % 1000) printf("FULL!\n");
	else{
		queue[rear] = i;
		rear = (rear + 1) % 1000;
	}
}

void DFS(int* result, int* visited, int pre){
	for(int i = 0; i < vertex; i++){
		if(matrix[pre - 1][i] == 1 && visited[i] == 0){
			visited[i] = 1;
			result[r++] = i + 1;
			DFS(result, visited, i + 1);
		}
	}
	return;
}
void BFS(int* result, int* visited, int* queue){
	int start = 0;
	while(front != rear){
		start = Dequeue(queue);
		for(int i = 0; i < vertex; i++){
			if(matrix[start][i] == 1 && visited[i] == 0){
				Enqueue(queue, i);
			}
		}
		result[r++] = start + 1;
		visited[start] = 1;
	}
}

int main() {
	int *result = NULL;
	int *visited = NULL;
	int queue[1000] = {0, };
	int start = 0;
	int edge = 0;
	int a = 0, b = 0, temp = 0;
	int i = 5;
	scanf("%d %d %d", &vertex, &edge, &start);
	//printf("ver: %d edge: %d start: %d\n", vertex, edge, start);
	
	matrix = (char **)malloc(sizeof(char*) * vertex);
	for(int i = 0; i < vertex; i++){
		matrix[i] = (char *)malloc(sizeof(char) * vertex);
	  memset(matrix[i], 0, sizeof(char) * vertex); // memset을 써보았당
	}
	
	result = (int *)malloc(sizeof(int) * vertex);
	memset(result, 0, sizeof(int) * vertex);
	result[r++] = start;
	
	visited = (int *)malloc(sizeof(int) * vertex);
	memset(visited, 0, sizeof(int) * vertex);
	visited[start - 1] = 1;	//방문했으면 1
	
	Enqueue(queue, start - 1); // start - 1 함!!!!
	
	temp = edge;
	while(temp--){
		scanf(" %d %d", &a, &b);
		matrix[a - 1][b - 1] = 1;
		matrix[b - 1][a - 1] = 1;
	}
	
	DFS(result, visited, start);
	for(int i = 0; i < vertex; i++){
		printf("%d ", result[i]);
	}	printf("\n");
	
	
	r = 0;
	memset(result, 0, sizeof(int) * vertex);
	memset(visited, 0, sizeof(int) * vertex);
	
	BFS(result, visited, queue);
	for(int i = 0; i < vertex; i++){
		printf("%d ", result[i]);
	}	printf("\n");
	
	/*
	for(int i = 0; i < vertex; i++){
		for(int j = 0; j < vertex; j++){
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}*/
	
	return 0;
}


// 백준 시간초과 안 걸린 코드

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int vertex_num, edge_num, start_vertex;
int x, y;
bool graph[1000][1000];
bool visited[1000];
queue<int> bfs_queue;

void Initialize_Graph(){
	for(int i = 0; i < 1000; i++){
		memset(graph[i], 0, sizeof(bool) * 1000);
	}
}

void Initialize_Array(){
	memset(visited, 0, sizeof(bool) * 1000);
}

void Make_Adjacency_Matrix(){
	for(int i = 0; i < edge_num; i++){
		cin >> x >> y;
		graph[x - 1][y - 1] = true;
		graph[y - 1][x - 1] = true;
	}
}

void DFS(int start){
	cout << start + 1 << " ";
	for(int i = 0; i < vertex_num; i++){
		if(graph[start][i] == true && visited[i] == 0){
			visited[i] = 1;
			DFS(i);
		}
	}
	return;
}
void DFS_Search(){
	visited[start_vertex - 1] = 1;
	DFS(start_vertex - 1);
	cout << "\n";
}

void BFS(int start){
	// ********** Recursive ver. **********
	if(bfs_queue.empty()) return;
	cout << start + 1 << " ";
	bfs_queue.pop();
	for(int i = 0; i < vertex_num; i++){
		if(graph[start][i] == true && visited[i] == 0){
			visited[i] = 1;
			bfs_queue.push(i);
		}
	}
	BFS(bfs_queue.front());
	return;
	
	
	// ********** Iteration ver. (No need to use parameter) **********
	while(!bfs_queue.empty()){
		int start_ver = bfs_queue.front();
		cout << start_ver + 1 << " ";
		bfs_queue.pop();
		
		for(int i = 0; i < vertex_num; i++){
			if(graph[start_ver][i] == true && visited[i] == 0){
				visited[i] = 1;
				bfs_queue.push(i);
			}
		}
	}
}

void BFS_Search(){
	visited[start_vertex - 1] = 1;
	bfs_queue.push(start_vertex - 1);
	BFS(start_vertex - 1);
	cout << "\n";
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	
	Initialize_Graph();
	Initialize_Array();
	cin >> vertex_num >> edge_num >> start_vertex;
	Make_Adjacency_Matrix();
	
	DFS_Search();
	Initialize_Array();
	BFS_Search();
}



