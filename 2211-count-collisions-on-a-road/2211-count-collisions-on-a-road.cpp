class Solution {
public:
    int countCollisions(string d) {
        int n = d.size();
        int i = 0, j = n - 1;

        // Remove cars that never collide
        while (i < n && d[i] == 'L') i++;
        while (j >= 0 && d[j] == 'R') j--;

        int ans = 0;

        // Count only L and R in the middle
        for (int k = i; k <= j; k++) {
            if (d[k] == 'L' || d[k] == 'R')
                ans++;
        }

        return ans;
    }
};
