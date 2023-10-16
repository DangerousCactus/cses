#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<string> gray(int n) {
  if (n == 1) {
    return {"0", "1"};
  } else {
    auto temp = gray(n - 1);
    vector<string> out;
    for (auto &x: temp) {
      out.push_back("0" + x);
    }
    for (auto it = temp.rbegin(); it != temp.rend(); it++) {
      out.push_back("1" + *it);
    }
    return out;
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  for (auto &x: gray(n)) {
    cout << x << '\n';
  }
}