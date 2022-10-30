#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl "\n"
#define fi first
#define se second
#define all(x) begin(x), end(x)
#define rall rbegin(a), rend(a)
#define bitcnt(x) (__builtin_popcountll(x))
#define complete_unique(a) a.erase(unique(begin(a), end(a)), end(a))
#define mst(x, a) memset(x, a, sizeof(x))
#define MP make_pair

using ll = long long;
using ull = unsigned long long;
using db = double;
using ld = long double;
using VLL = std::vector<ll>;
using VI = std::vector<int>;
using PII = std::pair<int, int>;
using PLL = std::pair<ll, ll>;

using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T, typename S>
inline bool chmax(T &a, const S &b) {
    return a < b ? a = b, 1 : 0;
}

template <typename T, typename S>
inline bool chmin(T &a, const S &b) {
    return a > b ? a = b, 1 : 0;
}

#ifdef LOCAL
#include <debug.hpp>
#else
#define dbg(...)
#endif
// head

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#ifdef LOCAL

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#endif

int dir[][2] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0},
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head) {
        auto res = vector<vector<int>>(m, vector<int>(n, -1));

        int x = 0, y = 0;
        int ix = 0;
        while (head) {
            res[x][y] = head->val;
            head = head->next;
            int nx, ny;
            nx = x + dir[ix][0];
            ny = y + dir[ix][1];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n || res[nx][ny] != -1) {
                ix = (ix + 1) % 4;
                nx = x + dir[ix][0];
                ny = y + dir[ix][1];
            }

            x = nx;
            y = ny;
        }

        return res;
    }
};

#ifdef LOCAL

int main() {
    return 0;
}

#endif