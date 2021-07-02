package backtrack

import (
	"strconv"
	"strings"
)

func restoreIpAddresses(s string) []string {
	res := []string{}
	if s == "" {
		return res
	}

	var dfs func(s string, pos int, cur []string, res *[]string)
	dfs = func(s string, pos int, cur []string, res *[]string) {
		if pos == len(s) && len(cur) == 4 {
			*res = append(*res, strings.Join(cur, "."))
			return
		}

		num := 0
		for i := 0; i < 3 && pos+i < len(s); i++ {
			tmp, _ := strconv.Atoi(string(s[pos+i]))
			num = 10*num + tmp

			if num > 255 {
				break
			}

			cur = append(cur, strconv.Itoa(num))

			rest := len(s) - (pos + i + 1)
			if rest < 4-(len(cur)) || rest > 3*(4-(len(cur))) {
				cur = cur[:len(cur)-1]
				if num != 0 {
					continue
				} else {
					break
				}
			}

			dfs(s, pos+i+1, cur, res)
			cur = cur[:len(cur)-1]

			if num == 0 {
				break
			}
		}
	}

	cur := make([]string, 0, 4)
	dfs(s, 0, cur, &res)
	return res
}
