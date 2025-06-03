#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (j >= 0 && i >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

void case1() {
    int nums1[] = {1,2,3,0,0,0};
    int nums1Size = 6;
    int m = 3;
    int nums2[] = {2,5,6};
    int nums2Size = 3;
    int n = 3;

    merge(nums1, nums1Size, m, nums2, nums2Size, n);

    for(int i = 1; i < nums1Size; i++) {
        if(nums1[i] < nums1[i-1]) {
            printf("Test case 1 failed: array not sorted\n");
            return;
        }
    }
    printf("Test case 1 passed\n");
}

void case2() {
    // edge case
    int nums1[] = {0};
    int nums1Size = 1;
    int m = 0;
    int nums2[] = {1};
    int nums2Size = 1;
    int n = 1;

    merge(nums1, nums1Size, m, nums2, nums2Size, n);

    for(int i = 1; i < nums1Size; i++) {
        if(nums1[i] < nums1[i-1]) {
            printf("Test case 2 failed: array not sorted\n");
            return;
        }
    }
    printf("Test case 2 passed\n");
}

void case3() {
    // edge case
    int nums1[] = {2,0};
    int nums1Size = 2;
    int m = 1;
    int nums2[] = {1};
    int nums2Size = 1;
    int n = 1;

    merge(nums1, nums1Size, m, nums2, nums2Size, n);

    for(int i = 1; i < nums1Size; i++) {
        if(nums1[i] < nums1[i-1]) {
            printf("Test case 3 failed: array not sorted\n");
            return;
        }
    }
    printf("Test case 3 passed\n");
}

void case4() {
    // edge case
    int nums1[] = {0};
    int nums1Size = 1;
    int m = 0;
    int nums2[] = {1};
    int nums2Size = 1;
    int n = 1;

    merge(nums1, nums1Size, m, nums2, nums2Size, n);

    for(int i = 1; i < nums1Size; i++) {
        if(nums1[i] < nums1[i-1]) {
            printf("Test case 4 failed: array not sorted\n");
            return;
        }
    }
    printf("Test case 4 passed\n");
}

int main() {
    case1();
    case2();
    case3();
    case4();
    return 0;
}
