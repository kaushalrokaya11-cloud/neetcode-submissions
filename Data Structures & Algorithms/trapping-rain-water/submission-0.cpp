class Solution {
public:
   int trap(vector<int> &height){
    int n = height.size();
    vector<int> left_max(n), right_max(n);
    int result=0;
    left_max[0]= 0; right_max[n-1]=0;
    for(int i =1;i<n;i++){

        left_max[i]= (left_max[i-1]>height[i-1])?left_max[i-1]:left_max[i]= height[i-1];
    }
    for(int i =n-2;i>=0;i--){
        right_max[i]= right_max[i+1]>height[i+1]?right_max[i+1]:height[i+1];
    }

    for(int i = 0;i<n;i++){
        int h_diff = min(left_max[i],right_max[i])- height[i];
        if(h_diff>0){
            result += h_diff;
        }
    }
    return result;

}
};
