package main

func countStat(data string) (map[rune]uint64, uint64) {
	res := make(map[rune]uint64)
	tot := uint64(0)
	spli := []rune(data)
	for _, c := range spli {
		res[c]++
	}
	for _, j := range res {
		tot += j
	}
	return res, tot
}

func genStat(data string) map[rune]float64 {
	stats, tot := countStat(data)
	res := make(map[rune]float64)

	for i, j := range stats {
		res[i] = float64(j) / float64(tot)
	}

	return res
}