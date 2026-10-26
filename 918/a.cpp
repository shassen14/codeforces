
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using ll = long long;

void solve() {
  int a, b, c;
  cin >> a >> b >> c;

  if (a == b) {
    cout << c << "\n";
  } else if (b == c) {
    cout << a << "\n";
  } else {
    cout << b << "\n";
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
