#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int n;
vi arr;
vi dpinc;
vi dpdec;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n;
	arr = vi(n);

	dpinc = vi(n, 1);
	dpdec = vi(n, 1);

	for (auto&& x : arr) {
		cin >> x;
	}

	auto ans = int{ 1 };
	for (auto i = 1; i < n; ++i) {
		if (arr[i - 1] <= arr[i]) {
			dpinc[i] = dpinc[i - 1] + 1;
			ans = max(ans, dpinc[i]);
		}

		if (arr[i] <= arr[i - 1]) {
			dpdec[i] = dpdec[i - 1] + 1;
			ans = max(ans, dpdec[i]);
		}
	}

	cout << ans;

	return 0;
}