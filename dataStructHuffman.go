package main

import (
	"fmt"
	"io/ioutil"
)

const (
	tableAlreadyGenerated = "The table has already been generated for this file..."
	encryptedFileAlreadyGenerated = "The encrypted file has already been generated for this file..."
)

type HuffmanFile struct {
	PathToFile string
	ContentFile string
	Table map[rune]string
	EncryptedVersion string
}

func CreateHuffmanFile (pathToFile string) *HuffmanFile {
	var res HuffmanFile

	data, err := ioutil.ReadFile(pathToFile)
	if err != nil {
		fmt.Printf("Something strange occured : %s\n", err)
		return nil
	}

	res.PathToFile = pathToFile
	res.ContentFile = string(data)
	res.Table = nil
	res.EncryptedVersion = ""
	return &res
}

func CreateHuffmanEncryptedFile (table map[rune]string, encrypt string) *HuffmanFile {
	var res HuffmanFile

	res.PathToFile = "Undefined"
	res.ContentFile = ""
	res.Table = table
	res.EncryptedVersion = encrypt
	return &res
}

func (hf *HuffmanFile) translate() {
	if hf.EncryptedVersion != "" {
		fmt.Errorf("%s\n", encryptedFileAlreadyGenerated)
		return
	}
	res := ""
	spli := []rune(hf.ContentFile)
	for _, c := range spli {
		res += hf.Table[c]
	}
	hf.EncryptedVersion = res
}

func (hf *HuffmanFile) EncryptFile () {
	if hf.Table != nil {
		fmt.Errorf("%s\n", tableAlreadyGenerated)
		return
	}
	hf.Table = GetAssociatedTable(hf.ContentFile)
	hf.translate()
}

func (hf HuffmanFile) PrettyPrint() {
	var display string
	beginLength := 20

	if len(hf.ContentFile) < beginLength {
		beginLength = len(hf.ContentFile)
	}

	display = "File path : \"" + hf.PathToFile + "\"\n"
	display += "\n"
	display += "Beginning of the file :\n\t"
	display += hf.ContentFile[:beginLength]
	display += "\n\n"
	display += "Huffman Table :\n"

	for key, value := range hf.Table {
		display += fmt.Sprintf("\t%q\t=>  %s\n", key, value)
	}

	display += "\n\n"
	display += "EncryptedVersion : \n\n"
	display += hf.EncryptedVersion
	display += "\n\n"

	fmt.Printf("%s", display)
}