// Time Complexity: O(n)
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool incr = false;
        bool decr = false;
        int i = 0;
        
        while (i < arr.size() - 1 && arr[i + 1] > arr[i]) {
            incr = true;
            i++;
        }
        
        while (i < arr.size() - 1 && arr[i + 1] < arr[i]) {
            decr = true;
            i++;
        }
        
        if (!incr || !decr || i != arr.size() - 1) return false;
        
        return true;
    }
};