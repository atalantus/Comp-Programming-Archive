// Time Complexity: O(n)
class Solution
{
public:
    long long zeroFilledSubarray(vector<int>& nums)
    {
        size_t start = -1;
        long long s = 0;

        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0 && start == -1)
            {
                // start of new 0 subarray
                start = i;
            } else if (nums[i] && start != -1)
            {
                // end of 0 subarray
                s += (i - start) * (i - start + 1) / 2;

                start = -1;
            }
        }

        if (nums[nums.size() - 1] == 0)
        {
            // end of 0 subarray
            s += (nums.size() - start) * (nums.size() - start + 1) / 2;
        }

        return s;
    }
};