class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed)
    {
        unordered_map<int,int>hashmap;
        stack<int> st;
        int relv,p1,p2,sp1,sp2,c=0;
        float t1,t2;
        int n=position.size();
        for(int i=0;i<n;i++){
            hashmap[position[i]]=speed[i];
        }
        sort(position.begin(),position.end());
        int carAhead=position[n-1];

        for(int i=n-1;i>=0;i--){
           
                p1=carAhead;
                p2=position[i];
                sp1=hashmap[p1];
                sp2=hashmap[p2];
                relv=sp2-sp1;
                if(relv>0){
               
                  
                    t1=(float)(target-p1)/sp1;
                    t2=(float)(p1-p2)/relv;
                    if(t2<=t1)
                    {
                        carAhead=p1;

                    }
                    else{
                        carAhead=p2;
                        c=c+1;
                    }


                    
                }
                 else{
                        carAhead=p2;
                        c=c+1;
                    }
                
            

        }
        return c;
        
        
    }
   
};