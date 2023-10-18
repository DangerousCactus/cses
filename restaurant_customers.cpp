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
  map<int, bool> m;

  rep(i, 0, n) {
    int a, b;
    cin >> a >> b;

    m[a] = true;
    m[b] = false;
  }

  int c = 0;
  int ans = 0;

  for (auto &[k, v]: m) {
    if (v) {
      c++;
    } else {
      c--;
    }
    ans = max(ans, c);
  }
  cout << ans;

}