// Time Complexity: O(n)
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {        
        bool table[1001] = {};
        
        for (int n : nums) {
            table[n] = true;
        }
        
        while (original <= 1000) {
            if (!table[original]) break;
            original *= 2;
        }
        
        return original;
    }
};