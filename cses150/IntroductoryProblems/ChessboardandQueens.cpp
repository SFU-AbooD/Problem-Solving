//https://cses.fi/problemset/task/1624/
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
#define endl '\n'
#define sp ' '
#define pb push_back
#define assert(x,a) if(x){cout << a << endl;return;}
#define sortv(x)sort(x.begin(),x.end())
#define vbe(vec)    vec.begin(), vec.end()
#define po(x)       x.begin(),x.end()
#define revev(x)reverse(x.begin(),x.end())
const ll mod = 1000000007;
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
char board[8][8];
bool vis[10];
int ans = 0;
bool check()
{
    for(int i = 0;i < 8;i++)
    {
        for(int j = 0;j < 8;j++)
        {
            if(board[i][j] != 'q')
                continue;
            int tx = i+1;
            int ty = j+1;
            while(tx < 8 && ty < 8)
            {
                if(board[tx][ty] == 'q')
                    return false;
                tx++;
                ty++;
            }
            tx = i - 1;
            ty = j - 1;
            while(tx >= 0 && ty >= 0)
            {
                if(board[tx][ty] == 'q')
                    return false;
                tx--;
                ty--;
            }
            tx = i - 1;
            ty = j + 1;
            while(tx >= 0 && ty < 8)
            {
                if(board[tx][ty] == 'q')
                    return false;
                tx--;
                ty++;
            }
            tx = i + 1;
            ty = j - 1;
            while(ty >= 0 && tx < 8)
            {
                if(board[tx][ty] == 'q')
                    return false;
                tx++;
                ty--;
            }
        }
    }
    return true;
}
void dfs(int index)
{
    if(index == 8){
        if(check())
           {
                ans++;
                return;
           }
    else
        return;
    }
    for(int i = 0;i < 8;i++)
    {
        if(board[index][i] != '*' && vis[i] == false)
        {
            vis[i] = true;
            board[index][i] = 'q';
            dfs(index + 1);
            board[index][i] = '.';
            vis[i] = false;
        }
    }
}
void solve()
{
    memset(vis,false,sizeof vis);
    for(int i = 0;i < 8;i++)
    {
        for(int j = 0;j < 8;j++)
        {
            cin >> board[i][j];
        }
    }
    dfs(0);
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