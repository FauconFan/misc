package main

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