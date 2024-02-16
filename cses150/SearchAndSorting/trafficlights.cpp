//https://cses.fi/problemset/task/1163/

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <string>
#include <iostream>
#include <map>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;
typedef long long int_64;
typedef long long ll;
const ll mod = 1000000007;
using ull = unsigned long long;
#define endl '\n'
#define sp ' '
#define pb push_back
#define assert(x, a) if (x) {cout << a << endl;return;}
#define sortv(x) sort(x.begin(), x.end());
#define vb(vec) vec.begin(), vec.end()
inline void fast() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
}
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
  return (a * b) / gcd(a, b);
}
int a,b;
template < typename T > void debug(vector < T > & l) {
  for (auto & it: l) cout << it << sp;
  cout << endl;
}
void solve() {
    ll a,b;cin >>a >> b;
    map<ll,bool>kk;
    kk[0] = true;
    kk[a] = true;
    vector<ll>tl(b);for(ll &e : tl)cin >> e;
    vector<ll>tl_temp = tl;
    vector<ll>answers(b);
    int index = b - 1;
    sort(vb(tl_temp));
    for(int i = 0 ;i < b;i++)
        kk[tl[i]] = true;
    ll best_vv= tl_temp[0];
    for(int i = 0;i < b - 1;i++)
        best_vv = max(best_vv,tl_temp[i + 1] - tl_temp[i]);
    best_vv = max(best_vv,a - tl_temp.back());
    for(int i = 0;i < b;i++){
        answers[index--] = best_vv;
        auto it = kk.find(tl.back());
        auto it_before = it;
        auto it_after = it;
        it_before--;
        it_after++;
        best_vv = max(best_vv,it_after->first - it_before->first);
        kk.erase(it);
        tl.pop_back();
    }
    for(ll &e : answers)
        cout << e << sp;
}
int main() {
  fast();
  ll t {
    1
  }; // cin >> t;
  // cin.ignore();
  while (t--) {
    solve();
  }
}
