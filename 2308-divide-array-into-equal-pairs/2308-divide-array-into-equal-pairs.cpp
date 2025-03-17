class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_multiset<int> s;
        int pair=nums.size()/2;
        for(auto i:nums)
        {
            if(!s.empty())
            {
                if(s.find(i)!=s.end())
                {
                    s.erase(i);
                    pair--;
                }
                else
                    s.insert(i);
            }
            else
                s.insert(i);
        }
        return s.empty();
    }
};