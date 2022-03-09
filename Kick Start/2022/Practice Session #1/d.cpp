#include <bits/stdc++.h>

using namespace std;

int winning_paths(int n, const vector<vector<char>> &board, bool blue) {
    int wp = 0;

    for (int i = 0; i < n; i++) {
        // start node
        pair<int, int> s = {blue ? i : 0, blue ? 0 : i};

        // check start node
        if (board[s.first][s.second] != (blue ? 1 : 2))
            continue;

        vector<vector<bool>> vis(n, vector<bool>(n, false));

        stack<pair<int, int>> st;
        st.push(s);

        while (!st.empty()) {
            pair<int, int> v = st.top();
            st.pop();

            if (vis[v.first][v.second])
                continue;

            if ((blue ? v.second : v.first) == n - 1) {
                // reached path to goal line
                wp++;
                if (wp > 1)
                    // already impossible since we have more than one path
                    // to goal line
                    return wp;
            }

            // add all adjacent nodes to stack
            for (int x = -1; x < 2; x++)
                for (int y = -1; y < 2; y++) {
                    if ((x == 0 && y == 0) || (x == -1 && y == -1) ||
                        (x == 1 && y == 1))
                        continue;

                    if (v.first + x < 0 || v.second + y < 0 ||
                        v.first + x >= n || v.second + y >= n)
                        continue;

                    if (!vis[v.first + x][v.second + y] &&
                        board[v.first + x][v.second + y] == (blue ? 1 : 2))
                        st.push({v.first + x, v.second + y});
                }
        }
    }

    return wp;
}

void solve() {
    int n;
    cin >> n;

    int r = 0;
    int b = 0;

    vector<vector<char>> board = vector<vector<char>>(n, vector<char>(n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;

            if (c == 'B') {
                b++;
                board[i][j] = 1;
            } else if (c == 'R') {
                r++;
                board[i][j] = 2;
            }
        }

    if (abs(r - b) > 1) {
        cout << "Impossible" << endl;
        return;
    }

    int bw = 0;
    int rw = 0;

    bw = winning_paths(n, board, true);
    rw = winning_paths(n, board, false);

    if (bw == 1 && rw == 0)
        cout << "Blue wins" << endl;
    else if (bw == 0 && rw == 1)
        cout << "Red wins" << endl;
    else if (bw == 0 && rw == 0)
        cout << "Nobody wins" << endl;
    else
        cout << "Impossible" << endl;
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