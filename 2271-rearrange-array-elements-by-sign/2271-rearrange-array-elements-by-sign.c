/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* rearrangeArray(int* nums, int numsSize, int* returnSize) {
    int posIndex=0;
    int negIndex=1;
    int *ans=(int*)malloc(numsSize*sizeof(int));
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]>0)
        {
            ans[posIndex]=nums[i];
            posIndex+=2;
        }
        else
        {
            ans[negIndex]=nums[i];
            negIndex+=2;
        }
    }
    *returnSize=numsSize;
    return ans;
}