//
//  plus one.cpp
//  wallbreakers
//
//  Created by XiaoJia Quan on 6/26/19.
//  Copyright © 2019 XiaoJia Quan. All rights reserved.
//

/*https://leetcode.com/problems/plus-one/description/
 
 
 In this problem, I first check if the vector list's last integer is less than 9, if it is less than 9, then we just need to add 1 to the last integer and return the whole list immediatly without needing any further checking.
 otherwise, which the last ineger of the vector list is 9:
 I set a variable named "income" initialized to 0 in the begining.
 "income" will keep track if the previous integer add up to 1 is euqal to 10. if yes, then the "income" variable will hold the "1" to add to the next integer later. if not, then just add 1 to current ineger and return the whole list.
 
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int original = 0;
        if(digits.back() < 9)
        {
            int i = digits.back();
            digits.pop_back();
            digits.push_back(i+1);
            return digits;
        }
        else
        {
            int  income = 0;
            for(int i = digits.size() - 1; i >= 0; i--)
            {
                if(i == digits.size() -1)
                {
                    if(digits[i] + 1 == 10)
                    {
                        digits[i] = 0;
                        income = 1;
                    }
                }
                else
                {
                    if(digits[i] + income == 10)
                    {
                        digits[i] = 0;
                        income = 1;
                    }
                    else
                    {
                        digits[i] += 1;
                        return digits;
                    }
                }
                
            }
            
            if(income == 1)
                digits.insert(digits.begin(), 1);
            
            return digits;
            
        }
        
        
    }
};
