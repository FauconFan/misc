package main

import (
	"fmt"
)

var (
	listFiles = []string{
		"assets/easy1.txt",
		"assets/easy2.txt",
		"assets/easy3.txt",
		"assets/lorem1.txt",
		"assets/lorem2.txt",
		"assets/lorem3.txt",
		"assets/lorem4.txt",
		"assets/mandarin1.txt",
		"assets/mandarin2.txt",
		"assets/mandarin3.txt",
		"assets/simple1.txt",
		"assets/simple2.txt",
		"assets/simple3.txt",
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