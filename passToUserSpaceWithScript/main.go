package main
import (
	"fmt"
	"io/ioutil"
	"log"
	"os"
)

func main() {
    driver_handle, err := os.Open("/proc/trey_driver")
    if err != nil {
        log.Fatal(err)
    }
    defer driver_handle.Close()

    message_from_kernel_space, err := ioutil.ReadAll(driver_handle)
    if err != nil {
        log.Fatal(err)
    }

    fmt.Printf("Message from kernel space: %s\n", message_from_kernel_space)
    fmt.Println("Exiting user application.")
}
