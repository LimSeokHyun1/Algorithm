#include <iostream>

using namespace std;

int sudoku_board[9][9];
int available_num[9][9];	// 3x3
int blank_cnt = 0;
int success_flag = 0;
pair<int, int> blank_position[81];

void Fill_Sudoku_Board(int solving_blank);
bool Judge_Valid_Num(int x_pos, int y_pos, int num);
void Find_Available_Num();

int main(){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cin >> sudoku_board[i][j];
			if(sudoku_board[i][j] == 0){
				blank_position[blank_cnt++] = make_pair(i, j);
			}
		}
	}
	Find_Available_Num();
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cout << available_num[i][j] << " ";
		} cout << endl;
	}
	//Fill_Sudoku_Board(0);
}

void Find_Available_Num(){
	int x = 0, y = 0;
	for(int a = 0; a < 9; a++){
		if(a >= 1){	
			x++;
			if(a % 3 == 0){
				x = 0;
				y++;
			}
		}
		for(int i = 3 * y; i < 3 * (y + 1); i++){
			for(int j = 3 * x; j < 3 * (x + 1); j++){
				if(sudoku_board[i][j] != 0)
					available_num[a][sudoku_board[i][j] - 1] = 1;
			}
		}
	}
}

void Fill_Sudoku_Board(int solving_blank){
		
	int x_pos = blank_position[solving_blank].first;
	int y_pos = blank_position[solving_blank].second;
	
	if(solving_blank == blank_cnt){
		success_flag = 1;
		return;
	}

	for(int k = 1; k <= 9; k++){
		if(Judge_Valid_Num(x_pos, y_pos, k)){
			sudoku_board[x_pos][y_pos] = k;
			Fill_Sudoku_Board(++solving_blank);
		}
		if(success_flag == 1) return;
	}
}

bool Judge_Valid_Num(int x_pos, int y_pos, int num){
	/*
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cout << sudoku_board[i][j] << " ";
		} cout << endl;
	}*/
	
	return true;
}
