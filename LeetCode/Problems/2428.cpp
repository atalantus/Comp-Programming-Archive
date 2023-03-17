// Time Complexity: O(m*n)
class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int max = INT_MIN;

        for (int y = 1; y < grid.size() - 1; y++) {
            for (int x = 1; x < grid[y].size() - 1; x++) {
                int n = grid[y-1][x-1] + grid[y-1][x] + grid[y-1][x+1] +
                        grid[y][x] +
                        grid[y+1][x-1] + grid[y+1][x] + grid[y+1][x+1];
                if (n > max)
                    max = n;
            }
        }

        return max;
    }
};