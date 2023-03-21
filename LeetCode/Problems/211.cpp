class WordDictionary {
public:
    vector<array<uint32_t, 26>> state;
    vector<bool> end;

    WordDictionary() {
        state = {{0}};
        end = {false};
    }

    void addWord(string word) {
        int s = 0;

        // iterate word
        for (char c: word)
        {
            if (state[s][c - 'a'] == 0) {
                int t = state.size();
                state[s][c - 'a'] = t;
                state.push_back({0});
                s = t;
            } else {
                s = state[s][c - 'a'];
            }
        }

        // mark word end
        end.resize(state.size());
        end[s] = true;
    }

    bool search(string word) {
        return search_helper(word, 0, 0);
    }

    bool search_helper(const string& word, int start, int j) {
        int s = start;

        // iterate word
        for (int i = j; i < word.size(); ++i)
        {
            char c = word[i];
            if (c == '.') {
                // wildcard
                for (auto n : state[s]) {
                    if (n != 0 && search_helper(word, n, i + 1)) return true;
                }

                return false;
            } else {
                if (state[s][c - 'a'] == 0) return false;
                s = state[s][c - 'a'];
            }
        }

        return end[s];
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */