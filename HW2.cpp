#include <iostream>

using namespace std;

int main()
{
    //cout << "Hello world!" << endl;
    int num;
    cin >> num;
    long *ptr = NULL;
    //int Dim = 0;
    //int arr[1000000];
    ptr = new long[num];
    for(int i =0; i < num;i++){
        long input;
        cin >> input;
        *(ptr + i) = input;
    }
    /*for(int i =0; i < num;i++){
        cout << ptr[i] << endl;
    }*/

    long max_sum = 0, sum = 0;
    int start = 0, end = 0, temp_start = 0;

    for (int i=0; i<num; ++i)
    {
        sum += ptr[i];

        if (sum < 0)
        {
            sum = 0;
            temp_start = i+1;   // 重新設定起點是下一個數字
        }

        if (sum > max_sum)
        {
            max_sum = sum;
            start = temp_start;
            end = i;
        }
    }

    /*if (start > end)
        cout << "什麼數字都不取";
    else
        cout << "從" << start << "到" << end;
    */
    if (max_sum > 0){
        cout <<max_sum;
    }
    else{
        cout << 0;
    }


    return 0;
}
