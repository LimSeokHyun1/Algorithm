#include <iostream>
#include <queue>

using namespace std;

int input;
queue<pair<int, int>> calculated_num;

void Make_Input_One(){
	int front, cnt;
	calculated_num.push(make_pair(input, 0));
	while(1){
		front = calculated_num.front().first;
		cnt = calculated_num.front().second;
		
		if(front == 1) break;
		
		calculated_num.pop();
		
		if(front % 3 == 0){
			calculated_num.push(make_pair(front / 3, cnt + 1));
		}
		if(front % 2 == 0){
			calculated_num.push(make_pair(front / 2, cnt + 1));
		}
		calculated_num.push(make_pair(front - 1, cnt + 1));
	}
	cout << cnt << "\n";
}

int main(){
	cin >> input;
	Make_Input_One();
}

//
