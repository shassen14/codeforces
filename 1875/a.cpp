
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using ll = long long;

void solve() {
  int a, b, n;
  cin >> a >> b >> n;

  ll total = b;

  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    if (val < a) {
      total += val;
    } else {
      total += a - 1;
    }
  }

  cout << total << "\n";
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
