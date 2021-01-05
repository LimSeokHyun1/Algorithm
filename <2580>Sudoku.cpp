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
int Classification(int x_pos, int y_pos);

int main(){
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cin >> sudoku_board[i][j];
			if(sudoku_board[i][j] == 0){
				blank_position[blank_cnt++] = make_pair(i, j);
			}
		}
	}
	Fill_Sudoku_Board(0);
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			cout << sudoku_board[i][j] << " ";
		} cout << endl;
	}
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

int Classification(int x_pos, int y_pos){
	if(x_pos < 3){
		if(y_pos < 3) return 0;
		else if(y_pos >= 3 && y_pos < 6) return 1;
		else return 2;
	}
	else if(x_pos >= 3 && x_pos < 6){
		if(y_pos < 3) return 3;
		else if(y_pos >= 3 && y_pos < 6) return 4;
		else return 5;
	}
	else{
		if(y_pos < 3) return 6;
		else if(y_pos >= 3 && y_pos < 6) return 7;
		else return 8;
		
	}
}

bool Judge_Valid_Num(int x_pos, int y_pos, int num){
	if(available_num[Classification(x_pos, y_pos)][num - 1] == 1){
		return false;
	}
	
	for(int i = 0; i < 9; i++){
		if(sudoku_board[x_pos][i] == num || sudoku_board[i][y_pos] == num){
			return false;
		}
	}
	
	return true;
}

void Fill_Sudoku_Board(int solving_blank){
	int x_pos = blank_position[solving_blank].first;
	int y_pos = blank_position[solving_blank].second;
	Find_Available_Num();
	
	if(solving_blank == blank_cnt){
		success_flag = 1;
		return;
	}

	for(int k = 1; k <= 9; k++){
		if(Judge_Valid_Num(x_pos, y_pos, k)){
			sudoku_board[x_pos][y_pos] = k;
			Fill_Sudoku_Board(++solving_blank);
			if(success_flag == 1) return;
		}
	}
}

/*
0 6 0 0 0 0 2 0 9
0 0 0 8 2 0 5 0 0
0 1 0 9 0 3 0 0 0
3 7 0 0 9 0 0 0 6
1 0 0 0 0 0 0 0 8
2 0 0 0 4 0 0 5 1
0 0 0 5 0 4 0 9 0
0 0 3 0 7 9 0 0 0
5 0 9 0 0 0 0 6 0
*/
