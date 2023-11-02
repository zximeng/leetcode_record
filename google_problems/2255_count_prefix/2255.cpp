class Solution {
public:
     int countPrefixes(vector<string>& words, string s) {
        int res = 0;
        for(auto word:words){
            bool pre = true;
            for(int i=0; i<word.length(); i++){
                if(word[i] != s[i]){
                    pre = false;
                    break;
                }
            }
            if(pre) res++;
        }
        return res;
    }
};

// fastest solution found in the accpeted page. the author used s.find 

class Solution {
public:
	//time:O(n), space: O(1)
	int countPrefixes(vector<string>& words, string s) {
		int count = 0;
		for(auto wd : words)
			if(s.find(wd) < 1) count++; //if first occurrence of sub-string is in the specified string
		return count;
	}
};