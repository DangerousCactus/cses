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

  vi a(n);
  for(auto & x : a){
    cin >> x;
  }

  ll total = 0;
  rep(i, 1, n){
    total += max(0, a[i - 1] - a[i]);
    a[i] = max(a[i], a[i - 1]);
  }

  cout << total;
}