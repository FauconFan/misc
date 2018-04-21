package main

import (
	"fmt"
	"io/ioutil"
)

func main () {
	pathToFile := "assets/lorem1.txt"
	
	data, _ := ioutil.ReadFile(pathToFile)
	fmt.Println(string(data))
}