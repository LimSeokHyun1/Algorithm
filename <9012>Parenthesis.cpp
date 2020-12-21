#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
	int count;
	string data;
	stack<int> s;
	cin >> count;
	for(int i = 0; i < count; i++){
		cin >> data;
		for(int j = 0; j < data.size(); j++){
			if(data[j] == '('){
				s.push(1);
			}
			else if(data[j] == ')'){
				if(s.empty()){
					s.push(1);
					break;
				}
				else{
					s.pop();
				}
			}
		}
		if(s.empty()){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
			while(!s.empty()){
				s.pop();
			}
		}
	}
}


