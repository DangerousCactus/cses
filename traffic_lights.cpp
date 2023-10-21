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

  int x, n;
  cin >> x >> n;

  set<int> lights{0, x};

  priority_queue<pii> pq; //len, start
  pq.emplace(x, 0);

  while (n--) {
    int p;
    cin >> p;

    auto it = lights.insert(p).first;
    pq.emplace(*next(it) - p, p);
    pq.emplace(p - *prev(it), *prev(it));

    auto outdated = [&]() {
        auto [d, s] = pq.top();
        auto it = lights.find(s);
        auto ne = next(it);

        return (*ne - *it) != d;
    };

    while (outdated()) {
      pq.pop();
    }

    cout << pq.top().first << ' ';
  }
}