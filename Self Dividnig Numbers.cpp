//
//  Self Dividnig Numbers.cpp
//  wallbreakers
//
//  Created by XiaoJia Quan on 6/26/19.
//  Copyright © 2019 XiaoJia Quan. All rights reserved.
//


/*In this problem, I implemented two function. One main function" selfDividingNumbers" and a helper function "isSelfDividing".
 
 The main function will iterate element from the left to the right of the range and then filter out whichever can be divided by 10. It pass the valid numbers to the helper bool function "isSelfDividing" and check if that number is selfDividing. The helper function returns true if is self dividing and falsae if not.
 
 By checking whether the number is self dividing, we first need to check if each digit in the number is not zero and can divide the number. (here we do need to check if there is a digit equal to 0 since the main function only checks those 10 can divides. But if we have numbers like 709, 10 also cannot divides 709).
 
 if the bool function gives true, that means the number is self dividing and we can push it back to a vector list.
 after we went through all the numbers in range, we can return the number list.
 https://leetcode.com/problems/self-dividing-numbers/description/
 */


class Solution {
public:
    
    bool isSelfDividing(int num)
    {
        int i = num;
        while(i>10)
        {
            int digit = i%10;
            if(digit == 0)
                return false;
            
            if(num % digit != 0 )
                return false;
            
            i = i/10;
        }
        
        if(num%i != 0)
            return false;
        
        return true;
        
    }
    
    
    
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> result;
        
        for(int i = left; i <= right; i++)
        {
            if(i%10 != 0 && isSelfDividing(i))
                result.push_back(i);
        }
        return result;
    }
};
