#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int num, result = 0;
	cin >> num;
	
	int* first = new int[num];
	int* second = new int[num];
	
	for(int i = 0; i < num; i++){
		cin >> first[i];
	}
	for(int i = 0; i < num; i++){
		cin >> second[i];
	}
	
	sort(first, first + num, greater<int>());
	sort(second, second + num, less<int>());
	
	for(int i = 0; i < num; i++){
		result += first[i] * second[i];
	}
	cout << result << "\n";
}