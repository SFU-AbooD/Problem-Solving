//https://cses.fi/problemset/task/2431/
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
typedef long long int_64;
typedef long long ll;
const ll mod = 1000000007;
using ull = unsigned long long;
#define endl '\n'
#define sp ' '
#define pb push_back
#define assert(x,a) if(x){cout << a << endl;return;}
#define sortv(x)sort(x.begin(),x.end());
#define vb(vec)    vec.begin(), vec.end()
inline void fast() {
    std::ios_base::sync_with_stdio(false);
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
    for (auto& it : l)cout << it << sp;
    cout << endl;
}
ull ans = 0;
ull bin(ull& length, ull& start, ull& total, ull& v)
{
    ull low = start;
    ull high = (start * 10) - 1;
    while (low <= high)
    {
        ull mid = (low + high) / 2;
        ull ans = (((mid - low) * length) + total);
        if (ans <= v && ans + (length - 1) >= v)
        {
            v -= ans;
            ::ans = mid;
            return mid;
        }
        if (ans < v)
        {
            total += ans - total + length;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return 5;
}
void solve()
{
    int q; cin >> q;
    while (q--)
    {
        ull v; cin >> v;
        ull length = 1;
        ull start = 1;
        ull total = 1;
        while (v >= total + ((start * 10) - start) * length)
        {
            total += ((start * 10) - start) * length;
            length++;
            start *= 10;
        }
        bin(length, start, total, v);
        string cc = to_string(ans);
        cout << cc[v] << endl;
    }
}
int main()
{
    fast();
    ll t{ 1 };// cin >> t;
    // cin.ignore();
    while (t--)
    {
        solve();
    }
}