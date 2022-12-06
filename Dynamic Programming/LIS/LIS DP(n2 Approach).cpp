class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        dp[0] = 1;
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(nums[j] >= nums[i])
                    continue;
                else
                {
                    int possibleAns = dp[j] + 1;
                    if(possibleAns > dp[i])
                        dp[i] = possibleAns;
                }
            }
        }
        int ans = INT_MIN;
        for(int i=0;i<n;i++)
            ans = max(ans,dp[i]);
        
        return ans;
    }
};
