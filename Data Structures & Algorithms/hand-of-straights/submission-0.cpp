class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(),hand.end());
        unordered_map<int,int> freq;

        for(auto h: hand){
            freq[h]++;
        }
        for(int i=0;i<hand.size();i++){
            if(freq[hand[i]]==0)continue;
            for(int j=0;j<groupSize;j++){
                if(!freq.count(hand[i]+j) || freq[hand[i]+j]==0) return false;
                else freq[hand[i]+j]--;
            }
            
        }
        return true;


    }
   
};
