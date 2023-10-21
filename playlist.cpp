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

  queue<int> q;
  set<int> seen;

  int ans = 0;

  while (n--) {
    int x;
    cin >> x;

    while (seen.count(x)) {
      seen.erase(q.front());
      q.pop();
    }

    q.push(x);
    seen.insert(x);
    ans = max(ans, sz(q));
  }

  cout << ans;
}