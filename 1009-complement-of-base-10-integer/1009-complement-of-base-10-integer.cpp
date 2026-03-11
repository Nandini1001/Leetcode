class Solution {
public:
    int bitwiseComplement(int n) {
        int no=0;
        int bits=(n)?floor(log2(n))+1:1;
        for(int i=0;i<bits;i++){
            if(!(n & (1<<i))){
                no+=pow(2,i);
            }
        }
        return no;
    }
};