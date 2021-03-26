//Bottom up iterative using dynamic programming
class Solution {
  public:
    int knapsack(vector<int>& values, vector<int>& weights, int maxWeightConstraint) {
        int n = sizeof(weights)/ sizeof(weights[0]);
        //Stores the maximum values for a max weight up to and including the max weight
        //If we only use the first item, then the first and second and so on
        int dp[n+1][maxWeightConstraint+1];
        
        for(int i=0; i<=n; i++){
          for(int j=0; j<=maxWeightConstraint; j++){
              if(i==0 || j==0){ //Fill the first row and first column with zeros as we cannot use any weights for a max weight of 0
                  dp[i][j] = 0;
              }else if ( j - weights[i-1] >= 0){ //Check for index error
                  //Max value if we skip the current weight, or we use the current weight, 
                  //Then we have to look on the row above with [current max weight - current weight] as we cannot pick the same item if we chose it
                  dp[i][j] = max(dp[i-1][j], dp[i-1][j- weights[i-1]] + values[i-1]); 
              }else{
                  dp[i][j] = dp[i-1][j]; //Just skip the current weight
              }
          }
      }
      return dp[n][maxWeightConstraint]; //Return max
    }
};
