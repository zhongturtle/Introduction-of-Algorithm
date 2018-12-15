#include <bits/stdc++.h>
using namespace std;


int matrix[100][100];
int value[100][100];
int local_value = 1;


int cal_valid(int n , int k, int value){
    int valid_local = 0;
    if(matrix[0][0] != 1){
        valid_local = 0;
    }
    if((matrix[n+1][k] == value) || matrix[n][k+1] == value){
        valid_local = 1;
    }
    else if((matrix[n+1][k] == (value + 1)) || matrix[n][k+1] == (value +1)){
        valid_local = 1;
        local_value += 1;
    }
    else{
        valid_local = 0;
    }
    if(valid_local){
        return 1;
    }
    else{
        return 0;
    }
}
int cal_use(int r ,int c){
    memset(value, 0, sizeof(value));
    /*cout << "value" <<endl;
    for (int i = 0; i < r; i ++){
        for (int j = 0; j < c; j ++){
            cout << value[i][j] << " ";
        }
        cout << "\n";
	}
    cout << "value" <<endl;*/

    for (int i = 0; i < r; i ++){
        for (int j = 0; j < c; j ++){
            if(i == 0 && j > 0){
                /*if(matrix[i][j] >= matrix[i-1][j]){
                    value[i][j] = 1;
                }
                else*/ if( ( (matrix[i][j] == matrix[i][j-1]) && (value[i][j -1] != 0) ) || ( (matrix[i][j] == matrix[i][j-1] + 1) && (value[i][j-1] != 0)  ) ){
                    value[i][j] = 1;
                }
            }
            else if(j == 0 && i > 0){
                if( ( (matrix[i][j] == matrix[i-1][j]) && (value[i-1][j] != 0) ) || ( (matrix[i][j] == matrix[i-1][j] + 1) && (value[i-1][j] != 0) )  ){
                    value[i][j] = 1;
                }
                /*else if(matrix[i][j] <= matrix[i][j+1]){
                    value[i][j] = 1;
                }*/
            }
            else if(i == 0 && j == 0){
                if(matrix[i][j] == 1){
                    value[i][j] = 1;
                }
            }
            else{
                if( ( (matrix[i][j] == matrix[i-1][j]) && (value[i-1][j] != 0) ) || ( (matrix[i][j] == matrix[i-1][j] + 1) && (value[i-1][j] != 0) )  ){
                    value[i][j] = 1;
                }
                else if( ( (matrix[i][j] == matrix[i][j-1]) && (value[i][j -1] != 0) ) || ( (matrix[i][j] == matrix[i][j-1] + 1) && (value[i][j-1] != 0)  ) ){
                    value[i][j] = 1;
                }
            }



        }
	}
    /*cout << "value" <<endl;

	for (int i = 0; i < r; i ++){
        for (int j = 0; j < c; j ++){
            cout << value[i][j] << " ";
        }
        cout << "\n";
	}*/
}

/*int path_valid(int v_r, int v_c){
    for(int i = 0; i < v_r ; i++){
        for(int j = 0; j < v_c ;j++){
           if(i == 0 && j > 0) {
              value[i][j] = value[i][j-1] + value[i][j]
           }
        }
    }



}*/
int main() {
    int n ,k;
	cin >> n >>k;
	memset(matrix, 0, sizeof(matrix));
	for (int i = 0; i < n; i ++){
        for (int j = 0; j < k; j ++){
            cin >> matrix[i][j];
        }
	}
	cal_use(n , k);
	if (value[n-1][k-1] && matrix[0][0] == 1 && matrix[n-1][k-1] == 7){
        cout << "Yes\n";
	}
	else{
        cout << "No\n";
	}

}
