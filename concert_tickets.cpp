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
  int n, m;
  cin >> n >> m;

  multiset<int> tix;
  rep(i, 0, n){
    int x;
    cin >> x;
    tix.insert(x);
  }

  rep(i, 0, m){
    int x;
    cin >> x;

    if(!sz(tix) || *tix.begin() > x){
      cout << -1 << '\n';
    }else{
      auto it = prev(tix.upper_bound(x));
      cout << *it << '\n';
      tix.erase(it);
    }
  }

}