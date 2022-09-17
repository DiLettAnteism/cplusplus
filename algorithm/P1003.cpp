#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> input(n, vector<int>(4));
	for (int i = 0; i < n; ++i) {
		cin >> input[i][0] >> input[i][1] >> input[i][2] >> input[i][3];
	}
	int x, y;
	cin >> x >> y;
	int output = -1;
	for (int i = 0; i < n; ++i) {
		if (x >= input[i][0] && x <= input[i][0] + input[i][2] && y >= input[i][1] && y <= input[i][1] + input[i][3]) {
			output = i + 1;
		}
	}
	cout << output << endl;
	return 0;
}