//https://cses.fi/problemset/task/1073/
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
map<ll,int>keys;
void solve() {
    int n;cin >> n;
    int towers = 0;
    for(int i = 0;i < n;i++){
        ll a;cin >> a;
        auto it = keys.upper_bound(a);
        if(it== keys.end()){
            towers++;
            keys[a]++;
        }
        else
        {
            if(it->second == 1)
                keys.erase(it);
            else
                it->second--;
            keys[a]++;
        }
    }
    cout << towers;
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