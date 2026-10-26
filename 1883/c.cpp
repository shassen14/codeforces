
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> nums;
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    nums.push_back(val);
  }

  // base case
  int min_mod = 5;
  int count_evens = 0;
  for (const int num : nums) {
    if (num % 2 == 0) {
      count_evens++;
    }

    int val = (k - (num % k)) % k;
    min_mod = min(min_mod, val);
  }

  // special
  if (k == 4) {
    if (count_evens >= 2) {
      min_mod = 0;
    } else {
      min_mod = min(min_mod, 2 - count_evens);
    }
  }

  cout << min_mod << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
