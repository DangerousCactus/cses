#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int n = 9;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  cin >> s;

  vector<pair<char, pii>> moves{{'L', {-1, 0}},
                                {'D', {0,  1}},
                                {'R', {1,  0}},
                                {'U', {0,  -1}}};

  bool board[n][n] = {{false}};

  function<int(int, int, int)> solve = [&](int x, int y, int m) -> int {
      if (x == 1 && y == n - 2) {
        return (m == (n - 2) * (n - 2));
      }

      int total = 0;

      for (auto &[c, d]: moves) {
        if (s[m - 1] == '?' || s[m - 1] == c) {
          int newX = x + d.first, newY = y + d.second;
          if (!board[newX][newY]) {
            if (board[newX + d.first][newY + d.second]) {
              if (!board[newX + d.second][newY + d.first] && !board[newX - d.second][newY - d.first]) {
                continue;
              }
            }

            board[newX][newY] = true;
            total += solve(newX, newY, m + 1);
            board[newX][newY] = false;
          }
        }
      }

      return total;
  };

  rep(i, 0, n) {
    board[0][i] = board[i][0] = board[n - 1][i] = board[i][n - 1] = true;
  }
  board[1][1] = true;
  cout << solve(1, 1, 1);
}

