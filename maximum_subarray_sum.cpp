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

  vector<ll> nums(n);
  for (auto &x: nums) {
    cin >> x;
  }
  ll ans = *max_element(all(nums));
  ll total = 0;

  for (auto &x: nums) {
    total += x;
    ans = max(ans, total);
    if (total < 0) {
      total = 0;
    }
  }

  cout << ans;

}

