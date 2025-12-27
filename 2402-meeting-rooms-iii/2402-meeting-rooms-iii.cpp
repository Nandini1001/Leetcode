class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];   
    }

    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> cnt(n,0);
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>,
        greater<pair<long long,long long>>> pq, free;
        int firstunusedroom=0;
        sort(meetings.begin(), meetings.end(), comp);
        for(auto it:meetings){
            while(!pq.empty() && pq.top().first<=it[0]){
                auto topp=pq.top();
                pq.pop();
                free.push({topp.second,topp.first});
            }
            if(!free.empty()){
                auto topp=free.top();
                free.pop();
                pq.push({it[1],topp.first});
                cnt[topp.first]++;
            }
            else if(firstunusedroom<n){
                pq.push({it[1],firstunusedroom});
                cnt[firstunusedroom]++;
                firstunusedroom++;
            }
            else{
                auto topp=pq.top();
                pq.pop();
                long long newend=topp.first-it[0]+it[1];
                pq.push({newend,topp.second});
                cnt[topp.second]++;
            }
            
        }
        int anscnt=-1, ansind=-1;
        for(int i=0;i<n;i++){
            if(anscnt<cnt[i]){
                anscnt=cnt[i];
                ansind=i;
            }
        }
        return ansind;
    }
};