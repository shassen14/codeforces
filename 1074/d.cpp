
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

void solve() {
  int n;
  int m;
  int h;
  cin >> n >> m >> h;

  vi nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  vi original = nums;
  vi last_update(n, -1);

  std::vector<vi> ops(m, vi(2));
  for (int i = 0; i < m; i++) {
    // 1 index, and value
    cin >> ops[i][0] >> ops[i][1];
    ops[i][0]--;
  }

  int last_crash = -1;

  for (int i = 0; i < m; i++) {
    int index = ops[i][0];
    int op = ops[i][1];

    if (last_update[index] < last_crash) {
      nums[index] = original[index];
    }

    nums[index] += op;
    last_update[index] = i;

    if (nums[index] > h) {
      last_crash = i;
      nums[index] = original[index];
    }
  }

  for (int i = 0; i < n; i++) {
    if (last_update[i] < last_crash) {
      nums[i] = original[i];
    }
    std::cout << nums[i] << ' ';
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
