def main():
    driver_handle = open('/proc/trey_driver') # Open the driver file
    message_from_kernel_space = driver_handle.readline()
    print("Message from kernel space: " + message_from_kernel_space)
    driver_handle.close()
    print("Exiting user application.")
    return

main()