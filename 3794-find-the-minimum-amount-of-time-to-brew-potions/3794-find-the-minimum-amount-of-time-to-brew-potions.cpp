class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size(),m=mana.size();
        vector<long long> finishTime(n,0);
        for(int j=0;j<m;j++)
        {
            finishTime[0]+=1LL*(mana[j]*skill[0]);

            for(int i=1;i<n;i++)
            {
                finishTime[i] = max(finishTime[i], finishTime[i-1]) + 1LL * (skill[i] * mana[j]);
            }

            for(int i=n-1;i>0;i--)
            {
                finishTime[i-1]=finishTime[i]-1LL*(skill[i]*mana[j]);
            }
        }
        return finishTime[n-1];
    }

    //We are doing (1-blindly assign and finishTime ke acc assign again) for every potion
    //TC: O(m*n)
    //SC: O(n)
};


// t=0;
// 5  30 40 60 
// 61 66 68 72 
//we are wasting most of the time here ncs wizard0 is free after 5s 
// if we choose 5+1*1=6 but after 6 w1 must come immediately but here it was busy with above till 30 sec 
//5 30 40 60
//6 35 42 64 jese he ik free hua vese he iind assign kr diya 


//wizard --> potion 
//when he is free from its previous potion[j-1] 
//when wizad[i-1] has completed his potion 
// __| for particular i we have to look these two values
// max(potion[i],wizard[i-1])+(skills[i]*mana[j]);

//synchronization
//64 se phele kab aaya tha 64->60 || 64-(skill[i]*potion[j])(we will correct previous positions value)
//finish[i-1]=finish[i]-(skill[i]*potion[j])   //Backtraking also used here (1-blindly assign and finishTime ke acc assign again)
//use this with the help of vector