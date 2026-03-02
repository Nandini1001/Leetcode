class Solution {
public:
    int candy(vector<int>& ratings) {
        int cnt=1;
        int i=1;
        while(i<ratings.size()){
            if( ratings[i-1]==ratings[i]){
                cnt++;
                i++;
                continue;
            }

            int top=1;
            while(i<ratings.size() && ratings[i-1]<ratings[i]){
                top++;
                cnt+=top;
                i++;
            }
            
            int down=1;
            while(i<ratings.size() && ratings[i-1]>ratings[i]){
                
                cnt+=down;
                i++;
                down++;
                
            }
            if(down>top) cnt+=(down-top);
        }
        return cnt;
    }
};