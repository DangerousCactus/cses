#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

set<pii> blocked;

bool collide(vector<pii> &board, pii q) {
  for (auto &[x, y]: board) {
    if (x == q.first || y == q.second) {
      return true;
    }

    if (abs(x - q.first) == abs(y - q.second)) {
      return true;
    }
  }

  if(blocked.count(q)){
    return true;
  }

  return false;
}

ll solve(int n, vector<pii> &board) {
  if (n == 8) {
    return 1;
  }

  ll total = 0;

  rep(i, 0, 8) {
    if(!collide(board, {n, i})){
      board.emplace_back(n, i);
      total += solve(n + 1, board);
      board.pop_back();
    }
  }

  return total;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  rep(i, 0, 8) {
    rep(j, 0, 8) {
      char c;
      cin >> c;
      if (c == '*') {
        blocked.emplace(i, j);
      }
    }
  }

  vector<pii> board;
  cout << solve(0, board);
}