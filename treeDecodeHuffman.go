package main

import "fmt"

type DecodeTree struct {
	Left *DecodeTree
	Right *DecodeTree
	Value rune
}

func buildNode(left *DecodeTree, right *DecodeTree) DecodeTree {
	return DecodeTree{left, right, 0}
}

func buildLeaf(value rune) DecodeTree {
	return DecodeTree{nil, nil, value}
}

func getSubMap(tab map[string]rune, prefix string) map[string]rune {
	res := make(map[string]rune)
	for k, v := range tab {
		if k[0] == prefix[0] {
			res[k[1:]] = v
		}
	}
	return res
}

func buildNextNode(tab map[string]rune) DecodeTree {
	if len(tab) == 1 {
		var r rune
		for _, v := range tab {
			r = v
		}
		return buildLeaf(r)
	}
	le := getSubMap(tab, "0")
	ri := getSubMap(tab, "1")
	leT := buildNextNode(le)
	riT := buildNextNode(ri)
	return buildNode(&leT, &riT)
}

func BuildTree(hf *HuffmanFile) DecodeTree {
	reversedTable := make(map[string]rune)

	if len(hf.Table) == 1 {
		var r rune
		for k, _ := range hf.Table {
			r = k
		}
		le := buildLeaf(r)
		return buildNode(&le, nil)
	}

	for k, v := range hf.Table {
		reversedTable[v] = k
	}
	return buildNextNode(reversedTable)
}

func AsyncDecrypt(content string, isFirstCalled bool, head *DecodeTree, pipeRune chan rune) {
	cop := head
	rank := 0
	for cop.Value == 0 {
		if content[rank] == '0' {
			cop = cop.Left
		} else {
			cop = cop.Right
		}
		rank++
	}
	pipeRune <- cop.Value
	if (rank != len(content)) {
		AsyncDecrypt(content[rank:], false, head, pipeRune)
	}
	
	if isFirstCalled {
		close(pipeRune)
	}
}

func Decrypt(hf *HuffmanFile) string {
	reverseTree := BuildTree(hf)
	res := ""
	pipeRune := make(chan rune, len(hf.EncryptedVersion))

	go AsyncDecrypt(hf.EncryptedVersion, true, &reverseTree, pipeRune)

	for r := range pipeRune {
		res += fmt.Sprintf("%c", r)
	}
	return res
}
