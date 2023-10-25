#include <bits/stdc++.h>
#include <bits/extc++.h>

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
        tree_order_statistics_node_update>;


int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k;
  cin >> n >> k;

  Tree<int> t;
  rep(i, 1, n + 1){
    t.insert(i);
  }

  int curr = 0;
  while(sz(t)){
    curr = (curr + k) % sz(t);
    auto it = t.find_by_order(curr);
    cout << *it << ' ';
    t.erase(it);
  }
}