class Solution {
public:
    int characterReplacement(string s, int k)
    {
        int ans = 0, maxf = 0;
        int i = 0;
        vector<int> dict(26, 0);
        for(int j = 0; j<s.length(); j++)
        {
            dict[s[j] - 'A']++;
            maxf = max(maxf, dict[s[j] - 'A']);
            int letterstochange = (j - i + 1) - maxf;
            if(letterstochange > k)
            {
                dict[s[i]-'A']--;
                i++;
            }
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};