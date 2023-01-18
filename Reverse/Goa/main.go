package main

import "fmt"

func foo() {

	nums := []int{98, 117, 101, 116, 123, 115, 49, 109, 112, 108, 51, 95, 103, 48, 108, 52, 110, 103, 95, 98, 49, 110, 52, 114, 121, 125}
	
	for i:=0; i < len(nums); i++ {
		fmt.Printf("%c", nums[i])
	}

	fmt.Println()

}

func main() {
	fmt.Println("Welcome to GOA! Enjoy your stay.")

	var i int

	fmt.Print("Type a number: ")
	fmt.Scan(&i)

	if (i == 2137219831273212) {
		foo()
	}

}