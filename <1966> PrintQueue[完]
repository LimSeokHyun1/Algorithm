#include <iostream>
#include <deque>
#include <utility>

using namespace std;

int main(){
	int test, N, M, prior, result = 0, flag;
	deque<pair<int, int>> file;
	cin >> test;
	int *arr = new int[test];
	
	for(int i = 0; i < test; i++){
		result = 0;
		cin >> N >> M;
		file.clear();
		for(int j = 0; j < N; j++){
			cin >> prior;
			file.push_back(make_pair(prior, j));
		}
		
		while(1){
			flag = 0;
			if(N == 1){
				arr[i] = 1;
				break;
			}
			for(int i = 1; i < N - result; i++){
				if(file[0].first < file[i].first){
					flag = 1;
					file.push_back(make_pair(file[0].first, file[0].second));
					file.pop_front();
				/*	for(deque<pair<int, int>>::iterator iiter = file.begin(); iiter!=file.end(); ++iiter){
						cout << iiter->first << " : " << iiter->second << "  ";
					}cout << endl;*/
					break;
				}
			}
			if(flag == 0){
				result++;
				if(file[0].second == M){
					arr[i] = result;
					break;
				}
				else{
					file.pop_front();
				}
			}
			
		}
	}
	for(int i = 0; i < test; i++){
		cout << arr[i] << "\n";
	}
}
