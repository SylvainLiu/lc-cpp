package backtrack

func permute(nums []int) [][]int {
	if len(nums) == 0 {
		return nil
	}

	result := [][]int{}
	cur := []int{}
	used := make([]bool, len(nums))
	backtrack(nums, cur, used, &result)
	return result
}

func backtrack(nums, cur []int, used []bool, res *[][]int) {
	if len(nums) == len(cur) {
		tmp := make([]int, len(nums))
		copy(tmp, cur)
		*res = append(*res, tmp)
		return
	}

	for i := 0; i < len(nums); i++ {
		if used[i] {
			continue
		}

		cur = append(cur, nums[i])
		used[i] = true
		backtrack(nums, cur, used, res)

		cur = cur[:len(cur)-1]
		used[i] = false
	}
}
