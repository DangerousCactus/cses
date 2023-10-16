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

  char last = 0;
  int ct = 0, mx = 0;

  for (auto c: s) {
    if (c == last) {
      ct++;
    } else {
      mx = max(mx, ct);
      last = c;
      ct = 1;
    }
  }

  mx = max(mx, ct);

  cout << mx;
}