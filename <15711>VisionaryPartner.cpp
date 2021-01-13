#include <iostream>
#include <math.h>
#include <vector>

#define MAX_NUM 2000001

using namespace std;

bool primenum[MAX_NUM];
vector<int> primenumvec;
int TC;
long long A, B, sum;

void FindPrimeNum(){
	primenum[0] = false;
	primenum[1] = false;
	primenum[2] = true;
	primenum[3] = true;
	for(int i = 2; i < sqrt(MAX_NUM); i++){
		if(primenum[i] == true){
			for(int j = i * i; j < MAX_NUM; j += i){
				primenum[j] = false;
			}
		}
	}
	for(int i = 2; i < MAX_NUM; i++){
		if(primenum[i] == true){
			primenumvec.push_back(i);
		}
	}
}

bool DeterPrimeNum(long long targetnum){
	for(int i = 0; i < primenumvec.size(); i++){
		if((long long)primenumvec[i] * primenumvec[i] > targetnum){
			break;	
		}
		if(targetnum % primenumvec[i] == 0){
			return false;
		}
	}
	return true;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	
	fill_n(primenum, MAX_NUM, true);
	FindPrimeNum();
	
	cin >> TC;
	for(int i = 0; i < TC; i++){
		cin >> A >> B;
		sum = A + B;
		
		if(sum < 4) cout << "NO\n";
		else if(sum % 2 == 0) cout << "YES\n";
		else{
			if(DeterPrimeNum(sum - 2)){
				cout << "YES\n";
			}
			else{
				cout << "NO\n";
			}
		}
	}
}
/*
4이상의 짝수는 모두 소수 두개로 나눌 수 있다. - 골드바흐의 추측
홀수 = 짝수 + 홀수 -> 근데 짝수 소수 2 뿐이므로 무조건 2 + 홀수인데, 
이 나머지 홀수가 소수면 된다!

Q) 10000까지 소수 모두 구해라
	-> 10000까지의 수를 1 ~ 100 으로 에라토스테네스의 체 사용
Q) 10000까지의 수 중 x가 소수냐?
	-> 100까지 소수를 모두 준비해서 그 소수들로 직접 하나씩 나눠보기
	-> 100까지의 소수 구할 땐, 100까지의 수를 1 ~ 10으로 에라토스테네스의 체 사용
	
+) 당연히 TC가 있으므로 할 때마다 다 돌면서 prime num이 true인지 확인하는 것 보다 미리 소수를 벡터에 빼놓는게 더 이득. 
*/
