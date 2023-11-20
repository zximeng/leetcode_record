class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        backTrack(nums, 0, res, sub);
        return res;
        
    }

private:
    void backTrack(vector<int>& nums, int idx, vector<vector<int>>&res, vector<int>&sub) {
        res.push_back(sub);

        for (int i = idx; i < nums.size(); i++) {
            sub.push_back(nums[i]);
            backTrack(nums, i+1, res, sub);
            sub.pop_back()
        }

    }

};