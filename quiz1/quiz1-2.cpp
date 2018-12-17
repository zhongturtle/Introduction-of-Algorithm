#include <bits/stdc++.h>
using namespace std;


int matrix[500][500];
int value[100][100];
//int local_value = 1;

int main(){
    int n ,k;
    cin >> n >>k;
    int v1, v2;
    for (int i = 1; i <= k ; i++){
        cin >> v1 >> v2;
        matrix[v1][v2] = 1;
        matrix[v2][v1] = 1;
    }
    /*for (int i = 1; i <= n ; i++){
        for (int j = 1; j <= n ; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << "Alice wins\n";
}
