solution 1 => House Robber

Memoization 
    vector<int> dp;
    int allSubsequence(vector<int> &nums, int index) {
        if(index == 0)
            return nums[0];
        
        if(index < 0)
            return 0;
        
        if(dp[index] != -1)
            return dp[index];
        
        int ls = allSubsequence(nums, index-2) + nums[index];
        int rs = allSubsequence(nums, index-1);
        
        dp[index] = max(ls, rs);
        return dp[index];
    }
    int rob(vector<int>& nums) {
    
        dp.assign(nums.size(), -1);
        int maxRes = allSubsequence(nums, nums.size()-1);
        
        return maxRes;
    }

Tabulization 

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        
        for(int i = 1; i < n; i++) {
            
            int pick =  nums[i]; if(i > 1) pick += dp[i-2];
            int n_pick = dp[i-1];
            
            dp[i] = max(pick, n_pick);
        }
        
        return dp[n-1];
    }
    
solution 2 => House Robber II

    int maxAmount(vector<int>& amount, vector<int>& dp){
        
        dp[0] = amount[0];
        int n = amount.size();
        for(int i = 1; i < n; i++) {
            int pick = amount[i]; if(i > 1) pick += dp[i-2];
            int n_pick = dp[i-1];
            
            dp[i] = max(pick, n_pick);
        }
        return dp[n-1];
        
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        if(n == 2)
            return max(nums[0], nums[1]);
        
        vector<int> dp(n-1, -1);
        vector<int> houses1, houses2;
        for(int i = 0; i < n; i++) {
            if(i != 0)
                houses1.push_back(nums[i]);
            if(i != n-1)
                houses2.push_back(nums[i]);
        }
        
        return max(maxAmount(houses1, dp), maxAmount(houses2, dp));
    }
    
solution 3 => Delete and Earn

Memoization 

    int maxEarn(int idx, vector<int> &arr, vector<int> &dp){
        
        if(idx == 0)
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        int take = idx * arr[idx];
        if(idx > 1){
           take += maxEarn(idx-2, arr, dp);
        }
        int notTake = 0 + maxEarn(idx-1, arr, dp);
        
        return dp[idx] = max(take, notTake);
    }
    int deleteAndEarn(vector<int>& nums) {
        int maxEle = *max_element(nums.begin(), nums.end()), n = nums.size();
        vector<int> arr(maxEle + 1, 0);
        for(int i = 0; i < n; i++){
            arr[nums[i]]++;
        }
        vector<int> dp(maxEle+1, -1);
        return maxEarn(maxEle, arr, dp);
    }
    
Tabulization 

    int deleteAndEarn(vector<int>& nums) {
    
        int maxEle = *max_element(nums.begin(), nums.end()), n = nums.size();
        vector<int> arr(maxEle + 1, 0);
        for(int i = 0; i < n; i++){
            arr[nums[i]]++;
        }
        vector<int> dp(maxEle+1, 0);
        
        for(int idx = 1; idx <= maxEle; idx++){
            
            int take = idx * arr[idx];
            if(idx > 1){
               take += dp[idx-2];
            }
            int notTake = 0 + dp[idx-1];

            dp[idx] = max(take, notTake);
            
        }
        
        return dp[maxEle];
    }
