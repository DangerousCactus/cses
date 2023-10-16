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

  int n, out = 0;
  cin >> n;

  rep(i, 0, n - 1){
    int x;
    cin >> x;
    out ^= x ^ i;
  }

  out ^= (n - 1) ^ n;

  cout << out;
}