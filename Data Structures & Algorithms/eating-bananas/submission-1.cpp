class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int i=1,n=piles.size();
        sort(piles.begin(),piles.end());
        int j= piles[n-1];
        int temp;
        int k=j;
        int mid=j;
        // if(piles.empty()){
        //     return 0;
        // }
        while(i<=j){
            mid=(i+j)/2;
            temp=hoursTaken(mid,n,piles);

            
            if(temp>h){
                i=mid+1;
            }
            
            else{
                k=min(k,mid);
                j=mid-1;
            }

        }
        return k;
       
        
    }
     int hoursTaken(int &k,int n,vector<int> &piles){
            int count=0;
            
           
            for(int m=0;m<n;m++){
                count=count+(piles[m]+k-1)/k;
            }
            return count;
        }
};
