solution 1 => Maximum Subarray

// It also give the start and end of maximum subarray sum.
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0], n = nums.size(), maxSum = nums[0], start = 0, end = 0, bgn = 0;
        for(int i = 1; i < n; i++){
            if(sum < 0){
                sum = 0;
                bgn = i;
            }
            sum += nums[i];
            if(sum > maxSum){
                maxSum = sum;
                end = i;
                start = bgn;
            }     
        }
        // cout << start << " " << end << endl;
        return maxSum;
    }

solution 2 => Maximum Sum Circular Subarray

    int kadanes(vector<int> &nums){
        int maxSum = nums[0], currSum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(currSum < 0){
                currSum = 0;
            }
            currSum += nums[i];
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSubSum = kadanes(nums), totalSum = 0, n = nums.size();
        if(maxSubSum < 0)
            return maxSubSum;
        for(int i = 0; i < n; i++){
            totalSum += nums[i];
            nums[i] = -1 * nums[i];
        }
        int minSubSum = kadanes(nums);
        return max(totalSum + minSubSum, maxSubSum);
    }
