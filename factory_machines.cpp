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

  ll n, t;
  cin >> n >> t;

  vi times(n);
  for (auto &x: times) {
    cin >> x;
  }

  __int128 lo = 0, hi = LLONG_MAX;
  while (lo < hi) {
    __int128 mid = (lo + hi) / 2;

    __int128 total = 0;
    for (auto &x: times) {
      total += (mid / x);
    }

    if (total >= t) {
      hi = mid;
    } else if (total < t) {
      lo = mid + 1;
    }
  }

  cout << (ll)lo;
}