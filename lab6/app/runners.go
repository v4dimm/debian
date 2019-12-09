package main

import (
    "fmt"
    "time"
    "math/rand"
    "strconv"
)

func runner1(c chan string) {
    for i := 0; i < 25; i++ {
        var barrier int = rand.Intn(2);
		if (barrier != 0) {
            c <- "barrier number: " + strconv.Itoa(i);
        }
    }
}

func runner2(c chan string) {
    for i := 0; i < 25; i++ {
        var barrier int = rand.Intn(2);
		if (barrier != 0) {
            c <- "(2) barrier number: " + strconv.Itoa(i);
        }
    }
}

func printer(c chan string) {
    for {
        msg := <- c
        fmt.Println(msg)
        time.Sleep(time.Second * 1)
    }
}
func main() {
    var c chan string = make(chan string)

    go runner1(c)
    go runner2(c)
    go printer(c)

    var input string
    fmt.Scanln(&input)
}