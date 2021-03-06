#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int count, length, dec, fflag = 0, flag = 0, rflag = 0;
	string arr_data, p;
	deque<int> arr;
	cin >> count;
	while(count--){
		fflag = 0;
		rflag = 0;
		flag = 0;
		arr.clear();
		arr_data.clear();
		p.clear();
		cin >> p;
		cin >> length;
		cin >> arr_data;
		for(int i = 0; i < arr_data.size(); i++){
			if(48 <= arr_data[i] && arr_data[i] <= 57){
				flag++;
				if(flag == 1){
					dec = arr_data[i] - 48;
				}
				else if(flag == 2){
					dec *= 10;
					dec += arr_data[i] - 48;
				}
				else{
					dec = 100;
				}
			}
			else{
				if(flag > 0){
					arr.push_back(dec);
				}
				flag = 0;
				dec = 0;
			}
		}
		
		for(int i = 0; i < p.size(); i++){
			if(p[i] == 'R'){
				rflag ^= 1;
			}
			else if (p[i] == 'D'){
				length--;
				if(arr.empty()){
					cout << "error\n";
					fflag = 1;
					break;
				}
				if(rflag == 0){
					arr.pop_front();
				}
				else{
					arr.pop_back();
				}
			}
		}

		/*
		for(deque<int>::iterator iter = arr.begin(); iter!=arr.end(); ++iter){
			cout << *iter << " ";
		}cout << endl;*/
		
		if(fflag == 0){
			if(arr.empty()){
				cout << "[]\n";
			}
			else{
				if(rflag == 0){
					cout << '[';
					for(deque<int>::iterator iter = arr.begin(); iter!=arr.end(); ++iter){
						length--;
						if(length == 0){
							cout << *iter;
						}
						else{
							cout << *iter << ',';
						}
					}cout << "]\n";
				}
			
				else{
					cout << '[';
					for(deque<int>::reverse_iterator iter = arr.rbegin(); iter!=arr.rend(); ++iter){
						length--;
						if(length == 0){
							cout << *iter;
						}
						else{
							cout << *iter << ',';
						}
					}cout << "]\n";
				}
			}
		}
	}
}
