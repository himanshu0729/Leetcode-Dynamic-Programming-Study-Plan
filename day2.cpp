Solutoin 1 => Climbing Stairs

Memoization 

    int totalWays(int n, vector<int> &dp){
        if(n == 0)
            return 1;
        
        if(dp[n] != -1)
            return dp[n];
        
        int nm1 = totalWays(n-1, dp);
        int nm2 = 0;
          
        if(n > 1)
            nm2 = totalWays(n-2, dp);
        
        return dp[n] = nm1 + nm2;
    }
    
    int climbStairs(int n) { 
        vector<int> dp(n+1, -1);
        return totalWays(n, dp);
    }

Tabulization 

    int climbStairs(int n) { 
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int i  = 1; i <= n; i++){
            int nm1 = dp[i-1] ;
            int nm2 = 0;

            if(i > 1)
                nm2 = dp[i-2];
            
            dp[i] = nm1 + nm2;
        }
        return dp[n];
    }
    
Solution 2 => Min Cost Climbing Stairs

    vector<int> dp;
    int minCost(int start, vector<int> &cost) {
        
        if(start == cost.size()){
            return 0;
        }

        if(dp[start] != -1)
            return dp[start];
        
        int rmc = INT_MAX;
        int lmc = minCost(start+1, cost) + cost[start];
        if(start != cost.size()-1)
            rmc = minCost(start+2, cost) + cost[start];
        
        return dp[start] = min(lmc, rmc);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.assign(n, -1);
        minCost(0, cost);
        return min(dp[0], dp[1]);
    }
