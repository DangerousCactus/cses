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

  int n;
  cin >> n;

  vector<ll> apples(n);
  for (auto &x: apples) {
    cin >> x;
  }

  ll total = accumulate(all(apples), 0LL);
  ll mn = LLONG_MAX;

  rep(i, 0, 1 << n) {
    ll temp = 0;
    rep(j, 0, n) {
      if (i & (1 << j)) {
        temp += apples[j];
      }
    }
    mn = min(mn, abs(total - 2 * temp));
  }

  cout << mn;
}