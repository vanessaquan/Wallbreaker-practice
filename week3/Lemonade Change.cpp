class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map <int, int> cash_count;
        int pos = 0;
        int rest = bills[pos];
        //initially, we don't have ant change,
        //if we received money that is not 5, we cannot make change and return false
        if(rest != 5)
            return false;
        
        //pos increment to check the next customer
        cash_count[rest] ++;
        pos ++;
        //iterate through bills vector list
        while(pos < bills.size())
        {
            rest = bills[pos];
            cash_count[rest] ++;
            
            //if rest is just 5, there is no need to change
            while(rest != 5)d
            {
                //otherwise, check if rest is 20
                if(rest == 20)
                {
                    //we will choose to change 10 first
                    if(cash_count.find(10) != cash_count.end())
                    {
                        rest -= 10;
                        cash_count[10] --;
                        if(cash_count[10] == 0)
                            cash_count.erase(10);
                    }
                    //if 10 change not available, we will check if 5$ available
                    else if(cash_count.find(5) != cash_count.end())
                    {
                        //if 5$ is available but not enough to change, return false
                        if((rest-5)/5 > cash_count[5])
                            return false;
                        
                        //other wise, deduct the quantity number of 5$ by the number of 5$ we need to give as change
                        cash_count[5] -= (rest-5)/5;
                        //after the change, if we ran out of 5$, erase 5$ from the map list
                        if(cash_count[5] == 0)
                            cash_count.erase(5);
                        //set the rest to 5$ and end the loop
                        rest = 5;
                    }
                    //if neither 10$ nor 5$ available, we will return false since
                    //changes not available
                    else
                        return false;
                }
                //if rest is 10, we will choose to give 5$ change
                else if(rest == 10)
                {
                    if(cash_count.find(5) != cash_count.end())
                    {
                        rest -= 5;
                        cash_count[5] --;
                        if(cash_count[5] == 0)
                            cash_count.erase(5);
                    }
                    else
                        return false;
                    
                }
            }
            pos ++;
        }
        return true;
    }
};
