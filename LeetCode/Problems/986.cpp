// Time Complexity: O(n+m)
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ints;
        
        int i,j = 0;
        
        while (i < firstList.size() && j < secondList.size()) {
            int s = max(firstList[i][0], secondList[j][0]);
            if (ints.size() > 0)
                s = max(s, ints[ints.size() - 1][1]);
            
            // check if j ends in i
            if (secondList[j][1] <= firstList[i][1] && secondList[j][1] >= firstList[i][0]) {
                ints.push_back({s, secondList[j][1]});
                j++;
            }
            // check if i ends in j
            else if (firstList[i][1] <= secondList[j][1] && firstList[i][1] >= secondList[j][0]) {
                ints.push_back({s, firstList[i][1]});
                i++;
            } 
            // no intersection
            else {
                if (secondList[j][1] < firstList[i][1]) j++;
                else i++;
            }
        }
            
        return ints;
    }
};