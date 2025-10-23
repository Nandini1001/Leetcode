class Solution {
public:
    bool hasSameDigits(string s) {
        while(1){
            string news="";
            for(int i=1;i<s.size();i++){
                news+=to_string(((s[i-1]-'0')+(s[i])-'0')%10);
            }
            if(news.size()==2) return news[0]==news[1];
            s=news;
        }
        return false;
    }
};