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

  vector<pii> m;

  rep(i, 0, n) {
    int a, b;
    cin >> a >> b;
    m.emplace_back(a, b);
  }

  sort(all(m));
  vi DP(n + 1, -1);
  DP.back() = 0;

  function<int(int)> solve = [&](int i) -> int {
      if (DP[i] != -1) {
        return DP[i];
      }

      auto it = lower_bound(all(m), pii{m[i].second, 0});
      return DP[i] = max(solve(i + 1), 1 + solve(distance(m.begin(), it)));
  };

  int ans = 0;
  rep(i, 0, n) {
    ans = max(ans, solve(i));
  }
  cout << ans;

}