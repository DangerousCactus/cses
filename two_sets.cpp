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

  ll total = n * (n + 1) / 2;
  if (total % 2) {
    cout << "NO";
    exit(0);
  }

  cout << "YES\n";

  vi out1;
  ll total1 = 0;
  int i = n;
  int skip = -1;
  while (total1 + i < total / 2) {
    out1.push_back(i);
    total1 += i--;
  }

  if (total1 != total / 2) {
    out1.push_back(total / 2 - total1);
    skip = out1.back();
  }

  cout << sz(out1) << '\n';
  for (auto &x: out1)
    cout << x << ' ';
  cout << '\n';
  cout << n - sz(out1) << '\n';

  i = 0;
  ll total2 = 0;
  while (total2 != total / 2) {
    i++;
    if (i == skip) {
      continue;
    }
    total2 += i;
    cout << i << ' ';
  }
}