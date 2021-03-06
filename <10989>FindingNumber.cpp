//****************counting sort써서 푸는 방법**********
#include <iostream>

using namespace std;

int main(){
	int n, num;
	int index[10001];
	
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	fill(index, index + 10001, 0);
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> num;
		index[num]++;
	}
	
	for(int i = 1; i <= 10000; i++){
		for(int j = 0; j < index[i]; j++){
			cout << i << "\n";
		}
	}
	
}

//***************2751번은 STL sort로 ********************

#include <iostream>
#include <algorithm>

using namespace std;
int idata[1000000];

int main(){
	int n, num;
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	fill(idata, idata + 1000000, 0);
	
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> num;
		idata[i] = num;
	}
	
	sort(idata, idata + n);
	
	for(int i = 0; i < n; i++){
		cout << idata[i] << "\n";
	}
	
}
