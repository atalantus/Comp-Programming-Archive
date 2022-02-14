#include <bits/stdc++.h>

using namespace std;

vector<char> vs = {'a', 'e', 'i', 'o', 'u'};

void solve() {
    string k;
    cin >> k;

    cout << k << " is ruled by ";

    char e;
    e = tolower(k.at(k.length() - 1));

    if (e == 'y') {
        cout << "nobody." << endl;
        return;
    }

    for (int i = 0; i < vs.size(); i++) {
        if (e == vs[i]) {
            cout << "Alice." << endl;
            return;
        }
    }

    cout << "Bob." << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(numeric_limits<double>::max_digits10);

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}