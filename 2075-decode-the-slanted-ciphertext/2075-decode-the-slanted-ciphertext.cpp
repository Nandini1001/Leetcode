class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int size=encodedText.size();
        int cols=size/rows;
        string ans;
        int notobeadded=cols+1;
        for(int j=0; j<cols; j++){
            ans+=encodedText[j];
            for(int i=1; i<rows; i++){
                if(j+(notobeadded)*i>=size) break;
                ans+=encodedText[j+(notobeadded)*i];
            }
        }
        while(!ans.empty() &&ans.back()==' ')
            ans.pop_back();
        return ans;
    }
};