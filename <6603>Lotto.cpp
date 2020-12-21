#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
vector<int> result;

void ChoosingNumber(int start, int count){
	if(result.size() == 6){
		for(int i = 0; i < 6; i++){
			cout << result[i] << " ";
		} cout << endl;
		return;
	}
	for(int i = start + 1; i < count; i++){
		result.push_back(v[i]);
		ChoosingNumber(i, count);
		result.pop_back();
	}
	return;
}

int main(){
	int count, num;
	while(1){
		v.clear();
		result.clear();
		cin >> count;
		if(count == 0) break;
		for(int i = 0; i < count; i++){
			cin >> num;
			v.push_back(num);
		}
		ChoosingNumber(-1, count);
		cout << '\n';
	}
}
