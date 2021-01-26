#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int memo_one[41];
int memo_zero[41];
bool visited[41];
vector<int> input_num;

void Initialize(){
	memset(memo_zero, 0, sizeof(int) * 41);
	memset(memo_one, 0, sizeof(int) * 41);
	memset(visited, false, sizeof(bool) * 41);
	memo_zero[0] = 1;
	memo_one[0] = 0;
	memo_zero[1] = 0;
	memo_one[1] = 1;
	visited[0] = true;
	visited[1] = true;
}

void fibonacci(int n){
	if(visited[n - 1] == true && visited[n - 2] == true){
		memo_zero[n] = memo_zero[n - 1] + memo_zero[n - 2];
		memo_one[n] = memo_one[n - 1] + memo_one[n - 2];
		visited[n] = true;
		return;
	}
	if(n == 0){
        return;
    }
	else if(n == 1){
        return;
    }
	else{
		fibonacci(n - 1); 
      	fibonacci(n - 2); 
		memo_zero[n] = memo_zero[n - 1] + memo_zero[n - 2];
		memo_one[n] = memo_one[n - 1] + memo_one[n - 2];
		visited[n] = true;
		return;
    }
}

int main(){
	int TC, fib_num;
	cin >> TC;
	Initialize();
	for(int i = 0; i < TC; i++){
		cin >> fib_num;
		input_num.push_back(fib_num);
		fibonacci(fib_num);
	}
	for(int i = 0; i < input_num.size(); i++){
		cout << memo_zero[input_num[i]] << " " << memo_one[input_num[i]] << "\n";
	}
}
