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

  vi indexes(n);
  rep(i, 0, n){
    int x;
    cin >> x;

    indexes[x - 1] = i;
  }

  int ct = 1;

  rep(i, 1, n){
    if(indexes[i] < indexes[i - 1]){
      ct++;
    }
  }

  cout << ct;
}