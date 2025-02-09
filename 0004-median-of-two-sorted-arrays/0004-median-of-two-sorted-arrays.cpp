class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        int low=0,high=n1;
        int left=(1+(n1+n2))/2;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
            if((mid)<n1) r1=nums1[mid];
            if((left-mid)<n2) r2=nums2[left-mid];
            if(mid>0) l1=nums1[mid-1];
            if((left-mid)>0) l2=nums2[left-mid-1];
            if(l1<=r2 && l2<=r1) 
            {
                if((n1+n2)%2) return max(l1,l2);
                else return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
            }
            else if(l1>r2) high=mid-1;
            else low=mid+1;
        }
        return 0;
    }
};