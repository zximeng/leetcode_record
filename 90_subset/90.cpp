class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        int index = 0;
        sort(nums.begin(),nums.end());
        find(nums, index, sub, res);
        return res;
    }

private:
    void find(vector<int>& nums, int index, vector<int>&sub, vector<vector<int>>& res) {
        res.push_back(sub);

        for (int i = index; i < nums.size(); i++) {
            if ((i > 0) && (nums[i] == nums[i - 1]) && (i > index)) {
                continue;
            }
            sub.push_back(nums[i]);
            find(nums, i+1, sub, res);
            sub.pop_back();
        }

    }
};