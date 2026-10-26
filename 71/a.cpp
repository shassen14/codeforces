
#include <bits/stdc++.h>
#include <string>

using namespace std;
using vi = vector<int>;

void solve() {
  std::string n;
  cin >> n;
  std::string answer;
  // Your code here
  if (n.size() <= 10) {
    answer = n;
  } else {
    answer = n[0] + std::to_string(n.size() - 2) + n[n.size() - 1];
  }
  cout << answer << "\n";
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
