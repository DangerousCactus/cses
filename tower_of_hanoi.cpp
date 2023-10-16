#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


void hanoi(int start, int end, int size) {
  int mid = 1 ^ 2 ^ 3 ^ start ^ end;
  if (size != 1) {
    hanoi(start, mid, size - 1);
  }
  cout << start << ' ' << end << '\n';
  if (size != 1) {
    hanoi(mid, end, size - 1);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  // to solve for size N:
  // move size N-1 to peg 2
  // Move largest from 1 to 3
  // move size N-1 to peg 3
  int n;
  cin >> n;
  cout << pow(2, n) - 1 << '\n';

  hanoi(1, 3, n);
}