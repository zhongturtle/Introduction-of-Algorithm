#include <bits/stdc++.h>
using namespace std;


int matrix[1000][1000];
int value[1000][1000];


int cal_value(int k ,int n) {
    int diff = 0;
	memset(value, 0, sizeof(value));
	value[0][0] = 1;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			if (i){
                diff = abs(matrix[i][j] - matrix[i - 1][j]);
                if(diff <= k){
                    value[i][j] |= value[i - 1][j];
                }
		    }
			if (j){
			    diff = abs(matrix[i][j] - matrix[i][j - 1]);
                if(diff <= k){
                    value[i][j] |= value[i][j - 1];
                }
			}
		}
	}
	return value[n - 1][n - 1];
}

int main() {
    int n;
	cin >> n;
	for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            cin >> matrix[i][j];
        }
	}
	int left = -1, right = 1e8, med;
	while (right - left > 1) {
		med = (left + right) / 2;
		if (cal_value(med , n) ){
            right = med;
		}
		else{
            left = med;
		}
	}
	cout << right << '\n';
}
