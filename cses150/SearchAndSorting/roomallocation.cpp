//https://cses.fi/problemset/task/1164/


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
#include <list>
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
        ll a;cin >>a;
        int index = 0;
        vector<pair<pair<ll,ll>,ll>>pairs(a);for(auto &e : pairs){
        cin >> e.first.first >> e.first.second;
        e.second  = index++;
        }
        sort(vb(pairs));
        map<pair<ll,ll>,ll>maps;
        vector<int>ans(a);
        int mx = 1;
        int rev = 1000000;
        for(auto &i : pairs){
                auto it = maps.lower_bound({i.first.first,rev});
                if(it == maps.begin()){
                    maps[{i.first.second,rev--}] = mx++;
                    ans[i.second] = mx - 1;
                }
                else{
                      it--;
                      ans[i.second] = it->second;
                      maps.erase(it);
                      maps[{i.first.second,rev--}] =  ans[i.second];
                }
        }
        cout << mx  - 1<< endl;
        for(auto &it : ans)cout << it << sp;
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
