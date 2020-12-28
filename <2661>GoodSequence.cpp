#include <iostream>
#include <vector>

using namespace std;
 
int good_array[80];
int array_length, recursive_end_flag = 0;

void Show_Array();
void Make_Array(int tar_idx, int pre);
bool Deter_Good_Array();

int main(){
	cin >> array_length;
	Make_Array(0, -1);
}

void Show_Array(){
	for(int i = 0; i < array_length; i++){
		cout << good_array[i];
	}
	cout << "\n";
}

void Make_Array(int tar_idx, int pre){
	if(tar_idx == array_length){
		if(array_length <= 3){
			recursive_end_flag = 1;
			Show_Array();
			return;
		}
		if(Deter_Good_Array()){
			recursive_end_flag = 1;
			Show_Array();
		}
		return;
	}
	
	for(int i = 1; i <= 3; i++){
		if(i == pre) continue;
		good_array[tar_idx] = i;
		Make_Array(tar_idx + 1, i);
		if(recursive_end_flag == 1) return;
	}
}

bool Deter_Good_Array(){
	Show_Array();
	int pre_idx, cur_idx, same_num_flag;
	for(int i = 2; i <= array_length / 2; i++){
		pre_idx = 0;
		cur_idx = 0;
		while(cur_idx + i <= array_length){
			same_num_flag = 0;
			cur_idx = pre_idx + i;
			//cout << "cur_idx: " << cur_idx << " pre_idx: " << pre_idx << endl;
			for(int j = 0; j < i; j++){
				//cout << "cur: " << good_array[cur_idx + j] << " pre: " << good_array[pre_idx + j] << endl;
				if(good_array[cur_idx + j] != good_array[pre_idx + j]){
					same_num_flag = 1;
					break;
				}
			}
			if(same_num_flag == 0){
				return false;
			}
			cur_idx++;
			pre_idx++;
		}
	}
	return true;
}
