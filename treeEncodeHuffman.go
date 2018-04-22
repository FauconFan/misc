package main

type EncodeTree struct {
    Left  *EncodeTree
    Right *EncodeTree
    Value rune
    ProbActu float64
}

type returnBuildingCode struct {
	Code string
	Char rune
}

func insertInList(list []EncodeTree, actu EncodeTree) []EncodeTree {
	i := 0
	for _, value := range list {
		if value.ProbActu < actu.ProbActu {
			break
		}
		i++
	}
	res := append(list[:i], append([]EncodeTree{actu}, list[i:]...)...)
	return res
}

func sortByProbActu(list []EncodeTree) []EncodeTree {
	res := make([]EncodeTree, 0)
	for _, t := range list {
		res = insertInList(res, t)
	}
	return res
}

func genStatTree(proba map[rune]float64) EncodeTree {
	data := make([]EncodeTree, len(proba))
	rank := 0
	for char, value := range proba {
		data[rank] = EncodeTree{nil, nil, char, value}
		rank++
	}
	data = sortByProbActu(data)
	for len(data) > 1 {
		la := data[len(data) - 1]
		lb := data[len(data) - 2]
		data = data[:len(data) - 2]
		ne := EncodeTree{&la, &lb, 0, la.ProbActu + lb.ProbActu}
		data = insertInList(data, ne)
	}
	return data[0]
}

func travelTree(head EncodeTree, isHead bool, code string, pipeRes chan returnBuildingCode) {
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

func GetAssociatedTable(data string) map[rune]string {
	statData := genStat(data)
	head := genStatTree(statData)
	res := make(map[rune]string)
	pipeRes := make(chan returnBuildingCode, len(statData))
	go travelTree(head, true, "", pipeRes)

	for k := range pipeRes {
		res[k.Char] = k.Code
	}

	if len(res) == 1 {
		for k, _ := range res {
			res[k] = "0"
		}
	}

	return res
}