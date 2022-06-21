class Solution {
public:
    vector<string> phone = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        vector<string> ans;
        ans.push_back("");
        for(auto digit: digits)
        {
            vector<string> temp;
            for(auto cand: phone[digit-'0'])
                for(auto a: ans)
                    temp.push_back(a + cand);
            ans.swap(temp);
        }
        return ans;
    }
};