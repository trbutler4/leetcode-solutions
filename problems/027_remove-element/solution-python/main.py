class Solution:
    def removeElement(self, nums: list[int], val: int) -> int:
        i = 0
        j = 0
        num_not_equal = 0
        while i < len(nums):
            if nums[i] == val:
                nums[i] = -1
            else:
                num_not_equal += 1
                nums[j] = nums[i]
                j += 1
            i += 1
        return num_not_equal


if __name__ == "__main__":
    nums = [3, 2, 2, 3]
    val = 3
    s = Solution()

    expected_return = 2

    result = s.removeElement(nums, val)
    print(f"{result=}")
    print(f"{nums=}")
    assert result == expected_return

    nums = [0,1,2,2,3,0,4,2]
    val = 2
    s = Solution()

    expected_return = 5

    result = s.removeElement(nums, val)
    print(f"{result=}")
    print(f"{nums=}")
    assert result == expected_return
