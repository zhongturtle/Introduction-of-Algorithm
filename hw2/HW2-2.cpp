#include <bits/stdc++.h>
using namespace std;

int value[2][10000] = {0};
int ans[10000];
string s1 ,s2;

int calculate_value(int length, int i){
    memset(value[i % 2], 0, sizeof(value[i % 2]));
    int max_value;
    for (int j = 1; j <= length; j ++) {

        max_value = max(value[!(i % 2)][j], value[i % 2][j - 1]);
        value[i % 2][j] = max_value;
        if (s1[i - 1] != s2[j - 1]){
            continue;
        }
        else if (s1[i - 1] == s2[j - 1]){
            max_value = max(value[i % 2][j], value[!(i % 2)][j - 1] + 1);
            value[i % 2][j] = max_value;

        }
    }
    return value[i % 2][length + 1 - i];
}


int main() {
	cin >> s1;
	s2 = s1;
	//cout << s2;
	reverse(s2.begin(), s2.end());
	int length = s1.size();

	for (int i = 1; i <= length; i ++) {
		ans[i] = calculate_value(length, i) * 2 - 1 ;
	}

	for (int i = 1; i <= length; i ++)
		cout << ans[i] << ' ';


	cout << '\n';
}
