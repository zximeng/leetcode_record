class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int maxScore = 0;
        int zeroCount = 0;
        int oneCount = 0;
        // go through the array once to get the total number of ones
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]) {
                oneCount++;
            }
        }
        zeroCount = nums.size() - oneCount;
        int sum = 0;
        int currentZeroCount = 0;
        vector<int> res;
        // int currentOneCount = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == 0) {
                currentZeroCount += 1;
            }
            // score for all zeros on the left and ones on the right
            sum = currentZeroCount + (oneCount - (i + 1 - currentZeroCount));
            if (maxScore == sum) {
                maxScore = sum;
                res.clear();
                res.push_back(i+1);
            } else if (maxScore < sum) {
                res.push_back(i+1);
            }

        }
        // special case 
        if (oneCount >= maxScore) {
            if (oneCount > maxScore) {
                res.clear();
            }
            res.push_back(0);
        }
        return res;
        
    }
};