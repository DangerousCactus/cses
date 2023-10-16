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

  const int mod = 1E9 + 7;
  ll ans = 1;

  int n;
  cin >> n;

  rep(i, 0, n) {
    ans <<= 1;
    ans %= mod;
  }

  cout << ans;
}