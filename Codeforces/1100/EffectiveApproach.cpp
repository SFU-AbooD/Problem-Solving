//https://codeforces.com/problemset/problem/227/B
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
    vector<int64_t> v(a);for(int64_t &e : v)cin >> e;
    map<int64_t,int64_t>vesya;
    map<int64_t,int64_t>petya;
    int64_t vesya_com = 0;
    int64_t petya_com = 0;
    for(int i = 1;i <=a;i++)
    {
        if(vesya[v[i - 1]] == 0)
            vesya[v[i - 1]]  = i;
    }
    for(int i = a;i >=1;i--)
    {
        if(petya[v[i - 1]] == 0)
            petya[v[i - 1]]  = a - (i - 1);
    }
    int q;cin >> q;
    while(q--)
    {
        int64_t tt;cin >> tt;
        vesya_com+=vesya[tt];
        petya_com+=petya[tt];
    }
    cout << vesya_com << sp << petya_com;

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
