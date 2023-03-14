// Time Complexity: O(n)
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int a = INT_MIN, b = INT_MIN, c = INT_MAX, d = INT_MAX;

        // iterate nums
        for (int i = 0; i < nums.size(); ++i) {
            int n = nums[i];

            if (n > a) {
               b = a;
               a = n;
            } else if (n > b) {
                b = n;
            }

            if (n < c) {
                d = c;
                c = n;
            } else if (n < d) {
                d = n;
            }
        }

        return a*b-c*d;
    }
};