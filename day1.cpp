Problem 1 => Fibonacci Number

Memoization 
int fun(int n, vector<int> &dp){
        
        if(n == 0 || n == 1)
            return n;
        
        if(dp[n] != -1)
            return dp[n];
        
        int nm1 = fun(n-1, dp);
        int nm2 = fun(n-2, dp);
        
        return dp[n] = nm1 + nm2;
    }
int fib(int n) {
        vector<int> dp(n+1, -1);
        return fun(n, dp);
}

Tabulization 

    int fib(int n) {
        
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        if(n > 0)
            dp[1] = 1;
        
        for(int i = 2; i <= n; i++)
            dp[i] = dp[i-1] + dp[i-2];
        
        return dp[n];
    }
    
Problem 2 => N-th Tribonacci Number

Memoization 
    int tri(int n, vector<int> &qn){
        
        if(n <= 1)
            return n;
        if(n == 2)
            return 1;
        
        if(qn[n] != -1)
            return qn[n];
        
        int nm1 = tri(n-1, qn);
        int nm2 = tri(n-2, qn);
        int nm3 = tri(n-3, qn);
        
        qn[n] = nm1+nm2+nm3;
        
        return qn[n];
        
    }
    
    int tribonacci(int n) {
        vector<int> qn(n+1, 0);
        int res = tri(n, qn);
        return res;
    }

Tabulization 

    int tribonacci(int n) {
        vector<int> qn(n+1, 0);
        if(n == 0)
            return 0;
        if(n == 1 || n == 2)
            return 1;
        int a = 0,b = 1, c = 1, res = 0;
        for(int i = 3; i <= n; i++){
            res = a + b + c;
            a = b;
            b = c; 
            c = res;
        }  
        return res;
    }
