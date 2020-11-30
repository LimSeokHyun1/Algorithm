#include <iostream>
#include <cmath>

using namespace std;

int result = 0;

void OTT(int n){
	
	if(n == 1){
		result++;
		return;
	}
	else if(n == 2){
		result += 2;
		return;
	}
	else if(n == 3){
		result += 4;
		return;
	}
	else{
		OTT(n - 1);
		OTT(n - 2);
		OTT(n - 3);
	}
	return;
}

int main(){
	int count, n;
	cin >> count;
	while(count--){
		result = 0;
		cin >> n;
		OTT(n);
		cout << result << "\n";
	}
}
