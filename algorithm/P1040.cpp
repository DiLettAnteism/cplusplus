#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &root, int i, int j) {
	if (i > j) {
		return;
	} else if (i == j) {
		cout << root[i][i] << " ";
		return;
	}
	cout << root[i][j] << " ";
	print(root, i, root[i][j] - 1);
	print(root, root[i][j] + 1, j);
}

int main() {
	int n;
	cin >> n;
	vector<vector<long long>> f(n + 1, vector<long long>(n + 1, 0));
	vector<vector<int>> root(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; ++i) {
		cin >> f[i][i];
		root[i][i] = i;
	}
	// 区间长度从2递增到n
	for (int len = 2; len <= n; ++len) {
		for (int i = 1; i + len - 1 <= n; ++i) { // 若i + len - 1 > n,则[i, n]的区间长度小于len,在前面讨论过了，可以直接跳过
			// f[i][j] = max(f[i][k - 1] * f[k + 1][j] + f[k][k])
			int j = i + len - 1; // [i, j]的长度为len

			if (f[i + 1][j] + f[i][i] > f[i][j]) { // 左子树为空
				f[i][j] = f[i + 1][j] + f[i][i];
				root[i][j] = i;
			}

			for (int k = i + 1; k <= j - 1; ++k) { // 左子树与右子树均不为空
				if (f[i][k - 1] * f[k + 1][j] + f[k][k] > f[i][j]) {
					f[i][j] = f[i][k - 1] * f[k + 1][j] + f[k][k];
					root[i][j] = k;
				}
			}

			if (f[i][j - 1] + f[j][j] > f[i][j]) { // 右子树为空
				f[i][j] = f[i][j - 1] + f[j][j];
				root[i][j] = j;
			}
		}
	}
	cout << f[1][n] << endl;
	print(root, 1, n);
	return 0;
}