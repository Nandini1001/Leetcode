class Solution {
public:
    int strStr(string haystack, string needle) {
        /*int h=0, n=0;
        int start=-1;
        int hsize=haystack.size(), nsize=needle.size();
        while(h<hsize ){
            if(haystack[h]==needle[n]){
                n++;
                if(start==-1)
                    start=h;
            }
            else{
                start=-1;
                n=0;
            }
            h++;
            if(n==nsize) return start;
        }
        return -1;*/
        int n = haystack.length();
    int m = needle.length();

    if (m == 0) return 0;        // Edge case: empty needle

    for (int i = 0; i <= n - m; ++i) {
        int j = 0;
        // Use two pointers to compare each character
        while (j < m && haystack[i + j] == needle[j]) {
            ++j;
        }
        if (j == m) {
            return i; // Found full match
        }
    }

    return -1;
    }
};