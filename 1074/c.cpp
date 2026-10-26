
#include <bits/stdc++.h>
#include <limits>

using namespace std;
using vi = vector<int>;

void solve() {
  int n;
  cin >> n;
  // Your code here
  // choose an x that would make a max
  // MEX(vec)
  // sort everything and find the longest continuous numbers
  // 6, 7, 8 ... -11,-10,-9,-8
  vi nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  std::sort(nums.begin(), nums.end());
  nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

  int answer = 1;
  int cur = 1;

  for (int i = 1; i < n; i++) {
    if (nums[i] == nums[i - 1] + 1) {
      cur++;
    } else {
      cur = 1;
    }
    answer = std::max(answer, cur);
  }

  std::cout << answer << '\n';
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
