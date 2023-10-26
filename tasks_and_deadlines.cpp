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

  vector<pii> tasks(n);
  for(auto &x : tasks){
    cin >> x.first >> x.second;
  }

  sort(all(tasks));

  ll reward = 0;
  ll time = 0;

  for(auto & x : tasks){
    time += x.first;
    reward += x.second - time;
  }

  cout << reward;
}