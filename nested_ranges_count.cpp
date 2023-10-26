#include <bits/stdc++.h>
#include <bits/extc++.h>

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

using namespace __gnu_pbds;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
        tree_order_statistics_node_update>;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<vi> ranges(n, vi(3));
  vi contained(n), contains(n);
  Tree<pii> ends;
  rep(i, 0, n) {
    cin >> ranges[i][0] >> ranges[i][1];
    ranges[i][2] = i;
  }

  sort(all(ranges), [](auto &a, auto &b) {
      if (a[1] == b[1]) {
        return a[0] > b[0];
      }
      return a[1] < b[1];
  });

  for (auto &x: ranges) { // how many ranges x contains
    contains[x[2]] = sz(ends) - ends.order_of_key({x[0], 0});
    ends.insert({x[0], x[1]});
  }

  ends.clear();

  sort(all(ranges), [](auto &a, auto &b) {
      if (a[0] == b[0]) {
        return a[1] > b[1];
      }
      return a[0] < b[0];
  });

  for (auto &x: ranges) { // how many ranges contain x
    contained[x[2]] = sz(ends) - ends.order_of_key({x[1], 0});
    ends.insert({x[1], x[0]});
  }


  for (auto &x: contains) {
//    cout << (x > 0) << ' ';
    cout << x << ' ';
  }
  cout << '\n';
  for (auto &x: contained) {
//    cout << (x > 0) << ' ';
    cout << x << ' ';
  }
}