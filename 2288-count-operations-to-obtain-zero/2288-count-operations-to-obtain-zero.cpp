class Solution {
public:
    int countOperations(int num1, int num2) {
        int ans=0;
        while(num1!=0 && num2!=0){
            if(num1>=num2){
                ans+=num1/num2;
                num1=num1%num2;
            }
            else{
                ans+=num2/num1;
                num2=num2%num1;
            }
        }
        return ans;
    }
    
};


//this is iterative approach of prev and since prev also takes space this don't take any space
//this take O(log(max(num1,num2))) both time 