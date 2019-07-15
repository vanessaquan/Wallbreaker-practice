class Solution {
public:
    bool isHappy(int n) {
        
        int sum = 0;
        //use a map to store all numbers visited
        set <int> recur_list;
        
        //if any current number can be found in the recur_list, return false to break the loop
        //current number that can be found in the recur_list will end up being infinite loop
        while(1)
        {
            //add each element's power of 2 to sum
            sum += pow(n%10, 2);
            //update n by ingoring the last digit in n
            n = n/10;
            
            //whenever the updated n is reached to zero, it means n is less than 10
            //that is, it reached the last digit of n
            if(n == 0)
            {
                //add the last digit of n to sum
                sum += pow(n,2);
                
                //if sum reached to 1, stop the loop and return ture
                if(sum == 1)
                    return true;
                //otherwise, check if sum was a number that has been visited in the past
                //if sum was visited in the past, simply return false to avoid infinite loop
                //if not been visited, insert that number to set and continue the loop by resetting the sum to 0
                else
                {
                    
                    if(recur_list.find(sum) == recur_list.end())
                        recur_list.insert(sum);
                    else
                        return false;
                    n = sum;
                    sum = 0;
                }
            }
            
        }
        return true;
    }
};
