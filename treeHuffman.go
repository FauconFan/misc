package main

type Tree struct {
    Left  *Tree
    Right *Tree
    Value rune
    ProbActu float64
}

type returnBuildingCode struct {
	Code string
	Char rune
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
