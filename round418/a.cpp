#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> av, bv;
    int n, k, x;

    while (cin >> n >> k) {
        av.clear();
        bv.clear();

        for (int i=0; i<n; i++) {
            cin >> x;
            av.push_back(x);
        }
        for (int i=0; i<k; i++) {
            cin >> x;
            bv.push_back(x);
        }
        if (bv.size() > 1) {
            cout << "YES" << '\n';
        } else if (bv.size() == 1) {
            bool yes = false;
            x = bv[0];
            if (av[0] == 0)
                av[0] = x;
            
            for (vector<int>::size_type i=1; i<av.size(); i++) {
                if (av[i] == 0) av[i] = x;
                if (av[i] <= av[i-1]) {
                    yes = true;
                    break;
                }
            }
            if (yes)
                cout << "Yes" << '\n';
            else
                cout << "No" << '\n';
        }
    }
    return 0;
}