class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
	    int ans = 0, sum = 0;
	    unordered_map<int, int> map;
	    for(int i = 0; i<nums.size(); i++)
	    {
	        sum += nums[i];
	        int mod = ((sum%k)+k)%k;
	        if(mod == 0)
	            ans++;
            if(map.find(mod) != map.end())
	        {
	            ans += map[mod];
	        }
	        map[mod]++;
	    }
	    return ans;
	}
};