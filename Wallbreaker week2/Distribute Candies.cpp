class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        
        //base case: # of candies = 2
        if(candies.size() == 2)
            return 1;
        //
        else
        {
            //use a set named candymap to store kinds of candies
            set<int> candymap;
            //insert each candy in candies
            for(int i = 0; i < candies.size(); i++)
            {
                candymap.insert(candies[i]);
            }//sice set only allows unique value, candymap set will store the kinds of candies
            
            //since brother and sister equally share the candies, the number of candies that sister has will
            //in between the val of candymap's size or candies' half size. depends on whichever is the min
            //this can be proved by induction
            return min(candymap.size(), candies.size()/2);
        }
        return 0;
    }
};
