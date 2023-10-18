#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll pw(ll b, ll p) {
  if (p == 0) {
    return 1;
  } else if (p == 1) {
    return b;
  } else {
    return pw(b, p / 2) * pw(b, p / 2) * pw(b, p % 2);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int q;
  cin >> q;

  while (q--) {
    ll n;
    cin >> n;

    int digits = 1;
    ll i = 9, total = 0;
    while (total + i * digits < n) {
      total += i * digits++;
      i *= 10;
    }

    ll num = (n - (total + 1)) / digits + pw(10, digits - 1);
    ll idx = (n - (total + 1)) % digits;
    // numth ct digit number

    cout << (num / pw(10, digits - idx - 1)) % 10 << '\n';
  }
}