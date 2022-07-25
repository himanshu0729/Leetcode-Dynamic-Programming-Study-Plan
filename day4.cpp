solution 1 => Jump Game

Method 1
  
    bool tryAllJumps(int idx, vector<int>& nums, vector<int> &dp){
        
        if(idx == nums.size()-1){
            return true;
        }
        
        if(dp[idx] != -1)
            return dp[idx];
        
        for(int jump = 1; jump <= nums[idx]; jump++){
            if(idx + jump < nums.size()){
                if(tryAllJumps(idx+jump, nums, dp))
                    return dp[idx] = true;
            }else 
                return dp[idx] = false;
        }
        
        return dp[idx] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return tryAllJumps(0, nums, dp);
    }

Method 2
  
      vector<int> memo;
    public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=true;
        
        for(int i=1;i<n;i++){
             for(int j=i-1;j>=0;j--){
                 if(dp[j] && j+nums[j]>=i){
                     dp[i]=true;
                     break;
                 }       
             }           
        }
        return dp[n-1];
  }

Method 3 
  
      bool canJump(vector<int>& nums) {
        int minJump = 0, n = nums.size();
        for(int i = n-2; i >= 0; i--){
            minJump++;
            if(nums[i] >= minJump)
                minJump = 0;
        }
        return minJump == 0;
    }

solution 2 => Jump Game II

method 1 
  
      int minJumps(int idx, vector<int>& nums, vector<int> &dp)
    {
        if(idx == nums.size()-1)
            return 0;
        
        if(idx >= nums.size())
            return 1e5;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        int mJ = 1e5;
        for(int jump = 1; jump <= nums[idx]; jump++){
            int tJumps = 1 + minJumps(idx+jump, nums, dp);
            mJ = min(mJ, tJumps);
        }
        return dp[idx] = mJ;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return minJumps(0, nums, dp);
    }

method 2
  
      int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1e5);
        dp[n-1] = 0;
        for(int idx = n-2; idx >= 0; idx--){
            int mJ = 1e5;
            for(int jump = 1; jump <= nums[idx]; jump++){
                int tJumps = 1 + dp[min(n-1, idx+jump)];
                mJ = min(mJ, tJumps);
            }
            dp[idx] = mJ;
        }
        return dp[0];
    }

method 3
  
      int jump(vector<int>& nums) {
        int start = 0, end = 0, maxJump = 0, n = nums.size(), levels = 0;
        while(end < n-1){
            levels++;
            for(int el = start; el <= end; el++){
                maxJump = max(maxJump, el + nums[el]);
                if(maxJump >= n-1)
                    return levels;
            }
            start = end + 1;
            end = maxJump;
        }
        return levels;
    }
