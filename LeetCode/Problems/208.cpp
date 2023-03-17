// Time Complexity: O(s)
class Trie
{
public:
    vector<array<uint32_t, 26>> state;
    vector<bool> end;

    Trie()
    {
        state = {{0}};
        end = {false};
    }

    void insert(string word)
    {
        int s = 0;

        // iterate word
        for (char& c: word)
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

    bool search(string word)
    {
        int s = 0;

        // iterate word
        for (char& c: word)
        {
            if (state[s][c - 'a'] == 0) return false;
            s = state[s][c - 'a'];
        }

        return end[s];
    }

    bool startsWith(string prefix)
    {
        int s = 0;

        // iterate prefix
        for (char& c: prefix)
        {
            if (state[s][c - 'a'] == 0) return false;
            s = state[s][c - 'a'];
        }

        // trie only contains complete words so
        // if the prefix exists it must be associated with a word
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */