class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int  res = blocks.length(),white_blocks=0;
        int n = blocks.length();
        int l=0,r=0;
        for(r = 0;r< k; r++){
            if(blocks[r]=='W'){
                white_blocks++;
            }
        }
        res = min(res,white_blocks);
        while(r<n){
            if(blocks[l]=='W'){
                white_blocks--;
            }
            if(blocks[r]=='W'){
                white_blocks++;
            }
            res = min(res,white_blocks);
            l++;
            r++;
        }
        return res;
    }
};