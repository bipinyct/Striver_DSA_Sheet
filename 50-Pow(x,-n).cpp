class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1.0;

        double ans = 1.0;
        long long N = n;  // Use long long to handle INT_MIN case

        if(N < 0){
            x = 1/x;
            N = -N;
        }

        while(N>0){
            if(N % 2 == 0){
                x = x*x;
                N = N/2;

            }

            else{
                ans = ans*x;
                N--;
            }
        }
        return ans;
    }
};