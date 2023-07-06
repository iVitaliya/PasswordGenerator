package main

import (
	"fmt"
	"math/rand"
	"strconv"
	"strings"
	"time"

	"github.com/iVitaliya/logger-go/utils"
)

var chars []rune

func main() {
	for {
		fmt.Println("\nWhich other symbols would you like to include? (1=special, 2=numbers, 3=special + numbers)")
		var other string
		fmt.Scanln(&other)

		addChars(&chars, other)

		fmt.Println("How long would you like your password to be? (1-30)")
		var lenStr string
		fmt.Scanln(&lenStr)

		if length, err := strconv.Atoi(lenStr); err == nil {
			fmt.Println(utils.FormatString("\n\nHere's your new password: {0}", []string{
				generatePassword(length),
			}))
		}
	}
}

func generatePassword(length int) string {
	sb := strings.Builder{}
	rnd := rand.New(rand.NewSource(time.Now().UnixNano()))
	j := 0

	for j < length {
		sb.WriteRune(chars[rnd.Intn(len(chars))])
		j++
	}

	return sb.String()
}

func addChars(chars *[]rune, additionals string) {
	for c := 'a'; c <= 'z'; c++ {
		*chars = append(*chars, c)
	}

	for c := 'A'; c <= 'Z'; c++ {
		*chars = append(*chars, c)
	}

	switch additionals {
	case "1":
		for c := '!'; c <= '?'; c++ {
			*chars = append(*chars, c)
		}
		break
	case "2":
		for c := '0'; c <= '9'; c++ {
			*chars = append(*chars, c)
		}
		break
	case "3":
		for c := '!'; c <= '?'; c++ {
			*chars = append(*chars, c)
		}
		for c := '0'; c <= '9'; c++ {
			*chars = append(*chars, c)
		}
		break
	default:
		fmt.Println("\nYour choice didn't meet any of the given choices so I didn't add any special/numberic characters")
		break
	}
}
