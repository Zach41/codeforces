#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int> &v1, vector<int> &v2) {
    int cnt = 0;
    for (auto i = 0; i < v1.size(); i++) {
        if (v1[i] != v2[i]) cnt++;
    }
    if (cnt == 1)
        return true;
    else
        return false;
}

void printv(vector<int> &v) {
    cout << v[0];
    for (auto i=1; i<v.size(); i++) {
        cout << ' ' << v[i];
    }
    cout << '\n';
}

int main(void) {
    int n, x, pos1, pos2;
    vector<int> ansv, av, bv;

    while (cin >> n) {
        ansv.clear();
        av.clear();
        bv.clear();
        vector<bool> visit(n+1, false);
        pos1 = pos2 = -1;

        for (int i = 0; i < n; i++) {
            cin >> x;
            av.push_back(x);
        }
        for (int i = 0; i < n; i++) {
            cin >> x;
            bv.push_back(x);
        }

        for (int i=0; i<n; i++) {
            if (av[i] == bv[i]) {
                visit[av[i]] = true;
                ansv.push_back(av[i]);
            } else {
                ansv.push_back(-1);
                if (pos1 == -1) pos1 = i;
                else pos2 = i;
            }
        }
        // cout << "pos1: " << pos1 << "pos2: " << pos2 << '\n';
        bool flag = false;
        for (auto i = 1; i<visit.size(); i++) {
            if (!visit[i]) {
                // cout << "I: " << i << '\n';
                if (flag) ansv[pos2] = i;
                else {
                    flag = true;
                    ansv[pos1] = i;
                }
            }
        }
        if (check(av, ansv) && check(bv, ansv)) {
            printv(ansv);
        } else {
            swap(ansv[pos1], ansv[pos2]);
            // printv(ansv);
            printv(ansv);
        }
    }
    return 0;
}