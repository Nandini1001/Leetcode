class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        for(int i=1;i<words.size();i++){
            if(isanagram(words[i-1],words[i])){
                words.erase(words.begin()+i);
                i--;}
        }
        return words;
    }
    bool isanagram(string s1, string s2){
        /*multiset<char> st;
        for(auto i:s1) st.insert(i);
        for(auto i:s2){
            if(st.find(i)!=st.end()) st.erase(st.find(i));
            else return false;
        }
        return st.empty();*/
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        return s1==s2;
    }
};



//1 answer there is a problem in anagram function i.e. it is not giving correct for string1 aa and string2 a as we are just checking whether all the elements of s2 are present in s1 or not what if s1 contains all elements of s2 but s1 contains more elements so instead of true we write st.empty();
//in all wrong answers there is a problem in anagram and  in ans1 main logic we are changing words itself and in ans2 and ans3, ans4 main logic use seperate ans
//ans5 is main logic of ans2 and correct anagram and ans6 is main logic of ans2 and correct anagram