//https://codeforces.com/problemset/problem/463/B
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
void solve()
{
    int64_t a;cin >> a;
    vector<int64_t>l(a);for(int64_t &e : l)cin >> e;
    int64_t money = l[0];
    int64_t energy = 0;
    for(int i = 0;i < a - 1;i++)
    {
        if(l[i] < l[i + 1])
        {
            if(energy + l[i] < l[i + 1])
               {
                money+=abs((l[i] + energy) - l[i + 1]);
                energy = 0;
               }
           else
             energy = (energy + l[i]) - l[i + 1];
        }
        else
            energy+=l[i] - l[i + 1];
    }
    cout << money;
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
