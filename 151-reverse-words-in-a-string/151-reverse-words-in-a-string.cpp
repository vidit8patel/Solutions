class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        string res;
        int n = s.length();
        while(i < n)
        {
            while(i<n && s[i] == ' ')
                i++;
            if(i>=n)
                return res;
            int j = i+1;
            while(j<n && s[j] != ' ')
                j++;
            string temp = s.substr(i, j-i);
            if(res.length() == 0)
                res = temp;
            else res = temp + ' ' + res;
            i = j+1;
        }
        return res;
    }
};