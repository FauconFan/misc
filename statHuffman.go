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

type Tree struct {
    Left  *Tree
    Right *Tree
    Value rune
    ProbActu float64
}

func insertInList(list []Tree, actu Tree) []Tree {
	i := 0
	for _, value := range list {
		if value.ProbActu < actu.ProbActu {
			break
		}
		i++
	}
	res := append(list[:i], append([]Tree{actu}, list[i:]...)...)
	return res
}

func sortByProbActu(list []Tree) []Tree {
	res := make([]Tree, 0)
	for _, t := range list {
		res = insertInList(res, t)
	}
	return res
}

func genStatTree(proba map[rune]float64) Tree {
	data := make([]Tree, len(proba))
	rank := 0
	for char, value := range proba {
		data[rank] = Tree{nil, nil, char, value}
		rank++
	}
	data = sortByProbActu(data)
	for len(data) > 1 {
		la := data[len(data) - 1]
		lb := data[len(data) - 2]
		data = data[:len(data) - 2]
		ne := Tree{&la, &lb, 0, la.ProbActu + lb.ProbActu}
		data = insertInList(data, ne)
	}
	return data[0]
}

type returnBuildingCode struct {
	Code string
	Char rune
}

func travelTree(head Tree, isHead bool, code string, pipeRes chan returnBuildingCode) {
	if head.Value == 0 {
		travelTree(*head.Left, false, code + "0", pipeRes)
		travelTree(*head.Right, false, code + "1", pipeRes)
	} else {
		pipeRes <- returnBuildingCode{code, head.Value}
	}

	if isHead {
		close(pipeRes)
	}
}

func GetAssociatedTab(data string) map[rune]string {
	statData := genStat(data)
	head := genStatTree(statData)
	res := make(map[rune]string)
	pipeRes := make(chan returnBuildingCode, len(statData))
	travelTree(head, true, "", pipeRes)

	for k := range pipeRes {
		res[k.Char] = k.Code
	}

	return res
}