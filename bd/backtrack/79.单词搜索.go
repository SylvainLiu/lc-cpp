package backtrack

func exist(board [][]byte, word string) bool {
	var dfs func(board [][]byte, word string, pos, i, j int, used [][]bool) bool
	dfs = func(board [][]byte, word string, pos, i, j int, used [][]bool) bool {
		if pos == len(word) {
			return true
		}

		if i < 0 || i >= len(board) || j < 0 || j >= len(board[0]) || used[i][j] || board[i][j] != word[pos] {
			return false
		}

		used[i][j] = true
		pos++
		res := dfs(board, word, pos, i-1, j, used) ||
			dfs(board, word, pos, i+1, j, used) ||
			dfs(board, word, pos, i, j-1, used) ||
			dfs(board, word, pos, i, j+1, used)
		if res {
			return true
		}

		used[i][j] = false
		return false
	}

	m, n := len(board), len(board[0])
	used := make([][]bool, m)
	for i := 0; i < m; i++ {
		used[i] = make([]bool, n)
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if board[i][j] == word[0] && dfs(board, word, 0, i, j, used) {
				return true
			}
		}
	}
	return false
}
