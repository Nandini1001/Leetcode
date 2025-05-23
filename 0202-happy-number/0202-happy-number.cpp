class Solution {
public:
    bool isHappy(int n) {
        vector<int> cycle;
        while(find(cycle.begin(),cycle.end(),n)==cycle.end()){
            cycle.push_back(n);
            int no=0;
            while(n>0){
                no+=(n%10)*(n%10);
                n=n/10;
            }
            n=no;
            if(n==1) return true;
        }
        return false;
    }
};