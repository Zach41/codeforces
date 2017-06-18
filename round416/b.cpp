#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n, m, x;
    vector<int> permutation;
    
    cin >> n >> m;
    for (auto i = 0; i < n; i++) {
        cin >> x;
        permutation.push_back(x);
    }
    int l, r, cnt_less;
    while(m--) {
        cnt_less = 0;
        cin >> l >> r >> x;
        int val = permutation[x - 1];
        for (auto i = l; i <= r; i++) {
            if (permutation[i - 1] < val) cnt_less++;
        }
        if (x == l + cnt_less)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        
    }
    return 0;
}