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
bool isSelfPalindrom(string &s)
{
    int t = s.size() - 1;
    for(int i = 0;i <= t / 2;i++)
        if(s[i] != s[t - i])
            return false;
    return true;
}
void solve()
{
    int64_t a,b;cin >>a >> b;
    map<string,int>map;
    string t;
    bool flag = false;
    int count = 0;
    string self = "";
    vector<string>left;
    vector<string>right;
    for(int i = 0 ;i < a; i++)
    {
        cin >> t;
        map[t]++;
    }
    for(auto &it : map)
    {
        if(it.second == 0)
            continue;
        string q = it.first;
        reverse(q.begin(),q.end());
        bool pali = false;
        int ans = min(map[q],it.second) * 2;
        if(isSelfPalindrom(q))
           {
             ans = it.second;
             pali = true;
           }
        if(ans == 0)
            continue;
        if(ans % 2 == 1)
        {
            if(!flag && pali)
            {
                flag = true;
                self  = q;
                count+=b;
                ans--;
            }
        }
        if(ans > 0)
        {
            for(int i = 0;i < ans / 2;i++)
            {
               left.push_back(it.first);
               right.push_back(q);
               count+=b * 2;
            }
        }
        map[q] = 0;
        it.second = 0;
    }
    cout << count << endl;
    if(count > 0)
    {
        for(auto it = left.rbegin();it != left.rend();it++)
            cout << *it;
        if(flag)cout << self;
        for(auto it = right.begin();it != right.end();it++)
            cout << *it;
    }
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
