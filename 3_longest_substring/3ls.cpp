class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // using sliding window
        int len = s.length();
        if (len <= 1) {
            return len;
        }
        int left = 0;
        int right = 0;
        int maxLength = 0;
        unordered_set<char> seen;
        for (right = 0; right < len; right++) {
            if (0 == seen.count(s[right])) {
                seen.insert(s[right]);
                maxLength = max(maxLength, right-left+1);
            } else {
                while (seen.count(s[right])) {
                    seen.erase(s[left]);
                    left++;
                }
                seen.insert(s[right]);
            }
        } 
        return maxLength;
    }
};