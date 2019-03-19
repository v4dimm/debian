package main

import "fmt"

var input = [3][3]int{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}
var output [3][3]int

func main() {
	for i:=0; i<3; i++ {
		for j:=0; j<3; j++ {
			output[i][j] = input[j][i]
		}
	}
	fmt.Println(output)
}