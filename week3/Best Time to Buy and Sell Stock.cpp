class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        
        int profit = 0;
        //base case
        if(prices.size() <= 1)
            return 0;
        else if(prices.size() == 2)
        {
            if(prices[0] > prices[1])
                return 0;
            else
                return prices[1] - prices[0];
        }
        else
        {
            for(int i = 0; i < prices.size() - 1; i++)
            {
                for(int j = i+1; j < prices.size(); j++)
                {
                    if(prices[j] > prices[i])
                    {
                        if(prices[j] - prices[i] > profit)
                        {
                            profit = prices[j] - prices[i];
                        }
                    }
                    
                }
            }
        }
        
        return profit;
        
        
    }
};
