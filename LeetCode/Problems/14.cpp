// Time Complexity: O(s*n)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min = INT_MAX;
        for (auto& s : strs) {
            if (s.size() < min) min = s.size();
        }

        int i = 0;

        for (; i < min; ++i) {
            char c = strs[0][i];

            for (int j = 1; j < strs.size(); ++j)
                if (strs[j][i] != c) 
                    return strs[0].substr(0, i);
        }

        return strs[0].substr(0, i);
    }
};