
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using ll = long long;

void solve() {
  int num;
  cin >> num;
  vector<int> nums;
  for (int i = 0; i < 4; i++) {
    int digit = num % 10;
    num /= 10;
    nums.push_back(digit);
  }

  ranges::reverse(nums);

  int total = 4;
  int first_val = nums[0] == 0 ? 10 : nums[0];
  total += abs(1 - first_val);

  for (int i = 0; i < 3; i++) {
    int val1 = nums[i] == 0 ? 10 : nums[i];
    int val2 = nums[i + 1] == 0 ? 10 : nums[i + 1];

    total += abs(val2 - val1);
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
