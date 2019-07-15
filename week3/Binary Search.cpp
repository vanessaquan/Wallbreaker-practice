class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        //set edge left and right
        int left = 0, right = nums.size()-1;
        //initialize middle to hold the middle integer value
        int middle;
        //loop in a interval (left, right)
        while(left < right){
            //calculation of middle point
            middle = left + (right-left)/2;
            //if target is less than middle value, reset the range to (left, middle)
            if(target <= nums[middle])
                right = middle;
            //if the target is greater than middle value, reset the range to (middle+1, right)
            else
                left = middle + 1;
        }
        //when we reached to a case where left == right
        //check if the value is target, if it is, return the position, otherwise, return -1 for not found
        if(nums[left] == target)
            return left;
        return -1;
    }
};
