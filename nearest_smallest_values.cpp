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

  map<int, int> m;

  rep(i, 1, n + 1) {
    int x;
    cin >> x;

    auto it = m.lower_bound(x);
    if (it == m.begin()) {
      cout << 0 << ' ';
    } else {
      cout << prev(it)->second << ' ';
    }

    m[x] = i;

    it = m.find(x);
    while(next(it) != m.end() && next(it)->second < it->second){
      m.erase(next(it));
    }
  }
}