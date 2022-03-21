// Time Complexity: O(n)
class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> count = vector<int>(501, 0);
        
        for(int i : arr) {
            count[i]++;
        }
        
        for(int i = 500; i > 0; i--) {
            if (count[i] == i) return i;
        }
        
        return -1;
    }
};