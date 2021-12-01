package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func check(e error) {
	if e != nil {
		panic(e)
	}
}

func main() {
	f, err := os.ReadFile("input.txt")
	check(err)
	res := strings.Split(string(f), "\n")
	counter := 0
	previous := -1
	for _, s := range res {
		i, err := strconv.Atoi(s)
		check(err)
		if previous != -1 && i > previous {
			counter = counter + 1
		}

		previous = i
	}

	fmt.Println(counter)
}
