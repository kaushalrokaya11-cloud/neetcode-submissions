class TimeMap {
public:
unordered_map<string,vector<pair<int,string>>> storage;
int test=0;
 
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) 
    {
        storage[key].push_back({timestamp,value});

    }
    
    string get(string key, int timestamp) {
        if(storage.find(key)==storage.end()){
            return "";
        }
        else{
            int l=0;
            int r=storage[key].size()-1;
            int m;
            while(l<=r){
                m=(l+r)/2;
                if(storage[key][m].first==timestamp){
                    return storage[key][m].second;
                }
                else if (storage[key][m].first>timestamp){
                    r=m-1;
                }
                else{
                    l=m+1;
                }
            }
            if(r==-1){return "";}
            else{

            int mini=min(l,r);
            return storage[key][mini].second;
            }
        }
        
    }
};
