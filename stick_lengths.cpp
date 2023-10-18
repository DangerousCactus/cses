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

  vector<ll> sticks(n);
  for (auto &x: sticks) {
    cin >> x;
  }

  sort(all(sticks));
  ll avg = sticks[n / 2];
  ll avg2 = sticks[n / 2 - 1];

  ll total = 0, total2 = 0;

  for (auto &x: sticks) {
    total += abs(avg - x);
    total2 += abs(avg2 - x);
  }

  cout << min(total, total2);
}