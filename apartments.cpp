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

  int n, m, k;
  cin >> n >> m >> k;

  vi p(n), a(m);
  for (auto &x: p) {
    cin >> x;
  }
  for (auto &x: a) {
    cin >> x;
  }

  sort(all(p));
  sort(all(a));

  int i = 0, j = 0, t = 0;
  while (i < n && j < m) {
    if (a[j] >= p[i] - k && a[j] <= p[i] + k) {
      i++, j++, t++;
    } else if (p[i] - k > a[j]) {
      j++;
    } else if (p[i] + k < a[j]) {
      i++;
    }
  }

  cout << t;
}