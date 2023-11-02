class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // here the order doesn't matter and the sum needs to be zero.
        sort(nums.begin(), nums.end());
        // keep track of answers
        set<vector<int>>ans;
        vector<vector<int>>res;
        // special case
        if (nums[0] > 0 || nums[nums.size() - 1] < 0) {
            return res;
        }
        
        // start from the sides
        for (int i =0; i < nums.size(); i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                // if it starts to go below 0, then move j so sum is larger
                if (sum < 0) {
                    j++;
                } else if (0 == sum) {
                    ans.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                } else {
                    k--;
                }
            }
        }

        for (auto item: ans) {
            res.push_back(item);
        }
        return res;
        
    }
};

// much faster answer from others using iterator, cant find who's the author
// the author saved a lot time using while loops to skip same values.
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int>::iterator it1 = nums.begin();
        vector<int>::iterator it2 = nums.begin()+1;
        vector<int>::iterator it3 = nums.end()-1;
        sort(nums.begin(), nums.end());
        vector<int> newVec = {};
        int t =0;

        vector<vector<int>> res = {};

        while (it1 <= nums.end()-3) {
            // cout << *it1 << endl;
            it2 = it1+1;
            it3 = nums.end()-1;
            t = -(*it1);
            while (it2 < it3) {
                if (*it2+*it3 == t) {
                    newVec = {*it1, *it2, *it3};
                    res.push_back(newVec);
                    // Skip to another different value
                    while (*it2 == *(++it2) && it2 < it3) {

                    }
                    while (*it3 == *(--it3) && it2 < it3) {

                    }
                } else if (*it2 + *it3 < t) {
                    it2++;
                } else {
                    it3--;
                }
                
            }
            while (*it1 == *(++it1) && it1 <= nums.end()-3) {}
        }
        

        return res;
    }
};