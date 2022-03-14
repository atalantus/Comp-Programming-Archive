// Time Complexity: O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int bought = prices[0];
        
        for(int i = 1; i < prices.size(); i++) {
            if (prices[i] < bought)
                bought = prices[i];
            
            if (prices[i] - bought > max)
                max = prices[i] - bought;
        }
        
        return max;
    }
};