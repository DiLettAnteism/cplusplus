#include <bits/stdc++.h>
using namespace std;

bool check(int x0, int y0, int x1, int y1) {
	return (x0 == x1 && y0 == y1) ||
		   (x0 == x1-2 && y0 == y1-1) ||
		   (x0 == x1-2 && y0 == y1+1) ||
		   (x0 == x1+2 && y0 == y1-1) ||
		   (x0 == x1+2 && y0 == y1+1) ||
		   (x0 == x1-1 && y0 == y1-2) ||
		   (x0 == x1-1 && y0 == y1+2) ||
		   (x0 == x1+1 && y0 == y1-2) ||
		   (x0 == x1+1 && y0 == y1+2) ;
}

int main() {
	// P点坐标为(x, y)，定义A点能够到达P点的路径条数为dp[x][y]
	// dp[x][y] = dp[x-1][y] + dp[x][y-1]

	int n, m;
	int x, y;
	cin >> n >> m >> x >> y;
	vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));
	dp[0][0] = 1;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (i == 0 && j == 0) continue;
			if (check(i, j, x, y)) {
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = (i-1 >= 0 ? dp[i-1][j] : 0) + (j-1 >= 0 ? dp[i][j-1] : 0);
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}