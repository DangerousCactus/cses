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

  if(n == 1){
    cout << 1;
    exit(0);
  }

  if(n <= 3){
    cout << "NO SOLUTION";
    exit(0);
  }

  for(int i = 2; i <= n; i += 2){
    cout << i << ' ';
  }
  for(int i = 1; i <= n; i += 2){
    cout << i << ' ';
  }
}