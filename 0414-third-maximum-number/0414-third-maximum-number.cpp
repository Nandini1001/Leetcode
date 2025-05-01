class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long l=LLONG_MIN, sl=LLONG_MIN, tl=LLONG_MIN;
        for(int i:nums){
            if(i>l){
                tl=sl;
                sl=l;
                l=i;
            }
            else if(i>sl && i!=l){
                tl=sl;
                sl=i;
            }
            else if(i>tl && i!=sl && i!=l){
                tl=i;
            }
        }
        if(tl==LLONG_MIN) return l;
        return tl;
    }
};