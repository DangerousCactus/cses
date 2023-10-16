#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  cin >> s;

  unordered_map<char, int> m;
  for (char &c: s) {
    m[c]++;
  }

  int odds = 0;
  for (auto &[k, v]: m) {
    odds += v % 2;
  }

  string out(sz(s), ' ');
  int a = 0, b = sz(s) - 1;

  if (sz(s) % 2 == 0) {
    if (odds) {
      cout << "NO SOLUTION";
    } else {
      for (auto &[k, v]: m) {
        rep(i, 0, v / 2) {
          out[a++] = out[b--] = k;
        }
      }
    }
  } else {
    if (odds > 1) {
      cout << "NO SOLUTION";
    } else {
      for (auto &[k, v]: m) {
        if(v % 2){
          out[sz(s) / 2] = k;
          v--;
        }
        rep(i, 0, v / 2) {
          out[a++] = out[b--] = k;
        }
      }
    }
  }
  cout << out;
}