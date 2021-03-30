const int mod = 1e9 + 7;

class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        
        int dp[d][target+1]; //Number of dice (rows) used against sum (columns)
        memset(dp, 0, sizeof(dp)); //Set all to zero        
        
        //With only 1 dice, there is only 1 way of getting a sum up to the face number
        for(int i=1; i<= min(f,target); i++){ 
            dp[0][i] = 1;
        }
        
        for(int i=1; i< d; i++){ //For each dice
            for(int j=1; j<=target; j++){ //For each target sum                
                for(int k=1; k<=f; k++){ //For each side of the dice
                    //The possible ways of getting the current sum is the number of possible ways of getting 
                    // the current sum - the face number
                    if( j-k >= 0){                    
                        int &tmp = dp[i][j];                        
                        //Get the number of ways from the row above as the current coin is not in use
                        tmp += dp[i-1][j-k];                         
                        if(tmp >= mod){
                            tmp -= mod;
                        }                        
                    }
                }
            }
        }
        
        return dp[d-1][target];
        
    }
};
