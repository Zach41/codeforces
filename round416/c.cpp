/*
lmin(x)表示序列中x最左边的位置，rmax(x)表示序列中x最右边的位置.
xor(j, i)表示序列中下标为j到i的数字的异或和。
dp[i]表示到i为止能得到的最大的和。
如果存在这么一个区间[j, i]，满足区间区间中任意一个数字a，有lmin(a) >= j, rmax(a) <= i，
那么可以更新dp[i]为dp[i] = max(dp[j-1] + xor(j, i), dp[i])
如果不存在这样的区间，那么就有dp[i] = dp[i-1]
对每一个i，初始化更新dp[i]为dp[i-1]，然后从i往前迭代，找到一个区间就更新dp[i]，直到更新到序列头。
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(void)
{
    vector<int> codes;
    map<int, pair<int, int>> border_map;
    int n, x;

    cin >> n;
    codes.push_back(0);
    for (auto i = 0; i < n; i++) {
        cin >> x;
        codes.push_back(x);
    }

    for (auto i = 1; i < codes.size(); i++) {
        if (border_map.find(codes[i]) == border_map.end()) {
            border_map[codes[i]] = make_pair(i, i);
        } else {
            border_map[codes[i]].second = i;
        }
    }

    vector<int> dp(n+1, 0);
    for (auto i = 1; i < codes.size(); i++) {
        auto lmin = border_map[codes[i]].first, rmax = border_map[codes[i]].second;
        auto cur = 0;
        map<int, bool> visited;
        dp[i] = dp[i-1];
        for (auto j = i; j; j--) {
            lmin = min(border_map[codes[j]].first, lmin);
            rmax = max(border_map[codes[j]].second, rmax);
            if (visited.find(codes[j]) == visited.end()) {
                cur ^= codes[j];
                visited[codes[j]] = true;
            }
            if (j == lmin && i == rmax) dp[i] = max(dp[j-1] + cur, dp[i]);
        }        
    }
    cout << dp[n] << endl;
    return 0;
}