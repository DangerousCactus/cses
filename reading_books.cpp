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

  vector<ll> books(n);
  for(auto & x : books){
    cin >> x;
  }

  ll mx = *max_element(all(books));
  ll total = accumulate(all(books), 0LL);

  if(2 * mx >= total){
    cout << 2 * mx;
  }else{
    cout << total;
  }
}