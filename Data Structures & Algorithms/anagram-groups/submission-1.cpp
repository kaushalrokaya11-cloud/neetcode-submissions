class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>res;
        vector<vector<string>> result;
        for (auto str: strs){
            vector<int> count(26,0);
            for(char c : str){
                count[c-'a']++;
            }
            string key="";
            cout<<endl<<endl;
            for(int i=0;i<26;i++){
                key = key+  '#'+ to_string(count[i]);
                
            }
            res[key].push_back(str);

        }
        for(auto pr: res){
            result.push_back(pr.second);
        }
        return result;
    }
};
