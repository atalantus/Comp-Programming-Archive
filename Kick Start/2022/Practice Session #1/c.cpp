#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> cs(n);
    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        cin >> cs[i];
    }

    h[0] = 1;
    for (int i = 1; i < n; i++) {
        h[i] = h[i - 1];

        if (cs[i] <= h[i - 1])
            continue;

        int m = 0;

        for (int j = 0; j < i; j++) {
            if (cs[j] > h[i - 1])
                m++;
        }

        if (m + 1 > h[i - 1])
            h[i]++;
    }

    for (int i = 0; i < n; i++) {
        cout << " " << h[i];
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