class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for(char a: s)
        {
            freq[a-'a']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int f = freq[0];
        int count = 0;
        for(int i = 0; i<freq.size(); i++)
        {
            if(freq[i]>f)
            {
                if(f>0)
                {
                    count+=freq[i]-f;
                }
                else count+=freq[i];
            }
            f = min(f-1, freq[i]-1);
        }
        return count;
    }
};