#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll n;

struct Mod {
    ll x;

    Mod() : x(0) {}

    Mod(ll xx) {
      if (xx >= 0 || xx % n == 0) {
        x = xx % n;
      } else {
        x = n + (xx % n);
      }
    }
//    Mod(ll xx) : x(xx) {}

    Mod operator+(Mod b) { return Mod((x + b.x) % n); }

    Mod operator-(Mod b) { return Mod((x - b.x + n) % n); }

    Mod operator*(Mod b) { return Mod((x * b.x) % n); }

};

int main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n;

  vector<Mod> nums(n);
  for (auto &x: nums) {
    int z;
    cin >> z;
    x = Mod(z);
  }

  vector<Mod> partial(n);
  partial_sum(all(nums), partial.begin());

  map<ll, int> m;
  for (auto &z: partial) {
    m[z.x]++;
  }

  ll ans = m[0];

  rep(i, 0, n) {
    auto z = partial[i].x;
    m[z]--;
    ans += m[z];
  }

  cout << ans;
}