class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hset;
        int i=0;
        int sum =0;
        int cn=n;
        while(true)
        {   i++;
           
            while(cn>0)
            {
                int r= cn % 10;
                sum = sum + r*r;
                cn = cn/10;
            }
            cout<<endl<<endl<<"Iteration "<< i<<endl;
            if(sum==1){cout<<"Sum is 1 so returned true"<<endl;return true;}
            else if(hset.count(sum)) {cout<<"Sum found on hset"<<sum<<endl;return false;}
            else {cout<<"New sum inserted into hset"<<sum<<endl;hset.insert(sum);}
            cn=sum;
            sum =0;

        }
        return false;
    }
};
