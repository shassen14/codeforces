#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using ll = long long;

class SegTree {
public:
  SegTree(int n) : m_array_size(n) { m_tree = vector<int>(4 * n, 0); }

  int Query(int left, int right) {
    return query(1, 0, m_array_size - 1, left, right);
  }

  void Update(int position, int value) {
    update(1, 0, m_array_size - 1, position, value);
  }

private:
  // tree_i represents the range from lo - hi
  // left and right are query range
  int query(int tree_i, int lo, int hi, int left, int right) {
    // outside the range
    if (lo > right || hi < left) {
      return 0;
    }

    // completely in the range
    if (left <= lo && hi <= right) {
      return m_tree[tree_i];
    }

    int mid = lo + (hi - lo) / 2;

    int left_contribution = query(tree_i * 2, lo, mid, left, right);
    int right_contribution = query(tree_i * 2 + 1, mid + 1, hi, left, right);

    return left_contribution + right_contribution;
  }

  //  0 - 2, 3-5
  //  0    -     5,6 - 11
  // [-2,1,2,3,4,5.... 100]  points
  // [0, 0,0,1,0,0,....  0] people standing there
  //                        3.     3         3
  //.   tree index , || low end and high end query range, person
  void update(int tree_i, int lo, int hi, int p_i, int new_val) {
    if (lo == hi) {
      m_tree[tree_i] = new_val;
      return;
    }

    int mid = lo + (hi - lo) / 2;

    if (p_i <= mid) {
      update(tree_i * 2, lo, mid, p_i, new_val);
    } else {
      update(tree_i * 2 + 1, mid + 1, hi, p_i, new_val);
    }
    m_tree[tree_i] = m_tree[tree_i * 2] + m_tree[tree_i * 2 + 1];
  }

  vector<int> m_tree;
  size_t m_array_size;
};

vector<int> sorted_endpoints(vector<pii> &people) {
  vector<int> points(people.size(), 0);
  sort(people.begin(), people.end());
  for (size_t i = 0; i < people.size(); i++) {
    points[i] = people[i].second;
  }
  return points;
}
void solve() {
  int number_of_people;
  cin >> number_of_people;

  // get all the people's begin and end points
  vector<pii> people(number_of_people);
  for (int i = 0; i < number_of_people; i++) {
    int begin, end;
    cin >> begin >> end;
    people[i] = {begin, end};
  }

  // sort by begin points and get end points
  vector<int> endpoints = sorted_endpoints(people);

  // sort the endpoints by ends for the segtree
  vector<int> new_ends = endpoints;
  sort(new_ends.begin(), new_ends.end());

  // create the compression
  // [5,6,8,9,10,100]
  unordered_map<int, int> end_to_idx;
  for (int i = 0; i < new_ends.size(); i++) {
    end_to_idx[new_ends[i]] = i;
  }

  // Create Segtree for only endpoints
  SegTree segs(new_ends.size());

  ll total_greetings = 0;

  // query and update via end points sorted by beginning points
  // [100,8,6,9,5,10]

  for (int i = 0; i < endpoints.size(); i++) {
    int mapped_index = end_to_idx[endpoints[i]];

    ll value = segs.Query(mapped_index, endpoints.size() - 1);

    // cout << mapped_index << " " << endpoints[i] << " " << value << "\n";

    // query 1 over until the end to find how many people are ahead
    total_greetings += value;

    // then update to show that we
    segs.Update(mapped_index, 1);

    // int new_val = segs.Query(mapped_index, mapped_index);
    // cout << "what is this updated value: " << new_val << "\n";
  }

  cout << total_greetings << "\n";
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
