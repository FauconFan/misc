package main

import (
	"fmt"
	"io/ioutil"
)

func translate(data string, table map[rune]string) string {
	res := ""
	spli := []rune(data)
	for _, c := range spli {
		res += table[c]
	}
	return res
}

func main () {
	pathToFile := "assets/lorem1.txt"
	
	data, err := ioutil.ReadFile(pathToFile)
	if err != nil {
		fmt.Printf("Something strange occured : %s\n", err)
		return 
	}
	content := string(data)
	table := GetAssociatedTab(content)

	translated := translate(content, table)
	fmt.Printf("%s\n", translated)
}