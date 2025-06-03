package main

import "fmt"

func merge(nums1 []int, m int, nums2 []int, n int) {
	i := m - 1
	j := n - 1
	k := m + n - 1

	for j >= 0 && i >= 0 {
		if nums1[i] > nums2[j] {
			nums1[k] = nums1[i]
			i = i - 1
		} else {
			nums1[k] = nums2[j]
			j = j - 1
		}
		k = k - 1
	}
	for j >= 0 {
		nums1[k] = nums2[j]
		j = j - 1
		k = k - 1
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
