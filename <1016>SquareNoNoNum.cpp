#include <iostream>

#define ll long long

using namespace std;

ll min_num, max_num;
int rangenum[1000001];
int range, result = 0;

int FindSquareNum(){
	ll pow_num, rest;
	for(ll i = 2; (i * i) <= max_num; i++){
		pow_num = i * i;
		rest = min_num % pow_num;
		for(ll j = (pow_num - rest) % pow_num; j < range; j+=pow_num){
			rangenum[j] = 1;
		}
	}
	for(int i = 0; i < range; i++){
		if(rangenum[i] == 0){
			result++;
		}
	}
	return result;
}
// 16줄 이유
// 1 2 3 4 5 6 7 8
// 1 2 3 0 1 2 3 0

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	
	fill_n(rangenum, 1000000, 0);
	cin >> min_num >> max_num;
	range = max_num - min_num + 1;
	cout << FindSquareNum() << "\n";
}

