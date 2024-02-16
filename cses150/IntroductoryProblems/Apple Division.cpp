//https://cses.fi/problemset/task/1623

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
#define endl '\n'
#define sp ' '
const int64_t mod = 10e9+7;
using namespace std;
inline void fast() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}
ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return (a * b) / gcd(a, b);
}
template<typename T>void debug(vector<T>& l)
{
    int x = l.size();
    for (int i = 0;i < x;i++)cout << l[i] << sp;
    cout << endl;
}
vector<ll>subsets;
vector<ll>elem;
ll ans= 0;
ll sum = 0;
void solve()
{
    int n;cin >> n;
    elem.resize(n);
    ans = 10000000007;
    for(ll &e : elem){cin >> e;sum+=e;}
    if(n == 1)
    {
        cout << elem[0];
        return;
    }
    for(int i =1;i < (1 << elem.size()) - 1;i++)
    {
        ll sum2 = 0;
        for(int j = 0;j < n;j++)
        {
 
            if(i & (1 << j))
            {
                sum2+=elem[j];
            }
        }
        ans = min(ans,abs((sum - sum2) - sum2));
    }
    cout << ans;
}
int main()
{
    fast();
    ll t{ 1 };//cin >> t;
    // cin.ignore();
    while (t--)
    {
        solve();
    }
}