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
	previousWindow := -1
	for i := 2; i < len(res); i++ {
		a, err := strconv.Atoi(res[i])
		check(err)
		b, err := strconv.Atoi(res[i-1])
		check(err)
		c, err := strconv.Atoi(res[i-2])
		check(err)
		currentWindow := a + b + c
		check(err)

		if previousWindow != -1 && currentWindow > previousWindow {
			counter = counter + 1
		}

		previousWindow = currentWindow
	}

	fmt.Println(counter)
}
