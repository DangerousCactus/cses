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

  if (n <= 2) {
    cout << "IMPOSSIBLE";
    return 0;
  }

  vector<pii> nums(n);
  rep(i, 0, n) {
    cin >> nums[i].first;
    nums[i].second = i + 1;
  }

  sort(all(nums));

  auto i = nums.begin();
  auto j = next(i);

  for (auto i = nums.begin(); i != nums.end(); i++) {
    for (auto j = next(i); j != nums.end(); j++) {
      auto k = lower_bound(next(j), nums.end(), pii{t - i->first - j->first, -1});

      if (k != nums.end() && (i->first + j->first + k->first == t)) {
        cout << i->second << ' ' << j->second << ' ' << k->second;
        return 0;
      }
    }
  }


  cout << "IMPOSSIBLE";

}