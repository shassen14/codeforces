
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cout << i;
    if (i != n) {
      std::cout << " ";
    }
  }
  std::cout << '\n';
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
