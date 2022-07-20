class Solution {
public:
    int numMatchingSubseq(string& s, vector<string>& words) {
        int ans = 0;
        vector<vector<int>> map(26);  // stores array of indices for each character in s
        for(int i = 0; i < s.size(); i++) 
            map[s[i] - 'a'].push_back(i);
        for(auto& word : words) 
        {
            bool found = true;
            // i = index in word | prev = index in s matched for word[i-1]
            for(int i = 0, prev = -1; found && i < word.size(); i++) 
            {
                auto& v = map[word[i]-'a'];
                auto it = upper_bound(begin(v), end(v), prev);   // check if current character exists in s with index > prev
                if(it == end(v))
                    found = false;                  // doesn't exist
                else prev = *it;                    // update prev for next check
            }
            ans += found;
        }
        return ans;
    }
};