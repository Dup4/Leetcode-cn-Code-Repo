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
using pII = pair <int, int>;
using pLL = pair <ll, ll>;
constexpr int mod = 1e9 + 7;
template <class T1, class T2> inline void chadd(T1 &x, T2 y, int Mod = mod) { x += y; while (x >= Mod) x -= Mod; while (x < 0) x += Mod; } 
template <class T1, class T2> inline void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template <class T1, class T2> inline void chmin(T1 &x, T2 y) { if (x > y) x = y; }
inline int nextInt() { int x; cin >> x; return x; }
void rd() {}
template <class T, class... Ts> void rd(T& arg, Ts&... args) { cin >> arg; rd(args...); }
#define dbg(x...) do { cout << "\033[32;1m" << #x << " -> "; err(x); } while (0) 
void err() { cout << "\033[39;0m" << endl; } 
template <class T, class... Ts> void err(const T& arg, const Ts&... args) { cout << arg << ' '; err(args...); }
template <template<typename...> class T, typename t, typename... A> 
void err(const T <t> &arg, const A&... args) { for (auto &v : arg) cout << v << ' '; err(args...); }
void ptt() { cout << endl; }
template <class T, class... Ts> void ptt(const T& arg, const Ts&... args) { cout << ' ' << arg; ptt(args...); }
template <class T, class... Ts> void pt(const T& arg, const Ts&... args) { cout << arg; ptt(args...); }
void pt() {}
template <template<typename...> class T, typename t, typename... A>
void pt(const T <t> &arg, const A&... args) { for (int i = 0, sze = arg.size(); i < sze; ++i) cout << arg[i] << " \n"[i == sze - 1]; pt(args...); }
inline ll qpow(ll base, ll n) { assert(n >= 0); ll res = 1; while (n) { if (n & 1) res = res * base % mod; base = base * base % mod; n >>= 1; } return res; }
//head
constexpr int N = 1e5 + 10; 
int n, k, res; 

int calc(vector<vector<int>> vec) {
	int cnt = 0;
	for (auto &c : vec) {
		for (auto &it : c) {
			cnt += it;
		}
	}
	return cnt;
}

map <vector<vector<int>>, int> mp;

void dfs(vector<vector<int>> vec, int x, int y) {
	if (x == n - 1 && y == n - 1) {
		if (!mp.count(vec)) {
			mp[vec] = 1;
			res += ok(vec);
		}
		return;
	}
	if (x < n - 1) {
		dfs(vec, x + 1, y);
		vector <vector<int>> tmp(vec);
		for (int i = 0; i < n; ++i) {
			vec[x + 1][i] = 1;
		}
		dfs(tmp, x + 1, y);
	}
	if (y < n - 1) {
		dfs(vec, x, y + 1);
		vector <vector<int>> tmp(vec);
		for (int i = 0; i < n; ++i) {
			vec[i][y + 1] = 1;
		}	
		dfs(tmp, x, y + 1);
	}
}

class Solution {
public:
    int paintingPlan(int _n, int _k) {
		n = _n;
		k = _k;
		mp.clear();
		vector <vector<int>> vec(n, vector<int>(n, 0));
		res = 0;
		dfs(vec, -1, -1);
		return res;
    }
};

void run() {
	int n, k;
	rd(n, k);
	pt((new Solution())->paintingPlan(n, k));
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int _T = 1;
	//nextInt();
	while (_T--) run(); 
//    for (int kase = 1; kase <= _T; ++kase) {
//        cout << "Case #" << kase << ": ";
//        run();
//    }
//	while (cin >> n) run();
//	run();
	return 0;
}