class Solution {
public:
    int rob(vector<int>& nums) {
        
        //base cases
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        if(nums.size() == 2)
            return max(nums[0], nums[1]);
        if(nums.size() == 3)
            return max(max(nums[0], nums[1]), nums[2]);
        
        //there are n houses
        //first map, stores the max number from 1 to n-1 houses, since we picked 0, we will ingore nth
        unordered_map <int, int> houses_money_0;
        for(int i = 0; i <= nums.size()-1 ; i++)
        {
            if(i == 0)
                houses_money_0[i] = 0;
            else if(i == 1)
                houses_money_0[i] = nums[0];
            else if(i == 2)
                houses_money_0[i] = max(nums[0], nums[1]);
            else
                houses_money_0[i] = max(houses_money_0[i-2] + nums[i-1], houses_money_0[i-1]);
        }
        
        //skip 1 and iterate from 2 to nth
        unordered_map <int, int> houses_money_1;
        houses_money_1[0] = 0;
        for(int i = 1; i <= nums.size()-1 ; i++)
        {
            if(i == 1)
                houses_money_1[i] = nums[1];
            else if(i == 2)
                houses_money_1[i] = max(nums[1], nums[2]);
            else
                houses_money_1[i] = max(houses_money_1[i-2] + nums[i], houses_money_1[i-1]);
        }
        
        
        //return max between two number
        return max(houses_money_0[nums.size()-1], houses_money_1[nums.size()-1]);
        
        
    }
};
