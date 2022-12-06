// LIS By Memoization

class Solution {
public:
    int findLIS(vector<int>& nums,int idx,int previdx, vector<vector<int>> &mem)
    {
        if(idx >= nums.size())
        return 0;

        if(mem[idx][previdx+1] != -1)
            return mem[idx][previdx+1];
        int ans1 = 0;
        if(previdx == -1 || nums[idx] > nums[previdx])
        {
            ans1 = 1 + findLIS(nums, idx+1, idx,mem);
        }
        int ans2 = findLIS(nums,idx+1,previdx,mem);
        mem[idx][previdx+1] = max(ans1,ans2);
        return mem[idx][previdx+1];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> mem(n, vector<int>(n+1,-1));
        return findLIS(nums,0,-1,mem);
    }
};
