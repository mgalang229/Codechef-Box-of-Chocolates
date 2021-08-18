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
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		
		// find the maximum element
		int mx = *max_element(a.begin(), a.end());
		
		// find the length of the subarrays that don't contain the maximum element
		vector<int> sizes;
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] != mx) {
				count++;
			} else {
				sizes.emplace_back(count);
				count = 0;
			}
		}
		
		// first and last subarrays might be connected
		if (count != 0) {
			sizes[0] = (count + sizes[0]);
		}
		
		// calculate the result
		int result = 0;
		for (int i = 0; i < (int) sizes.size(); i++) {
			result += max(sizes[i] - n / 2 + 1, 0);
		}
		cout << result << '\n';
	}
	return 0;
}
