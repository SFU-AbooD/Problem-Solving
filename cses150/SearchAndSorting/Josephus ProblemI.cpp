//https://cses.fi/problemset/task/2162/

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
        int n;cin >> n;
        list<int>a;
        for(int i = 1;i <=n;i+=2)
            a.push_back(i);
        for(int i = 2;i <= n;i+=2)
            cout << i << sp;
        auto it = a.begin();
        if(!(n % 2))
                it++;
        while(it != a.end()&&a.size() != 0){
            cout << (*it) << sp;
            it = a.erase(it);
            if(it == a.end()){
                it = a.begin();
                    it++;
            }
            else if(++it == a.end())
                 it = a.begin();
        }
        if(a.size()>0)
            cout << *a.begin();
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