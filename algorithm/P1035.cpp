#include <bits/stdc++.h>
using namespace std;

int main() {
	int k;
	cin >> k;
	double Sn = 0;
	int n = 0;
	while ((Sn - k) < 1e-12) {
		++n;
		Sn += 1.0 / n;
	}
	cout << n << endl;
	return 0;
}