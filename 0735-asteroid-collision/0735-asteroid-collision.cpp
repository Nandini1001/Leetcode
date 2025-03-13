class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        list<int> st;
        vector<int> ans;
        for(int i=0;i<asteroids.size();i++)
        {
            if(asteroids[i]>0)
                st.push_back(asteroids[i]);
            else
            {
                while(!st.empty()&&st.back()>0&&st.back()<abs(asteroids[i]))
                    st.pop_back();
                if(!st.empty() && st.back()==abs(asteroids[i]))
                    st.pop_back();
                else if(st.empty() || st.back()<0)
                    st.push_back(asteroids[i]);
            }
        }
        while(!st.empty()){
            ans.push_back(st.front());
            st.pop_front();
    }
        return ans;
    }
};