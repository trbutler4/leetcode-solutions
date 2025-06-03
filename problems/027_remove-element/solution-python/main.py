class Solution:
    def removeElement(self, nums: list[int], val: int) -> int:
       return 0


def case1():
    nums = [3,2,2,3]
    val = 3
    s = Solution()

    expected_return = 2

    result = s.removeElement(nums, val)
    assert(result == expected_return)
    assert(nums[0] == 2)
    assert(nums[1] == 2)

if __name__ == "__main__":
    case1()
