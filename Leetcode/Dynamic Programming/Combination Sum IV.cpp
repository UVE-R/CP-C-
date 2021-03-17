//ITERATIVE SOLUTION

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        unsigned long long dp[target + 1]; //Stores the number of ways to get ith sum 
        
        memset(dp,0,sizeof(dp)); //Fill with zeros
        
        dp[0] = 1; //Only 1 way of getting a sum of 0
        
        sort(nums.begin(), nums.end()); //Sort nums
        
        int n = nums.size(); //Size of nums for iteration
        
        for(int i=1; i<= target; i++){ //For each ith sum
            for(int j=0; j<n; j++){
                if(nums[j] <= i){ //In case of out of bounds as dp[x] must have x>=0
                    //The problem of finding the ith sum is the same as finding the ways of getting
                    // i-x sum where x is the coin number.
                    // As coin x is added as a way of getting ith sum, it counts as a single way
                    //Then is multipled by the ways to get i-x sum, which is just 1* dp[i-x] = dp[i-x]
                    dp[i] += dp[i-nums[j]]; 
                }else{
                    break;
                }
            
            }
                 
        }
        
        return dp[target];
        
    }
};
