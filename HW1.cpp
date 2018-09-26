#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    //cout << "Hello world!" << endl;
    string in;
    cin >> in;
    //cout << int(in[3]);
    int arr[26] ;
    for(int i =0;i<26;i++){
        arr[i] = 0;
    }
    //cout << arr[25];
    int string_len = in.length();
    //cout << string_len;
    int type = 0;
    for (int i = 0;i< string_len;i++){
        //cout << i << in[i];
        if(arr[int(in[i]) - 65] == 0){
            type ++;
        }
        arr[int(in[i]) - 65] ++;
        //cout << int(in[i]) - 65 << endl;
    }
    //cout << type <<endl;
    /*for (int i = 0;i < 26;i++){
        cout << arr[i] << endl;
    }*/
    //cout << endl;
    for (int i = 0;i < type;i++){
        //cout << arr[i] << endl;
        int max_index = 0;
        for (int j = 0;j < 26; j++){
            if (arr[j] > arr[max_index]){
                max_index = j;
            }
        }
        cout << max_index+65 <<" "<<arr[max_index] <<endl;
        arr[max_index] = 0;
    }
    //cout << "Max element Index: " << max_element(arr, arr + 26) - arr;
    return 0;
}
