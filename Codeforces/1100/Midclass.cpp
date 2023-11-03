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
    int64_t a,b;cin >>a >> b;
    vector<int64_t>l(a);for(int64_t &e : l)cin >> e;
    sort(l.begin(),l.end());
    int size = l.size() - 1;
    double avg = 0;
    int count = 0;
    int ans = 0;
    while(--size >= 0)
    {
        if(l[size] >= b || (avg+l[size]) / (count + 1) >= b)
            {
                count++;
                avg+=l[size];
                ans++;
            }
        else break;
    }
    cout << ans << endl;
}
int main()
{
    fast();
    ll t{ 1 };cin >> t;
    // cin.ignore();
    while (t--)
    {
        solve();
    }
}
