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

  int n, x;
  cin >> n >> x;

  vi p(n);
  for (auto &z: p) {
    cin >> z;
  }

  sort(all(p));
  deque<int> d(all(p));

  int t = 0;
  while (sz(d) > 1) {
    t++;
    if (d.front() + d.back() <= x) {
      d.pop_front();
    }
    d.pop_back();
  }
  cout << t + sz(d);
}