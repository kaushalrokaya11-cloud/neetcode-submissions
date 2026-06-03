class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        int res;
        for(int i=0;i<=n;i++){
            res=0;

            for(int j=0;j<31;j++){
                if(1<<j & i){res++;}
            }
            result.push_back(res);
        }
        return result;
    }
};
