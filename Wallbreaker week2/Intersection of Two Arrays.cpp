class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //use unordered set named set1 to store nums1 into the set
        unordered_set<int> set1;
        //initialize a iterator it to iterate from beginning of nums1
        vector<int>::iterator it = nums1.begin();
        //unordered set set1 will hold the value of nums1
        set1.insert(it, it+nums1.size());
        
        vector<int> result;
        unordered_set<int> visited;
        //iterate nums2 and find the common value in both nums 1 and 2
        for(int i = 0; i < nums2.size(); i++)
        {
            //store common value into result and make sure the value in result is unique
            if(set1.find(nums2[i]) != set1.end()
               && visited.find(nums2[i]) == visited.end())
            {
                result.push_back(nums2[i]);
                visited.insert(nums2[i]);
            }
        }
        
        
        //return result
        return result;
    }
};
