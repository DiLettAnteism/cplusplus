#include <bits/stdc++.h>
using namespace std;

vector<int> handler(string &s) {
	int i = 0;
	int n = s.size();
	int coefficient = 0;
	int sum = 0;
	while (i < n) {
		if (s[i] == '+' || s[i] == '-') {
			bool plus = (s[i] == '+' ? true : false);
			++i;
			if (s[i] >= 'a' && s[i] <= 'z') {
				if (plus) coefficient += 1;
				else coefficient -= 1;
				++i;
				continue;
			}
			int temp = 0;
			while (s[i] >= '0' && s[i] <= '9') {
				temp = temp * 10 + s[i] - '0';
				++i;
			}
			if (s[i] >= 'a' && s[i] <= 'z') {
				if (plus) coefficient += temp;
				else coefficient -= temp;
				++i;
			} else {
				if (plus) sum += temp;
				else sum -= temp;
			}
		} else if (s[i] >= '0' && s[i] <= '9') {
			int temp = 0;
			while (s[i] >= '0' && s[i] <= '9') {
				temp = temp * 10 + s[i] - '0';
				++i;
			}
			if (s[i] >= 'a' && s[i] <= 'z') {
				coefficient += temp;
				++i;
			} else {
				sum += temp;
			}
		} else {
			coefficient += 1;
			++i;
		}
	}
	return {coefficient, sum};
}

int main() {
	string equation;
	cin >> equation;
	int idx;
	char ch;
	bool find1 = false, find2 = false;
	int n = equation.size();
	for (int i = 0; i < n; ++i) {
		if (equation[i] == '=') {
			idx = i;
			find1 = true;
			if (find1 && find2) break;
		} else if (equation[i] >= 'a' && equation[i] <= 'z') {
			ch = equation[i];
			find2 = true;
			if (find1 && find2) break;
		}
	}
	string left = equation.substr(0, idx);
	string right = equation.substr(idx + 1);
	const vector<int> &ret1 = handler(left);
	const vector<int> &ret2 = handler(right);
	int leftCoefficient = ret1[0];
	int leftSum = ret1[1];
	int rightCoefficient = ret2[0];
	int rightSum = ret2[1];
	int sum = rightSum - leftSum;
	int coefficient = leftCoefficient - rightCoefficient;
	if (abs(sum) == 0) {
		printf("%c=%.3lf\n", ch, 0.000);
		return 0;
	}
	printf("%c=%.3lf\n", ch, 1.0 * sum / coefficient); //保留三位小数输出
	return 0;
}