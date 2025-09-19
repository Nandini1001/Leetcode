int removeElement(int* nums, int numsSize, int val) {
    int k=0;
    for(int j=0;j<numsSize;j++)
    {
        if(nums[j]!=val)
        {
            nums[k]=nums[j];
            k++;
        }
    }
    return k;
}