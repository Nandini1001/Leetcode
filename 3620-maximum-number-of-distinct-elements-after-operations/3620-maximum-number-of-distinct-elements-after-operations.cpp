class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int last = INT_MIN;  // last chosen distinct value
        int count = 0;

        for (int num : nums) {
            // allowed range for this element
            int left = num - k;
            int right = num + k;

            // choose the smallest possible distinct number
            int val = max(left, last + 1);

            if (val <= right) {
                count++;
                last = val;
            }
            // else, we skip — can't assign distinct value
        }

        return count;
    }
};


//prev done by me TC=n*(2*k+1)+nlogn
//optimise nlogn
