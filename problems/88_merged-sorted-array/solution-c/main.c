#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
}

int main() {
    int nums1[] = {1,2,3,0,0,0};
    int nums1Size = 6;
    int m = 3;
    int nums2[] = {2,5,6};
    int nums2Size = 3;
    int n = 3;

    merge(nums1, nums1Size, m, nums2, nums2Size, n);

    for(int i = 0; i < nums1Size; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    return 0;
}
