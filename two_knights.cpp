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

  ll n;
  cin >> n;

  vi ans{0, 6, 28, 96};

  function<ll(int)> solve = [&](int x) -> ll {
      if (x < 5) {
        return ans[x - 1];
      }

      ll total = 0;
      ll x2 = x * x;
      total += 4 * (x2 - 3);
      total += 8 * (x2 - 4);
      total += 4 * (x - 4) * (x2 - 5);
      total += 4 * (x2 - 5);
      total += 4 * (x - 4) * (x2 - 7);
      total += (x2 - 16 - 8 * (x - 4)) * (x2 - 9);

      return total / 2;
  };

  rep(i, 1, n + 1) {
    cout << solve(i) << '\n';
  }
}