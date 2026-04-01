class Solution {
public:
    struct robot{
        int ind;
        int health;
        int position;
    };
    static bool comp(robot a, robot b){
        return a.position<b.position;
    }
    static bool comp1(pair<int,int> a, pair<int,int> b){
        return a.first<b.first;
    }
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<robot> arr(healths.size());
        for(int i=0; i<healths.size(); i++){
            arr[i].ind=i;
            arr[i].position=positions[i];
            if(directions[i]=='L') arr[i].health=-healths[i];
            else arr[i].health=healths[i];
        }
        sort(arr.begin(), arr.end(), comp);
        stack<pair<int,int>> st;
        for(int i=0; i<arr.size(); i++){
            if(arr[i].health>0) st.push({arr[i].ind,arr[i].health});
            else{
                while(!st.empty() && st.top().second>0 && st.top().second<abs(arr[i].health)){
                    st.pop();
                    arr[i].health++;
                }
                if(!st.empty() && st.top().second>0){
                    if(st.top().second==abs(arr[i].health))
                        st.pop();
                    else{
                        auto top=st.top();
                        st.pop();
                        top.second--;
                        st.push(top);
                    }
                }
                else if(st.empty() || st.top().second<0)
                    st.push({arr[i].ind,arr[i].health});
            }
        }
        vector<pair<int,int>> rem_robot;
        while(!st.empty()){
            rem_robot.push_back(st.top());
            st.pop();
        }
        sort(rem_robot.begin(), rem_robot.end(), comp1);
        vector<int> ans;
        for(int i=0; i<rem_robot.size(); i++){
            ans.push_back(abs(rem_robot[i].second));
        }
        return ans;
    }
};