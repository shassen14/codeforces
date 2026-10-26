
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using ll = long long;

struct State {
  ll total;
  int town;
  int bike;

  bool operator>(const State &other) const { return total > other.total; }
};

void solve() {
  int nodes, edges;
  cin >> nodes >> edges;

  unordered_map<int, vector<pair<int, int>>> town_map;

  for (int i = 0; i < edges; i++) {
    int town1, town2, dist;
    cin >> town1 >> town2 >> dist;

    town_map[town1].push_back({town2, dist});
    town_map[town2].push_back({town1, dist});
  }

  vector<int> bikes(nodes + 1);

  for (int i = 1; i <= nodes; i++) {
    int val;
    cin >> val;
    bikes[i] = val;
  }

  int slowest_bike = *max_element(bikes.begin(), bikes.end());
  ll inf = std::numeric_limits<ll>::max();
  vector<vector<ll>> distances(nodes + 1, vector<ll>(slowest_bike + 1, inf));

  priority_queue<State, vector<State>, greater<State>> states;
  states.push(State(0, 1, bikes[1]));

  while (!states.empty()) {
    auto [total, town, bike] = states.top();
    states.pop();

    if (town == nodes) {
      cout << total << "\n";
      return;
    }

    if (distances[town][bike] != inf) {
      continue;
    }

    distances[town][bike] = total;

    bike = min(bike, bikes[town]);

    for (const auto &[neighbor, dist] : town_map[town]) {
      ll new_total = total + (bike * dist);

      // if (new_total >= distances[neighbor][best_bike]) {
      //   continue;
      // }
      //

      states.push(State(new_total, neighbor, bike));
    }
  }

  // never get here
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
