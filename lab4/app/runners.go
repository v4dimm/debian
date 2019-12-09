package main

import (
	"fmt"
	"time"
	"math/rand"
)

func doRun(area int) {
	for i := 0; i < area; i++ {
		var barrier int = rand.Intn(2);
		if (barrier != 0) {
			amt := time.Duration(rand.Intn(4))
			time.Sleep(time.Millisecond * amt)
			fmt.Println("barrier number: ", i, "\n")
		}
	}
}

func main() {
	hight := rand.Intn(25);
	runners := 3;
	area := hight * runners;

	for i := 0; i < runners; i++ {
        fmt.Println("Runner ", i + 1, "start\n");        
		go doRun(area);
	}

	var input string
	fmt.Scanln(&input)
}