package main

// this solution is very fast but uses a lot of memory
func RemoveDuplicates(nums []int) int {
	seen := make(map[int]int)
	num_unique := 0
	unique := []int{}

	for i := 0; i < len(nums); i += 1 {
		_, is_seen := seen[nums[i]]
		if !is_seen {
			seen[nums[i]] = 1
			num_unique += 1
			unique = append(unique, nums[i])
		}
	}

	copy(nums, unique)
	return num_unique
}

func main() {}
