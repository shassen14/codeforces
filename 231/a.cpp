
#include <bits/stdc++.h>
#include <numeric>

using namespace std;
using vi = vector<int>;

bool solve() {
  vi n(3);
  for (int i = 0; i < 3; i++) {
    cin >> n[i];
  }
  int val = std::accumulate(n.begin(), n.end(), 0);
  return val >= 2;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  int answer = 0;
  while (t--) {
    if (solve()) {
      answer++;
    };
  }

  std::cout << answer << '\n';

  return 0;
}
