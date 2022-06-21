class Solution {
public:
    string longestPalindrome(string s)
    {
        if(s.length() < 2)
            return s;
        int maxlen = 0, start = 0, i = 0;
        while(i < s.length())
        {
            int left = i, right = i;
            while(right < s.length() && s[right] == s[right+1])
                right++;
            i = right+1;
            while(right < s.length() && left > 0 && s[right+1] == s[left-1])
            {
                right++;
                left--;
            }
            int length = right - left + 1;
            if(length > maxlen)
            {
                maxlen = length;
                start = left;
            }
        }
        return s.substr(start, maxlen);
    }
};