class Solution(object):
    def merge(self, nums1, m, nums2, n):
        i = m - 1
        j = n - 1
        k = m + n - 1

        while j >= 0:
            if (nums1[i] > nums2[j]):
                print("branch1")
                nums1[k] = nums1[i]
                i -= 1
            else:
                print("branch3")
                nums1[k] = nums2[j]
                j -= 1
            k -= 1

if __name__ == "__main__":
    nums1 = [1,2,3,0,0,0]
    m = 3
    nums2 = [2,5,6]
    n = 3
    s = Solution()
    s.merge(nums1, m, nums2, n)

    expected = [1,2,2,3,5,6]
    print(f"Expected {expected} actual {nums1}")
