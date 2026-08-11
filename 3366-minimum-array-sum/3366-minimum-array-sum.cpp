class Solution {
public:
    int dp[105][105][105];

    int solve(vector<int>& nums, int k, int i, int op1, int op2) {
        if (i == nums.size())
            return 0;

        if (dp[i][op1][op2] != -1)
            return dp[i][op1][op2];

        int ans = nums[i] + solve(nums, k, i + 1, op1, op2);

        if (op1 > 0) {
            int val = (nums[i] + 1) / 2;
            ans = min(ans, val + solve(nums, k, i + 1, op1 - 1, op2));
        }
        if (op2 > 0 && nums[i] >= k) {
            int val = nums[i] - k;
            ans = min(ans, val + solve(nums, k, i + 1, op1, op2 - 1));
        }
        if (op1 > 0 && op2 > 0) {

            int val1 = (nums[i] + 1) / 2;
            if (val1 >= k) {
                ans = min(ans,
                          val1 - k + solve(nums, k, i + 1, op1 - 1, op2 - 1));
            }

            if (nums[i] >= k) {
                int val2 = (nums[i] - k + 1) / 2;
                ans = min(ans,
                          val2 + solve(nums, k, i + 1, op1 - 1, op2 - 1));
            }
        }

        return dp[i][op1][op2] = ans;
    }

    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, k, 0, op1, op2);
    }
};