class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        for(int i=digits.size()-1;i>=0;i--){
            if(digits[i]+carry <10) { digits[i]=digits[i]+carry;carry=0;}
            else if(digits[i]+carry>=10){ digits[i]=0;}
        }
        if (carry==0) return digits;
        else{
            vector<int> result(digits.size()+1);
            result[0]=1;
            return result;
        }
        
    }
    // vector<int> shift(vector<int> &digits){

    //     vector<int> result(digits.size()+1);
    //     for(int i=0;i<digits.size();i++){
    //         result[i+1]=digits[i];
    //     }
    //     result[0]=1;
    //     return result;
    // }
};
