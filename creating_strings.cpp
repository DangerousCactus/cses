#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int fact(int x){
  if(x <= 1){
    return 1;
  }

  return x * fact(x - 1);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  cin >> s;

  map<char, int> st;
  for(auto & c : s){
    st[c]++;
  }

  int total = fact(sz(s));
  for(auto & [k, v] : st){
    total /= fact(v);
  }
  cout << total << '\n';

  sort(all(s));
  do{
    cout << s << '\n';
  }while(next_permutation(all(s)));
}