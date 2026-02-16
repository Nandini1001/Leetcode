class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(), n2=nums2.size();
        int totalleft=ceil((n1+n2)/2.0);
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        int low=0, high=n1;
        while(low<=high){
            int mid=(low+high)/2;
            int l1=((totalleft-mid-1)>=0)?nums2[totalleft-mid-1]:INT_MIN;
            int l2=((mid-1)>=0)?nums1[mid-1]:INT_MIN;
            int r1=((totalleft-mid)<n2)?nums2[totalleft-mid]:INT_MAX;
            int r2=((mid)<n1)?nums1[mid]:INT_MAX;
            if((l1<=r2) && (l2<=r1)){
                if((n1+n2)%2) return max(l1,l2);
                return ((max(l1,l2)+min(r1,r2))/2.0);
            }
            if(l1>r2) low=mid+1;
            else if(l2>r1) high=mid-1;
        }
        return 0;
    }
};