package main

var (
	listFiles = []string{
		"assets/simple.txt",
		"assets/lorem1.txt",
		"assets/mandarin1.txt",
	}
)

func main () {
	for _, filePath := range listFiles {
		hf := CreateHuffmanFile(filePath)
		hf.EncryptFile()
		hf.PrettyPrint()
	}
}