#include <iostream>

using namespace std;
int main(){	// 1000 이하였기 때문에 31까지만 확인해보면 됨. 2, 3, 5, 7, 9, 11, 13, 15, 17, 19
	        // 21, 23, 29, 31
	int prime[13] = {2, 3, 5, 7, 11, 13, 15, 17, 19, 21, 23, 29, 31};
	int amount, num, result = 0, flag;
	
	cin >> amount;
	for(int i = 0; i < amount; i++){
		flag = 0;
		cin >> num;
		for(int i = 0; i < 13; i++){
			if(num == 1){
				flag = 1;
				break;
			}
			if(num == prime[i])	break;
			if(num % prime[i] == 0){
				flag = 1;
				break;
			}
		}
		if(flag == 0)	result++;
	}
	cout << result << '\n';
}

//*******************************************************************************************

#include <iostream>
#include <cmath>

using namespace std;

int Verify(int num){
	if(num == 2 || num == 3) return 1;
	if(num == 1 || num % 2 == 0) return 0;
	for(int i = 2; i <= sqrt(num); i++){
		if(num % i == 0) return 0;
	}
	return 1;
}

int main(){
	int amount, num, result = 0;
	cin >> amount;
	for(int i = 0; i < amount; i++){
		cin >> num;
		result += Verify(num);
	}
	cout << result << '\n';
}
