#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    int n, q, m;
    char ch;
    string garland;

    while (cin >> n) {
        cin >>garland;
        map<char, vector<int>> ans_map;
        vector<vector<int>> c_cnt(garland.size(), vector<int>(garland.size(), 0));

        for (ch = 'a'; ch <='z'; ch++) {
            ans_map[ch] = vector<int>(n+1, 0);
            for (auto i = 0; i < garland.size(); i++) {
                int replace_ct = 0;
                for (auto j = i; j < garland.size(); j++) {
                    if (garland[j] != ch) replace_ct++;                    
                    ans_map[ch][replace_ct] = max(ans_map[ch][replace_ct], j - i + 1);
                }
            }

            for (auto i=1; i < ans_map[ch].size(); i++) {
                ans_map[ch][i] = max(ans_map[ch][i], ans_map[ch][i-1]);
            }
        }
        cin >> q;
        while (q--) {
            cin >> m >> ch;
            cout << ans_map[ch][m] << '\n';
        }
    }
    return 0;
}