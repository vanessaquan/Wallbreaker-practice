class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        unordered_set<string> bannedlist;
        bannedlist.insert(banned.begin(), banned.begin()+banned.size());
        
        multiset<string> word;
        
        int i = 0;
        string word1 = "";
        while(i < paragraph.length())
        {
            while(paragraph[i]!=' ' &&paragraph[i] != '?'
                  &&paragraph[i] != '.'
                  &&paragraph[i] != ';'
                  &&paragraph[i] != '\''
                  &&paragraph[i] != ','
                  &&paragraph[i] != '!'
                  && paragraph[i] != '\n'
                  && paragraph[i] != '\r'
                  &&i<paragraph.length())
            {
                
                word1 += tolower(paragraph[i]);
                i++;
                if(i < paragraph.length())
                {
                    if(paragraph[i] == ' '
                       ||paragraph[i] == '.'
                       ||paragraph[i] == '!'
                       ||paragraph[i] == '?'
                       ||paragraph[i] == ';'
                       ||paragraph[i] == ',')
                    {
                        if(bannedlist.find(word1) == bannedlist.end())
                            word.insert(word1);
                    }
                }
                else if(i == paragraph.length())
                {
                    if(bannedlist.find(word1) == bannedlist.end())
                        word.insert(word1);
                    break;
                }
                
            }
            i++;
            word1 = "";
            
        }
        
        multiset<string>::iterator it = word.begin();
        int max = 0;
        string maxword = "";
        while(it != word.end())
        {
            cout << *it << " ";
            cout << word.count(*it) << endl;
            if(word.count(*it) >= max)
            {
                cout << maxword << "." ;
                max = word.count(*it);
                maxword = *it;
                
            }
            
            it ++;
        }
        
        
        
        return maxword;
    }
};
