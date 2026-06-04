class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string binary ="" ;
        for(int i=0;i<32;i++){
            if(1<<i & n){
                binary = binary+ '1';
            }
            else{
                binary = binary +'0';
            }
        }
        uint32_t res=0;
        for( int i=0;i<32;i++){
            if(binary[i]=='1')res=res|(1<<(31-i));
        }
        return res;
        
    }
};
