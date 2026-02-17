class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        if(turnedOn>8) return {};
        vector<string> ans;
        for(int hr=0;hr<=11;hr++){
            for(int min=0;min<=59;min++){
                if(__builtin_popcount(hr)+__builtin_popcount(min)==turnedOn){
                    string time;
                    time=to_string(hr)+":";
                    if(min<10){
                        time+="0"+to_string(min);
                    }
                    else time+=to_string(min);
                    ans.push_back(time);
                }
            }
        }
        return ans;
    }
};