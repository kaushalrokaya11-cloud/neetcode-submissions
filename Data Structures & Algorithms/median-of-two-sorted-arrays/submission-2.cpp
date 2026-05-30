class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int total =nums1.size()+ nums2.size();
        int half = (total +1)/2;
        if(nums2.size()<nums1.size()){swap(nums1,nums2);}

        int l =-1;
        int r= nums1.size()-1;
        int i,j;

        while(l<=r)// When does this condition get violated ?
        {
            i= l+(r-l)/2;
            j= half-(i+1)-1;
            cout<<" value of i:"<<i << " "<< " The value of j: "<< j;

            int aLeft = (i>=0)? nums1[i]: INT_MIN;
            int aRight= (i<(int)nums1.size()-1)? nums1[i+1]: INT_MAX;
            int bLeft = (j>=0) ? nums2[j]: INT_MIN; // Is checking b necessary?
            int bRight= (j< (int)nums2.size()-1)? nums2[j+1]: INT_MAX;
            

            if(aLeft<=bRight && bLeft <=aRight ){
                if( total % 2 == 1){
                    cout<<"Entered true and odd"<< "The values are"
                    << aLeft<<" " <<aRight<<" "<< bLeft<<" "<<bRight;return max(aLeft,bLeft);}
                else {cout<<"Entered true and even";return (max(aLeft,bLeft)+min(aRight, bRight))/2.0;}
            }
            else if(aRight < bLeft){
                l= i+1;
            }
            else {
                r= i-1;
            }
        }
        return -1;

    }
};
