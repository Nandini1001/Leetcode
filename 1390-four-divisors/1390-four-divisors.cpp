class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int maxelement=*max_element(nums.begin(),nums.end());
        vector<int> noofdivisors(maxelement+1,2);
        noofdivisors[1]=1;
        sieveoferatosthenes(noofdivisors);
        int sum=0;
        for(auto i:nums){
            if(noofdivisors[i]==4){
                for(int j=1; j*j<=i;j++){
                    if(i%j==0){
                        sum+=j;
                        if(i/j!=j) 
                            sum+=(i/j);
                    }
                }
            }
        }
        return sum;
    }
    void sieveoferatosthenes(vector<int>& noofdivisors){
        for(int i=2;i<noofdivisors.size();i++){
            int flag=1;
            for(int j=i+i; j<noofdivisors.size();j+=i){
                flag=0;
                noofdivisors[j]++;
            }
            if(flag) break;
        }
    }
};