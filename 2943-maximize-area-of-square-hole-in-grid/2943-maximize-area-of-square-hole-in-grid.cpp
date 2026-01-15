class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int maxh=1, maxv=1, curmax=1;
        for(int i=1;i<hBars.size();i++){
            if(hBars[i]-1==hBars[i-1]) curmax++;
            else{
                maxh=max(maxh, curmax);
                curmax=1;
            }
        }
        maxh=max(maxh, curmax);
        curmax=1;
        for(int i=1;i<vBars.size();i++){
            if(vBars[i]-1==vBars[i-1]) curmax++;
            else{
                maxv=max(maxv, curmax);
                curmax=1;
            }
        }
        maxv=max(maxv, curmax);
        int maxside=min(maxh,maxv)+1;
        return maxside*maxside;
    }
};