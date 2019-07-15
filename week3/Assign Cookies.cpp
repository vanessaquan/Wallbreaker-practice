class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        //sort both vector list from low to high
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        //create two iterators to iterate g and s
        vector<int> ::iterator itg = g.begin();
        vector<int> ::iterator its = s.begin();
        
        //set count to count the number of content children to 0
        int count = 0;
        
        //while both iterators not reached to end of list
        while(itg!=g.end() && its!=s.end())
        {
            //if the current cookie value is less than the current greed factor
            //goto the next cookie
            if(*its < *itg)
                its ++;
            //otherwise, this cookie can assign to this children
            //count will increment by 1
            //go to the next children and next cookie
            else
            {
                count ++;
                its ++;
                itg ++;
            }
        }
        
        //either the children have been all assigned or we ran out of cookies
        //the loop will end and return the count vlue
        
        return count;
    }
};
