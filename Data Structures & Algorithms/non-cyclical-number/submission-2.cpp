class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hset;
        int sum =0;
        int cn=n;
        while(true)
        {  
           
            while(cn>0)
            {
                int r= cn % 10;
                sum = sum + r*r;
                cn = cn/10;
            }
            
            if(sum==1){return true;}
            else if(hset.count(sum)) {return false;}
            else {hset.insert(sum);}
            cn=sum;
            sum =0;

        }
        return false;
    }
};
