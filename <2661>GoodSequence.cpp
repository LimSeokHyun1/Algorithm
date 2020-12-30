#include <iostream>
#include <vector>

using namespace std;
 
int good_array[80];
int array_length, recursive_end_flag = 0;

void Make_Array(int tar_idx, int pre);
bool Deter_Good_Array(int tar_idx);

int main(){
	cin >> array_length;
	Make_Array(0, -1);
}

void Make_Array(int tar_idx, int pre){
	if(array_length <= 3 && tar_idx == array_length){
		Show_Array();
		recursive_end_flag = 1;
		return;
	}
	
	if(Deter_Good_Array(tar_idx)){
		if(tar_idx == array_length){
			Show_Array();
			recursive_end_flag = 1;
			return;
		}
	}
	else	return;
	
	for(int i = 1; i <= 3; i++){
		if(i == pre) continue;
		good_array[tar_idx] = i;
		Make_Array(tar_idx + 1, i);
		if(recursive_end_flag == 1) return;
	}
}

bool Deter_Good_Array(int cur_length){
	int pre_idx, cur_idx, same_num_flag;
	for(int i = 2; i <= cur_length / 2; i++){
		pre_idx = 0;
		cur_idx = 0;
		while(cur_idx + i <= cur_length){
			same_num_flag = 0;
			cur_idx = pre_idx + i;
			for(int j = 0; j < i; j++){
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

/*
필요길이의 수열을 만들고 좋은 수열인지 체크하는 것보다 만들면서 체크해서 미리 쳐내는게 훨씬 빠름.
*/
