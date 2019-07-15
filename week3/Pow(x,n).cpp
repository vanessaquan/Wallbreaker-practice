class Solution
{
public:
    double myPow(double x, int n)
    {
        
        //Base Case : X^0 = 1
        if (n == 0) {
            return 1;
        }
        //Base Case: power of 1 is x^1
        else if (n == 1) {
            return x;
        }
        else if (n < 0 && n != INT_MIN) {
            return 1 / myPow(x, -n);
        }
        else if (n % 2 != 0) {
            double result = myPow(x, n / 2);
            return result * result * x;
        }
        else {
            double result = myPow(x, n / 2);
            return result * result;
        }
        
    }
};
