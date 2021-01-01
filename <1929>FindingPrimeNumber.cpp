#include <iostream>
#include <cmath>
#include <vector>

using namespace std;	

vector<char> num;		//int로 하면 커지는 지 확인좀.
int M, N, r_N;

void Delete(int factor){
	int i = 2;
	while(factor * i <= N){
		num[factor * i] = '0';
		//cout << "factor: " << factor * i << endl;
		i++;
	}
}

int main(){			// 소수 아니면 0, 소수면 1
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> M >> N;
	r_N = sqrt(N);

	num.push_back('0');		// 0은 소수 아님
	num.push_back('0');		// 1은 소수 아님
	for(int i = 2; i <= N; i++){
		num.push_back('1');
	}
	
	int i = 2;
	while(i <= r_N){
		if(num[i] == '1'){
			//cout << "i: " << i << endl;
			Delete(i);
		}
		i++;
	}
	
	for(int i = M; i <= N; i++){
		if(num[i] == '1') cout << i << "\n";
	}
}
