

// Longest Increasing Subsequence By Recursion
    
class Solution {
public:
    int findLIS(vector<int>& nums,int idx,int previdx,int n)
    {
        if(idx >= n)
        return 0;
        int ans1 = 0;
        if(previdx == -1 || nums[idx] > nums[previdx])
        {
            ans1 = 1 + findLIS(nums, idx+1, idx,n);
        }
        int ans2 = findLIS(nums,idx+1,previdx,n);
        return max(ans1,ans2);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return findLIS(nums,0,-1,n);
    }
};
