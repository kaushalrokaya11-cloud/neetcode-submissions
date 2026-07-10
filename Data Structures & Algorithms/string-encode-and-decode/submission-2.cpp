class Solution {
public:

string encode(vector<string>& strs) {
        string encoded_string="";
        for(auto str:strs){
            int length = str.length();
            encoded_string += to_string(length)+'#'+ str;
        }
        return encoded_string;

    }

   
    vector<string> decode(string s) {
        int i=0; 
        vector<string> result;
       while(i<s.length()){
        string str_curr_length= "";
           while(s[i]!='#'){
               str_curr_length+=s[i];
               i++;
            }
          
            i++;
            int curr_length= stoi(str_curr_length);
            string curr_str="";
            int boundary = i + curr_length;
        
            while(i<boundary){
                curr_str+=s[i];
                i++;
            }
            result.push_back(curr_str);
        
        }
        return result;

    }
};
