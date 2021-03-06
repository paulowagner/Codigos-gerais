package main

import (
	"fmt"
	"math/cmplx"
)

var (
	ToBe   bool       = false
	MaxInt uint64     = 1<<64 - 1
	z      complex128 = cmplx.Sqrt(-5 + 12i)
)

func main() {
	c := make(chan int,2)
	c <- 1
	c <- 2
	fmt.Printf(<-c)
	fmt.Printf(<-c)
}
