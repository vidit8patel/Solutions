class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if(strs.empty())
            return ans;
        sort(strs.begin(), strs.end());
        string a = strs.front();
        string b = strs.back();
        for(int i = 0; i<a.length(); i++)
        {
            if(a[i] == b[i])
                ans += a[i];
            else
                return ans;
        }
        return ans;
    }
};