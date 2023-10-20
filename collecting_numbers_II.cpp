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

  vi idx(n), num(n); //index of a number, number at an index
  rep(i, 0, n) {
    int x;
    cin >> x;

    idx[x - 1] = i;
    num[i] = x - 1;
  }

  int ct = 1;

  rep(i, 1, n) {
    if (idx[i] < idx[i - 1]) {
      ct++;
    }
  }

  rep(i, 0, m) {
    int a, b;
    cin >> a >> b;
    a--, b--;

    int curr = 0;

    for (auto x: {num[a], num[b]}) {
      if (x > 0) {
        curr -= idx[x] < idx[x - 1];
      }
      if (x < n - 1) {
        curr -= idx[x] > idx[x + 1];
      }
    }

    if (abs(num[a] - num[b]) == 1) {
      curr += idx[min(num[a], num[b])] > idx[max(num[a], num[b])];
    }

    swap(num[a], num[b]);
    swap(idx[num[a]], idx[num[b]]);

    for (auto x: {num[a], num[b]}) {
      if (x > 0) {
        curr += idx[x] < idx[x - 1];
      }
      if (x < n - 1) {
        curr += idx[x] > idx[x + 1];
      }
    }

    if (abs(num[a] - num[b]) == 1) {
      curr -= idx[min(num[a], num[b])] > idx[max(num[a], num[b])];
    }

    ct += curr;
    cout << ct << '\n';
  }


}