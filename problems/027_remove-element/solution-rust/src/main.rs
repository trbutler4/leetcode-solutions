struct Solution {}

impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut i = 0;
        let mut j = 0;
        let mut num_not_equal = 0;

        while i < nums.len() {
            if nums[i] == val {
                nums[i] = -1;
            } else {
                num_not_equal += 1;
                nums[j] = nums[i];
                j += 1;
            }

            i += 1;
        }

        num_not_equal
    }
}

fn main() {
    // Case 1
    let mut nums1 = vec![3, 2, 2, 3];
    let val1 = 3;
    let expected_return1 = 2;

    let result1 = Solution::remove_element(&mut nums1, val1);
    println!("result={}", result1);
    println!("nums={:?}", nums1);
    assert_eq!(result1, expected_return1);

    // Case 2
    let mut nums2 = vec![0, 1, 2, 2, 3, 0, 4, 2];
    let val2 = 2;
    let expected_return2 = 5;

    let result2 = Solution::remove_element(&mut nums2, val2);
    println!("result={}", result2);
    println!("nums={:?}", nums2);
    assert_eq!(result2, expected_return2);
}
