class Solution {
public:

    string encode(vector<string>& strs) {
        stringstream key;
        for(int i=0;i<strs.size();i++)
        {
            key<<strs[i].length()<<'#'<<strs[i];

        }
        string key_f= key.str();
        return key_f;

    }

    vector<string> decode(string s) {
        vector <string> vec;
        string final;
        int number;
        int j=0;
        for(int i=0;i<s.length();i++){
            j=i;
            while(s[j]!='#'){
                j++;
            }
            number=stoi(s.substr(i,j-i));
            final = s.substr(j+1,number);
            vec.push_back(final);
            i=j+number;
            
        }
        return vec;
        

    }
};
