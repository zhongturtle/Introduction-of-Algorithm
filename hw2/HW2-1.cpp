#include <bits/stdc++.h>
using namespace std;

int n;
int input_map[1000][1000];
int value_map[1000][1000];

int calculate_value(int k) {
	memset(value_map, 0, sizeof(value_map));
	value_map[0][0] = 1;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			if (!i && !j) continue;
			if (i && abs(input_map[i][j] - input_map[i - 1][j]) <= k)
				value_map[i][j] |= value_map[i - 1][j];
			if (j && abs(input_map[i][j] - G[i][j - 1]) <= k)
				value_map[i][j] |= value_map[i][j - 1];
		}
	}
	return dp[n - 1][n - 1];
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++){
		for (int j = 0; j < n; j ++){
			cin >> input_map[i][j];
    }
  }

	

	cout << R << '\n';
}

