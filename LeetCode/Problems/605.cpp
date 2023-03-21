// Time Complexity: O(n)
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int x = 0;
        int s = flowerbed.size();

        for(int i = 0; i < flowerbed.size(); ++i) {
            if (flowerbed[i]) continue;
            if (i > 0 && flowerbed[i-1]) continue;
            if (i < s - 1 && flowerbed[i+1]) continue;
            // place
            flowerbed[i] = 1;
            ++x;
        }

        return x >= n;
    }
};