const int mod = 1e9 + 7;

class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<int> dp(target+1); //Number of ways to get ith sum
        dp[0] = 1;    
        
        
        for(int i=1; i<=d; i++){
            vector<int> n (target +1);
            
            for(int j = 0; j<= target; j++){
                for(int k =1; k<=f; k++){
                    if(j + k <= target){
                        int &tmp = n[j+k];
                        
                        tmp += dp[j];
                        
                        if(tmp >= mod){
                            tmp -= mod;
                        }
                    }
                }
            }            
            
            dp = n;
        }
        
        return dp[target];
        
    }
};
