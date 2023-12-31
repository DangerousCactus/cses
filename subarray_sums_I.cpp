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

  int n, x;
  cin >> n >> x;

  queue<int> q;
  int sum = 0;
  int ans = 0;

  rep(i, 0, n) {
    int c;
    cin >> c;

    q.push(c);
    sum += c;

    while (sum > x) {
      sum -= q.front();
      q.pop();
    }

    if (sum == x) {
      ans++;
    }
  }

  cout << ans;
}