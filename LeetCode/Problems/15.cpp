// Time Complexity: O(n^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> s;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++) {
            int t = -nums[i];
            
            int l = i + 1;
            int r = nums.size() - 1;
            
            while (l < r) {                
                if (nums[l] + nums[r] == t) {
                    s.push_back({nums[i], nums[l], nums[r]});

                    while (l < r && nums[l] == nums[l+1]) l++;
                    while (l < r && nums[r] == nums[r-1]) r--;

                    l++;
                    r--;
                }
                else if (nums[l] + nums[r] < t)
                    l++;
                else
                    r--;
            }
            
            while (i < nums.size() - 1 && nums[i] == nums[i+1]) i++;
        }
        
        return s;
    }
};