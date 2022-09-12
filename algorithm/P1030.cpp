#include <bits/stdc++.h>
using namespace std;

void print(string &postorder, int idx, string &inorder, int l, int r) {
	if (l > r) return;
	// 打印根节点
	cout << postorder[idx];
	if (l == r) return;
	int root_idx;
	for (int i = l; i <= r; ++i) {
		if (inorder[i] == postorder[idx]) {
			root_idx = i;
			break;
		}
	}
	// 打印左子树
	print(postorder, idx - (r - root_idx) - 1, inorder, l, root_idx - 1);
	// 打印右子树
	print(postorder, idx - 1, inorder, root_idx + 1, r);
}

int main() {
	string inorder, postorder;
	cin >> inorder >> postorder;
	print(postorder, postorder.size() - 1, inorder, 0, inorder.size() - 1);
	cout << endl;
	return 0;
}