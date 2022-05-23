#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;
    if (numsSize < 3)
        return NULL;
    qsort(nums, numsSize, sizeof(int), cmp);
    int **ans = (int **)malloc(sizeof(int *) * numsSize * numsSize);
    *returnColumnSizes = (int *)malloc(sizeof(int) * numsSize * numsSize);
    int i, j, k, sum;

    int indexLeft = 0;
    int indexMiddle = 0;
    int indexRight = 0;
    //快排过后，使用三指针 遍历
    //左边遍历到倒数第三位即可
    for (indexLeft = 0; indexLeft < numsSize - 2; indexLeft++) {
        if (nums[indexLeft] > 0) {
            //因为是快排的结果，所以如果出现大零的
            //后面的值都是大于0的
            return ans;
        }

        //如果值相同 则不需要遍历
        if (indexLeft > 0 && nums[indexLeft] == nums[indexLeft - 1])
            continue;
        indexMiddle = indexLeft + 1;
        indexRight = numsSize - 1;

        //双指遍历 找到所有的可能
        while (indexMiddle < indexRight) {
            sum = nums[indexLeft] + nums[indexMiddle] + nums[indexRight];

            if (sum == 0) {
                ans[*returnSize] = (int *)malloc(sizeof(int) * 3);
                (*returnColumnSizes)[*returnSize] = 3;
                ans[*returnSize][0] = nums[indexLeft];
                ans[*returnSize][1] = nums[indexMiddle];
                ans[*returnSize][2] = nums[indexRight];
                *returnSize += 1;
                //过滤相等的值
                while (indexMiddle < indexRight && nums[indexMiddle] == nums[++indexMiddle])
                    ;
                while (indexMiddle < indexRight && nums[indexRight] == nums[--indexRight])
                    ;
            } else if (sum > 0) {
                //左边递减
                indexRight--;
            } else {
                //右边递增
                indexMiddle++;
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    return 0;
}
