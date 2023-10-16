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

  int t;
  cin >> t;

  while (t--) {
    int a, b;
    cin >> a >> b;
    if (a < b) {
      swap(a, b);
    }

    int diff = a - b;
    a -= 2 * diff;
    b -= diff;

    if (a >= 0 && a == b && a % 3 == 0) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << '\n';
  }
}