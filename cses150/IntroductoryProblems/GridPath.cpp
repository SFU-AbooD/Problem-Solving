//https://cses.fi/problemset/task/1625/
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
bool vis[7][7];
ll counter = 0;
ll inside = 0;
ull ans = 0;
void discover(string& path, int index, int x, int y)
{
    int x2, x3 = x2 = 0;
    if (!((y + 1 > 6) || vis[x][y + 1]))
        x3++;
    if (!((x + 1 > 6)|| vis[x + 1][y]))
        x2++;
    if (!((y - 1 < 0)|| vis[x][y - 1]))
        x3++;
    if (!((x - 1 < 0)|| vis[x - 1][y]))
        x2++;
    if ((x2 == 0 && x3 == 2) || (x3 == 0 && x2 == 2))
        return;
    vis[x][y] = true;
    counter++;
    if ((x)+(6 - y) == 0 && counter < 49)
    {
        vis[x][y] = false;
        counter--;
        return;
    }
    if (counter == 49)
    {
        vis[x][y] = false;
        ans++;
        counter--;
        return;
    }
    if (path[index] == '?')
    {
        if(!((x - 1 < 0)|| vis[x - 1][y]))
        discover(path, index + 1, x - 1, y);
          if (!((x + 1 > 6)|| vis[x + 1][y]))
        discover(path, index + 1, x + 1, y);
          if (!((y - 1 < 0) || vis[x][y - 1]))
        discover(path, index + 1, x, y - 1);
         if (!((y + 1 > 6)|| vis[x][y + 1]))
        discover(path, index + 1, x, y + 1);
    }
    else
        if (path[index] == 'L')
            {
            if(!((x - 1 < 0)|| vis[x - 1][y]))
                discover(path, index + 1, x - 1, y);
            }
        else if (path[index] == 'R')
        {
            if (!((x + 1 > 6)|| vis[x + 1][y]))
                discover(path, index + 1, x + 1, y);
        }
        else if (path[index] == 'D')
        {
            if (!((y + 1 > 6)|| vis[x][y + 1]))
                discover(path, index + 1, x, y + 1);
        }
        else
        {
           if (!((y - 1 < 0) || vis[x][y - 1]))
                discover(path, index + 1, x, y - 1);
        }
    vis[x][y] = false;
    counter--;
}
void solve()
{
    memset(vis, false, sizeof vis);
    string path; cin >> path;
    discover(path, 0, 0, 0);
    cout << ans;
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
