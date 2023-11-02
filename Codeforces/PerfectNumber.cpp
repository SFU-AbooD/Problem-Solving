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
bool sum10(int x)
{
    int sum = 0;
    while(x != 0)
    {
        sum+=x%10;
        x/=10;
    }
    return sum == 10;
}
void solve()
{
    int64_t a;cin >> a;
    int64_t b=  19;
    for(int i = 1;i != a;)
    {
        b++;
        if(sum10(b))
            {
                i++;
            }
    }
    cout << b << endl;

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
