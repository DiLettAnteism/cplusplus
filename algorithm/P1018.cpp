#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
vector<int> pro;
vector<int> idx;

void to_vec(string &num, int start, int end, vector<int> &b) {
	b.resize(end - start);
	for (int i = start, j = 0; i < end; ++i) {
		b[j++] = num[i] - '0';
	}
}

void cmp(vector<int> &ans, vector<int> &b) {
	if (ans.size() > b.size()) return;
	else if (ans.size() < b.size()) {
		ans = b;
	} else {
		for (int i = 0; i < ans.size(); ++i) {
			if (ans[i] > b[i]) break;
			else if (ans[i] < b[i]) {
				ans = b;
				break;
			}
		}
	}
}

void product(vector<int> &a, vector<int> &b) {
	vector<int> temp(55, 0);
	for (int i = b.size() - 1, j = 54; i >= 0; --i, --j) {
		for (int k = a.size() - 1; k >= 0; --k) {
			temp[j + k - a.size() + 1] += (a[k] * b[i]);
		}
	}
	int carry = 0;
	int i = 0;
	for (; i < 55; ++i) {
		if (temp[i] != 0) break;
	}
	int index = i;
	i = 54;
	while (i >= index || carry != 0) {
		temp[i] += carry;
		carry = temp[i] / 10;
		temp[i] %= 10;
		--i;
	}
	a.resize(54 - i);
	for (int j = 0; j < a.size(); ++j) {
		a[j] = temp[i + 1];
		++i;
	}
}

void dfs(string &num, int K, int cur, int cnt) {
	if (cnt >= K) {
		to_vec(num, 0, idx[0], pro);
		for (int i = 0; i < K - 1; ++i) {
			vector<int> temp;
			to_vec(num, idx[i], idx[i + 1],  temp);
			product(pro, temp);
		}
		vector<int> temp;
		to_vec(num, idx[K - 1], num.size(), temp);
		product(pro, temp);
		cmp(ans, pro);
		return;
	}
	if (cur >= num.size()) return;
	idx.push_back(cur);
	dfs(num, K, cur + 1, cnt + 1);
	idx.pop_back();
	dfs(num, K, cur + 1, cnt);
}

int main() {
	int N, K;
	cin >> N >> K;
	string num;
	cin >> num;
	dfs(num, K, 1, 0);
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i];
	}
	cout << endl;
	return 0;
}