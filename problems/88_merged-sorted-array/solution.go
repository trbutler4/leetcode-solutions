package main

import "fmt"

//"sort"

// solution using std
/*
 func merge(nums1 []int, m int, nums2 []int, n int) {
	nums1 = append(nums1[:m], nums2...)
	sort.Ints(nums1)
	fmt.Println(nums1)
 }
*/

// two pointer approach (optimal)
func merge(nums1 []int, m int, nums2 []int, n int) {
	fmt.Printf("Input nums1: %v\n", nums1)
	fmt.Printf("Input m: %d\n", m)
	fmt.Printf("Input nums2: %v\n", nums2)
	fmt.Printf("Input n: %d\n", n)
	i := m - 1
	j := n - 1
	k := m + n - 1

	for j >= 0 {
		fmt.Printf("\nCurrent array state: %v\n", nums1)
		fmt.Printf("Comparing at positions - i: %d, j: %d, k: %d\n", i, j, k)
		fmt.Printf("Values being compared - nums1[i]: %d, nums2[j]: %d\n", nums1[i], nums2[j])

		if i >= 0 && nums1[i] > nums2[j] {
			nums1[k] = nums2[i]
			fmt.Printf("Moving nums1[%d]=%d to position %d\n", i, nums1[i], k)
			i -= 1
		} else {
			nums1[k] = nums2[j]
			fmt.Printf("Moving nums2[%d]=%d to position %d\n", j, nums2[j], k)
			j -= 1
		}
		k -= 1

		fmt.Printf("After move array state: %v\n", nums1)
	}

}

func main() {
	nums1 := &[]int{1, 2, 3, 0, 0, 0}
	m := 3
	nums2 := []int{2, 5, 6}
	n := 3
	merge(*nums1, m, nums2, n)
	fmt.Println(nums1)
}
