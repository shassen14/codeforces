#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using ll = long long;

class UnionFind {
public:
  UnionFind(int num_nodes) {
    m_parents = vector<int>(num_nodes + 1, 0);
    std::iota(m_parents.begin(), m_parents.end(), 0);

    m_scores = vector<int>(num_nodes + 1, 0);
  }

  int Find(int x) {
    if (m_parents[x] != x) {
      m_parents[x] = Find(m_parents[x]);
    }

    return m_parents[x];
  }

  void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    m_parents[x] = y;
  }

  std::vector<int> m_parents;
  std::vector<int> m_scores;
};

void solve(UnionFind &uf) {
  string query;
  cin >> query;

  if (query == "get") {
    int node;
    cin >> node;
    cout << uf.m_scores[node] << "\n";
  } else if (query == "join") {
    int x;
    int y;
    cin >> x >> y;
    uf.Union(x, y);
  } else if (query == "add") {
    int x;
    int val;
    cin >> x >> val;
  }

  // Your code here
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int num_players;
  int t;
  cin >> num_players >> t;

  UnionFind uf(num_players);

  while (t--) {
    solve(uf);
  }
}
