class Solution {
public:
    const int inf = 1e6;    
    int coinChange(vector<int>& coins, int amount) {
        
        unsigned int dp[amount +1]; //Stores the minimum number of ways to get ith sum
        
        memset(dp, inf, sizeof(dp)); //Fill with infinity
        
        dp[0] = 0; //No Possible way of getting no coins
        
        //Sort so that if we start getting a negative index, we should move to the next iteration
        sort(coins.begin(), coins.end());
        
        int n = coins.size();        
        
        for(int i=1; i<= amount; i++){
            for(int j=0; j<n; j++){ //For each coin
                if(coins[j] <= i){ //Check if an index exists (avoid index error)
                    //Find the minimum, it is the same problem as the minimum number of ways to get sum - coin[i]
                    //Then add 1 to take into account that we are adding the coin back
                    dp[i] = min(dp[i], dp[i - coins[j]] +1);
                }else{
                    break;
                }
            }
        }
        
        if(dp[amount] > 10001){
          return -1; //If not possible 
        }else{
            return dp[amount];
        }
        
        
    }
};
