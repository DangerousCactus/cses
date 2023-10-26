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

    vector<vi> c(n, vi(3));
    vi rooms(n);
    rep(i, 0, n){
      cin >> c[i][0] >> c[i][1];
      c[i][2] = i;
    }

    sort(all(c));

    set<int> r{1};
    priority_queue<pii, vector<pii>, greater<>> pq;
    for(auto & x : c){
      while(sz(pq) && pq.top().first < x[0]){
        r.insert(pq.top().second);
        pq.pop();
      }

      if(!sz(r)){
        r.insert(sz(pq) + 1);
      }

      rooms[x[2]] = *r.begin();
      pq.emplace(x[1], *r.begin());
      r.erase(r.begin());

    }


    cout << *max_element(all(rooms)) << '\n';
    for(auto & x : rooms){
      cout << x << ' ';
    }

}