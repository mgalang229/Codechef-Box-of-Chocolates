#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		// input
		int n;
		cin >> n;
		vector<int> w(n);
		for (int i = 0; i < n; i++) {
			cin >> w[i];
		}
		
		// find the maximum number
		int mx = 0;
		for (int i = 0; i < n; i++) {
			mx = max(w[i], mx);
		}
		
		// find the length of the subarrays that don't contain the maximum number
		vector<int> v;
		for (int i = 0, j = 0; i < n; i = j) {
			if (w[i] == mx) {
				++j;
				continue;
			}
			for (; j < n && w[j] ^ mx; j++);
			v.push_back(j - i);
		}
		
		// first and last subarrays might be connected
		if (w[0] ^ mx && w[n - 1] ^ mx) {
			v[0] += v.back();
			v.pop_back();
		}
		
		// calculate the answer
		int ans = 0;
		for (int vi : v) {
			ans += max(vi - n / 2 + 1, 0);
		}
		cout << ans << '\n';
	}
	return 0;
}
