/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums,int numsSize,int target,int* returnsize)
{
    int *returnarray=(int*)malloc(2*sizeof(int));
    for(int i=0;i<numsSize;i++)
    {
        for(int j=i+1;j<numsSize;j++)
        {   
                if(nums[i]+nums[j]==target)
                {
                    *returnsize=2;
                    returnarray[0]=i;
                    returnarray[1]=j;
                    return returnarray;
                }
        }
    }
    *returnsize=0;
    return NULL;
}