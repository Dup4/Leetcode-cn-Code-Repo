#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define mkp make_pair
#define all(x) (x).begin(), (x).end()
using db = double;
using ll = long long;
using ull = unsigned long long;
using pII = pair<int, int>;
using pLL = pair<ll, ll>;
constexpr int mod = 1e9 + 7;
template <class T1, class T2>
inline void chadd(T1 &x, T2 y, int Mod = mod) {
    x += y;
    while (x >= Mod) x -= Mod;
    while (x < 0) x += Mod;
}
template <class T1, class T2>
inline void chmax(T1 &x, T2 y) {
    if (x < y)
        x = y;
}
template <class T1, class T2>
inline void chmin(T1 &x, T2 y) {
    if (x > y)
        x = y;
}
inline int nextInt() {
    int x;
    cin >> x;
    return x;
}
void rd() {}
template <class T, class... Ts>
void rd(T &arg, Ts &...args) {
    cin >> arg;
    rd(args...);
}
#define dbg(x...)                             \
    do {                                      \
        cout << "\033[32;1m" << #x << " -> "; \
        err(x);                               \
    } while (0)
void err() {
    cout << "\033[39;0m" << endl;
}
template <class T, class... Ts>
void err(const T &arg, const Ts &...args) {
    cout << arg << ' ';
    err(args...);
}
template <template <typename...> class T, typename t, typename... A>
void err(const T<t> &arg, const A &...args) {
    for (auto &v : arg) cout << v << ' ';
    err(args...);
}
void ptt() {
    cout << endl;
}
template <class T, class... Ts>
void ptt(const T &arg, const Ts &...args) {
    cout << ' ' << arg;
    ptt(args...);
}
template <class T, class... Ts>
void pt(const T &arg, const Ts &...args) {
    cout << arg;
    ptt(args...);
}
void pt() {}
template <template <typename...> class T, typename t, typename... A>
void pt(const T<t> &arg, const A &...args) {
    for (int i = 0, sze = arg.size(); i < sze; ++i) cout << arg[i] << " \n"[i == sze - 1];
    pt(args...);
}
inline ll qpow(ll base, ll n) {
    assert(n >= 0);
    ll res = 1;
    while (n) {
        if (n & 1)
            res = res * base % mod;
        base = base * base % mod;
        n >>= 1;
    }
    return res;
}
// head
constexpr int N = 1e5 + 10;
// int n;
map<int, int> f;

int dfs(int x) {
    if (x == 0)
        return 0;
    if (x == 1)
        return 1;
    if (f.count(x))
        return f[x];
    int now = x;
    if (x % 2 == 0)
        chmin(now, dfs(x / 2) + 1);
    if (x % 3 == 0)
        chmin(now, dfs(x / 3) + 1);
    if (x % 2 == 1)
        chmin(now, dfs((x - 1) / 2) + 2);
    if (x % 3 == 1)
        chmin(now, dfs((x - 1) / 3) + 2);
    if (x % 3 == 2)
        chmin(now, dfs((x - 2) / 3) + 3);
    return f[x] = now;
}

class Solution {
public:
    int minDays(int n) {
        f.clear();
        return dfs(n);
        //	int res = n;
        //	int it = 1, now = 1;
        //	while (it < n) {
        //
        //	}
        //	return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif