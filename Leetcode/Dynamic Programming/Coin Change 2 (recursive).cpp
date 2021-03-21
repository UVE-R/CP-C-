class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();       
         
        //Dp matrix of the coins used (dp[1][]) represents using only the first coin
        //(dp[3][]) represents using the first 3 coins
        // Alongside the number of ways to make dp[][i] sum        
        int dp[n+1][amount + 1];
        
        memset(dp,0,sizeof(dp));
        
        //Fill the first element of each row with 1s as only 1 way of making a sum of 0
        for(int i=0; i<=n;i++){
            dp[i][0] = 1;
        }        

        
        for(int i=1; i<=n; i++){ 
            for(int j=1; j<=amount; j++){ 
                if(j-coins[i-1] >=0){ //Check for index error
                    //The number of unique ways to get dp[i][j] is if you use the coin or dont use the current coin
                    //dp[i-1][j] represents not using the coin
                    //dp[i][j-coins[i-1]] represents using the coin as the number of ways to get the sum 
                    //with the sum-coin, it is i-1 as 1 starts at 1 so we must convert to zero based                    
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]]; 
                }else{
                    //If there is an index error then get the result if you do not use the coin
                    dp[i][j] = dp[i-1][j]; 
                }                                  
            }
        }
        
        return dp[n][amount];
        
        
        
    }
};
