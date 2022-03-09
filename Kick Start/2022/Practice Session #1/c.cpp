#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> cs(n);
    vector<int> h(n);
    vector<int> b(n + 1, 0);

    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        cs[i] = c;

        b[min(n, c)]++;

        int s = 0;
        int j = n;
        for (; j >= 0; j--) {
            s += b[j];

            if (s >= j)
                break;
        }

        cout << " " << j;
    }

    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(numeric_limits<double>::max_digits10);

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ":";
        solve();
    }

    return 0;
}