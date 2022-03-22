// Time Complexity: O(n), Space Complexity: O(n)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        vector<int> x;
        
        for(int n : nums1)
            s.insert(n);
        
        for(int n: nums2) {
            if (s.find(n) != s.end()) {
                s.erase(n);
                x.push_back(n);
            }
        }
        
        return x;
    }
};