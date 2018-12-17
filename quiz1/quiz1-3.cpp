#include <bits/stdc++.h>
using namespace std;


int A[1000][1000];
int B[1000][1000];
int C[1000][1000];
//int local_value = 1;

int main(){
    int n ;
    cin >> n;
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n ; j ++){
            cin >> A[i][j];
        }
    }
    //cout << "finish A\n";
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n ; j ++){
            cin >> B[i][j];
        }
    }
    /*cout << endl;
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n ; j ++){
            cout << A[i][j] << " ";
        }
        cout <<endl;
    }
    cout << endl;
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n ; j ++){
            cout << B[i][j] << " ";
        }
        cout <<endl;
    }*/
    for(int i= 0; i< n ;i++){
        for(int j= 0;j <n;j++){
            int sum = 0;
            for(int a =0 ; a< n ;a ++){
                sum = sum + A[i][a]*B[a][j];
            }
            C[i][j] = sum;
        }
    }
    //cout << endl;
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n ; j ++){
            cout << C[i][j] << " ";
        }
        cout <<endl;
    }
}
