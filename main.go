package main

import (
	"fmt"
)

var (
	listFiles = []string{
		"assets/simple.txt",
		"assets/lorem1.txt",
		"assets/mandarin1.txt",
		"assets/easy.txt",
	}
)

func test() {
	for _, pathToFile := range listFiles {
		hf := CreateHuffmanFile(pathToFile)
		hf.EncryptFile()

		dec := Decrypt(hf)
		prefix := ""
		if dec == hf.ContentFile {
			prefix = "OK"
		} else {
			prefix = "NON"
		}
		fmt.Printf("%s\t<- %s\n", prefix, pathToFile)
	}
}

func main () {
	test()
}