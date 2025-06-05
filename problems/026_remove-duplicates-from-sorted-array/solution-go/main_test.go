package main

import (
	"slices"
	"testing"
)

func TestRemoveDuplicates(t *testing.T) {
	nums := []int{1, 1, 2}
	expected_output := 2
	expected_nums := []int{1, 2}

	result := RemoveDuplicates(nums)

	if result != expected_output {
		t.Errorf("result %d does not equal expected %d", result, expected_output)
	}
	if !slices.Equal(nums[:result], expected_nums) {
		t.Errorf("result %d does not equal expected %d", nums, expected_nums)
	}
}
