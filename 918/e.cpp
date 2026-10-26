
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  set<ll> seen;
  seen.insert(0);

  ll sum = 0;

  vector<int> nums(n);

  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    nums[i] = num;
  }

  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      sum += nums[i];
    } else {
      sum -= nums[i];
    }

    if (seen.contains(sum)) {
      cout << "YES\n";
      return;
    }

    seen.insert(sum);
  }

  cout << "NO\n";
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
