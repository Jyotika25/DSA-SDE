//Brute approach

class Solution {
public:
    double power(double x , long n){
        if(n == 0)  return 1.0;
        if(n == 1)  return x;
        if(n<0) return(1/power(x,-n));
        double result = power(x*x , n/2);
        if(n%2) result *= x;
        return result;
    }
    
    double myPow(double x, int n) {
        return power(x,n);
    }
};


//optimal Approach
//tc : O(log2N)
//sc: O(1)

class Solution {
public:
    double myPow(double x, int n) {
        
        double result = 1.0;
        long long nn = n;
        if(nn<0)
            nn = -1 * nn;
        while(nn){
            if(nn%2){
                result = result * x;
                nn = nn-1;
            }
            else{
                x = x * x;
                nn = nn/2;
            }
        }
        if(n<0)
            result = double(1.0)/double(result);
        return result;
    }
};




