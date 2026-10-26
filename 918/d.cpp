
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using ll = long long;

bool is_vowel(const char letter) { return letter == 'e' || letter == 'a'; }

void solve() {
  int n;
  cin >> n;

  string word;

  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    word += c;
  }

  // bacednab
  //       ^
  //        ^^

  string final = "";

  for (int i = 0; i < n; i++) {
    string syllable = "";

    // consonant
    syllable += word[i];
    i++;
    // vowel
    syllable += word[i];

    // should i add third or nah?
    if (i + 1 < n && i + 2 < n && !is_vowel(word[i + 1]) &&
        !is_vowel(word[i + 2])) {
      i++;
      syllable += word[i];
    } else if (i + 2 == n) {
      i++;
      syllable += word[i];
    }

    if (i != n - 1) {
      syllable += '.';
    }
    final += syllable;
  }

  cout << final << "\n";
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
