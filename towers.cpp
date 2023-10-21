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

  multiset<int> towers;

  while (n--) {
    int x;
    cin >> x;

    auto it = towers.upper_bound(x);
    if (it != towers.end()) {
      towers.erase(it);
    }
    towers.insert(x);
  }

  cout << sz(towers);
}

