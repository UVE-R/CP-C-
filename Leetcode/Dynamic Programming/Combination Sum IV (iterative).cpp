class Solution {
public:
    int dp[1002];    
    int solve(vector<int>&nums, int start, int target){
        //Base case
        if(target == 0){
            return 1;
        }
        
        //Invalid Case
        if(target <0 || start>=nums.size()){
            return 0;
        }
        
        //Return if already calculated
        if(dp[target] != -1){
            return dp[target];
        }
        
        if(nums[start] > target){
            return dp[target] = solve(nums, start+1, target); //If too large, skip
        }
        
        //Add the number of way if we include the current number, which means we reset and start our nums pointer to the 
        //start as we can choose the previous numbers again
        //Or we can skip the current number, which means we need to set our nums pointer to the next number
        return dp[target] = solve(nums, 0, target - nums[start]) + solve(nums, start+1, target); 
        
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,target);        
    }
};
