class Solution {
public:
    int minOperations(string s) {
        char mustbe='0';
        int cnt1=0;
        for(char i:s){
            if(i!=mustbe) cnt1++;
            if(mustbe=='0') mustbe='1';
            else mustbe='0';
        }
        int n=s.size();
        return min(cnt1,n-cnt1);
    }
};