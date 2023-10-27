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

  ll n, x;
  cin >> n >> x;

  vector<ll> nums(n);
  for (auto &z: nums) {
    cin >> z;
  }

  vector<ll> partial(n);
  partial_sum(all(nums), partial.begin());

  map<ll, int> m;
  for (auto &z: partial) {
    m[z]++;
  }

  ll ans = 0;
  ans += m[x];

  rep(i, 0, n) {
    auto z = partial[i];
    m[partial[i]]--;
    ans += m[x + z];
  }

  cout << ans;
}