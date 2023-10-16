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

  int t;
  cin >> t;

  while (t--) {
    ll a, b;
    cin >> a >> b;
    ll mx = max(a, b);
    ll total = mx * (mx - 1) + 1;

    if (a != mx) {
      if (mx % 2 == 0) {
        total -= (mx - a);
      } else {
        total += (mx - a);
      }
    }
    if (b != mx) {
      if (mx % 2 == 0) {
        total += mx - b;
      } else {
        total -= mx - b;
      }
    }

    cout << total << '\n';
  }


}