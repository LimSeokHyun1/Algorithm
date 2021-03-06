#include <iostream>
#include <string>
#include <list>
#include <cstdio>

using namespace std;


int main(){	//cin은 공백, 엔터 '무시'하나 버퍼에 남아 그 후에 getline쓰면 종료 되는 것.
			//get은 공백, 엔터 '저장'할 수 있고, 버퍼에 남아있기도 함.
	list<char> editor;
	string input;
	int cursor, count;
	char inst;

	getline(cin, input);
	
	for(int i = 0; i < input.size(); i++){
		editor.push_back(input[i]);
	}
	
	list<char>::iterator iter = editor.end();
	list<char>::iterator iiter;
	
	cin >> count;
	
	while(count--){	// STL List에서 erase 쓰면 iterator값이 튀니까 미리 temp에 저장해놓고 써야함..
			// 아니면 iter = editor.erase(iter)
		cin >> inst;
		if(inst == 'L'){
			if(iter != editor.begin())
				iter--;
		}
		else if(inst == 'D'){
			if(iter != editor.end())
				iter++;
		}
		else if(inst == 'B'){
			if(iter != editor.begin()){
				iiter = iter;
				iter--;
				editor.erase(iter);
				iter = iiter;
			}
		}
		else if(inst == 'P'){
			cin >> inst;
			editor.insert(iter, inst);
		}
		else{
			break;
		}
	}
	
	for(list<char>::iterator iter = editor.begin(); iter != editor.end(); iter++){
    	cout << *iter;
    }cout << endl;
	

}
