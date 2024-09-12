# LED state controller
An simple LED state machine from scratch

# What is this repository for

This repository contains `led_ct.c` as the main programming

# Utilities currently supported

* `int initLEDGroup` : Initializes the settings of individual LEDs and the group the are in
* `int updateLEDGroupSettings`: Updates the LED settings of the individual LEDs and the group
* `int displayLEDGroupStatus`: Displays the statuses of the LEDs

# Usage

This project is compiled using `gcc`. On a Debian GNU/Linux based system you can install it by installing the package `build-essentials` as mentioned [here](https://lists.debian.org/debian-gcc/2008/04/msg00089.html).
You compile the `led_ct.c` file using `gcc` and run the executable to test it. A template `main ` function is provided in the `led_ct.c` file.
1. Clone the repo.
2. open terminal in the project root directory.
3. Type `gcc led_ct.c -o led_ct.out` and hit `enter` key.
4. Type `./a.out`

# Contributions

If you would like to extend or add/request any functionality please create an issue or open a pull request with your changes. 
