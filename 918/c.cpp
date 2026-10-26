
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using ll = long long;

void solve() {
  int n;
  cin >> n;

  ll sum = 0;

  for (int i = 0; i < n; i++) {
    ll val;
    cin >> val;

    sum += val;
  }

  ll sqrt_sum = round(sqrt(sum));

  if (sqrt_sum * sqrt_sum == sum) {
    cout << "YES\n";
  } else {

    cout << "NO\n";
  }
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
