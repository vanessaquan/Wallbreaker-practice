class Solution {
public:
    char findTheDifference(string s, string t) {
        
        //use ordered multiset to store element in s
        multiset <char> sset;
        string::iterator iter = s.begin();
        sset.insert(iter, iter+s.length());
        
        //use ordered multiset to store element in t
        multiset <char> tset;
        iter = t.begin();
        tset.insert(iter, iter+t.length());
        
        //iterate elements in each set and compare
        multiset <char> ::iterator iters, itert;
        for(iters = sset.begin(), itert = tset.begin();
            iters!= sset.end() && itert != tset.end(); iters++, itert ++)
        {
            //if element in same position is not equal,
            //insert the element to one of the set
            //in this case, I inserted itert's value to sset
            //if after the insertion, two sets are equal,
            //then the extra value is itert, otherwise, the extra value should be iters
            
            if(*iters != *itert )
            {
                sset.insert(iters, *itert);
                if(sset == tset)
                    return *itert;
                else
                    return *iters;
            }
        }
        
        //if nothing returned in the for loop,
        //check if one of the iterators have not reached to end
        //return the value of the iterator where it has not reached to end
        //otherwise, return empty char
        if(iters == sset.end() && itert != tset.end())
            return *itert;
        else if(iters != sset.end() && itert == tset.end())
            return *iters;
        
        return ' ';
    }
};
