
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

void solve() {
  int n;
  cin >> n;
  // array size
  int num;
  int max_num = 0;
  for (int i = 0; i < n; i++) {
    cin >> num;
    max_num = std::max(max_num, num);
  }

  // we swap the max number to the beginning
  // so we can add it every time
  std::cout << max_num * n << "\n";
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
