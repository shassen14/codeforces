
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using ll = long long;

void solve() {
  vector<string> lines(3);
  for (int i = 0; i < 3; i++) {
    cin >> lines[i];
  }
  // iterate thru lines with freq_map
  unordered_map<char, int> freq_map;
  for (const auto &line : lines) {
    for (const char c : line) {
      freq_map[c]++;
    }
  }

  for (const auto &[letter, freq] : freq_map) {
    if (freq == 2) {
      cout << letter << "\n";
    }
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
