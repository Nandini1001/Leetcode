class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        //sort(apple.begin(),apple.end(), greater<int>());
        sort(capacity.begin(),capacity.end(), greater<int>());
        int j=0, cnt=0, rem=0;
        for(int i=0;i<apple.size();i++){
            int apples=apple[i];
            apples=apples>rem?apples-rem:0;
            rem=rem>apple[i]?rem-apple[i]:0;
            while(apples){
                cnt++;
                rem=apples<capacity[j]?capacity[j]-apples:0;
                apples=apples>capacity[j]?apples-capacity[j]:0;
                j++;
            }
        }
        return cnt;
    }
};