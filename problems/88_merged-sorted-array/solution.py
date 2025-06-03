class Solution(object):
    def merge(self, nums1, m, nums2, n):
        # we know they are sorted so, and there is padding of size in to allow insertion.
        # We can start with the highest numbers in nums1 and the highest numbers in nums2
        # and merge sort the into the back of nums1 itself
        print(f"{nums1=}")
        print(f"{m=}")
        print(f"{nums2=}")
        print(f"{n=}\n")

        i = m - 1
        j = n - 1
        k = m + n - 1

        print(nums1[i])
        print(nums2[j])

        while j >= 0:
            print(f"{nums1[i]=}")
            print(f"{nums2[j]=}")
            print(f"{k=}")
            print(f"before: {nums1=}")

            if (nums1[i] > nums2[j]):
                print("branch1")
                nums1[k] = nums1[i]
                i -= 1
            elif (nums1[i] < nums2[j]):
                print("branch2")
                nums1[k] = nums2[j]
                j -= 1
            elif (nums1[i] == nums2[j]):
                print("branch3")
                nums1[k] = nums2[j]
                j -= 1

            print(f"after: {nums1=}\n")

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
