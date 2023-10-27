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

  int n, t;
  cin >> n >> t;

  if (n <= 3) {
    cout << "IMPOSSIBLE";
    return 0;
  }

  vector<pii> nums(n);
  rep(i, 0, n) {
    cin >> nums[i].first;
    nums[i].second = i + 1;
  }

  sort(all(nums));

  for (auto i = nums.begin(); i != nums.end(); i++) {
    for (auto j = next(i); j != nums.end(); j++) {
      auto k = next(j), m = prev(nums.end());
      ll target = t - i->first - j->first;

      if (target <= 0) {
        continue;
      }

      while (k < m) {
        ll r = target - k->first - m->first;
        if (r > 0) {
          k++;
        } else if (r < 0) {
          m--;
        } else {
          cout << i->second << ' ' << j->second << ' ' << m->second << ' ' << k->second;
          return 0;
        }
      }
    }
  }


  cout << "IMPOSSIBLE";

}