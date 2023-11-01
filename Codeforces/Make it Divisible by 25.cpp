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
    string s;cin >> s;
    int sz = s.size()- 1;
    int ans = INT_MAX;
    for(int i = sz;i>0;i--)
    {
        if(s[i] == '0')
        {
            if(s[i - 1] == '0')
                ans = min(ans,sz - i);
            else{
                for(int j = i - 1;j>=0;j--)
                    if(s[j] == '5' || s[j] == '0')
                        {
                               ans = min(ans,(sz - i) + (i - j - 1));
                               break;
                        }
            }
        }
        else if(s[i] == '5')
        {
              for(int j = i - 1;j>=0;j--)
                   if(s[j] == '7' || s[j] == '2')
                      {
                               ans = min(ans,(sz - i) + (i- j - 1));
                               break;
                     }
        }
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