# GET NEXT LINE PROJECT

![get_next_line_bonus_badge](https://github.com/byaliego/42-project-badges/raw/main/badges/get_next_linem.png)

## Description

This project implements a function called `get_next_line` that reads a file, line by line, from a file descriptor. It's designed to handle input efficiently by reading the file byte by byte, returning each line as it is read. This is a common exercise in 42SP Network curriculum and helps in understanding file I/O in C.

## What I Learned

- Reading files and handling file descriptors in C
- Working with bytes and memory buffers
- Writing compact algorithms
- Using static variables and macros
- Managing dynamic memory allocation (heap)

## How to Run

1. **Clone this repository** and make sure you have a C compiler installed.
2. **Edit `main.c`** (or create your own) to open your desired text file:
    ```c
    open("YOUR_TEXT_FILE.txt", O_RDONLY);
    ```
3. **Compile the project:**
    ```sh
    cc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c main.c
    ```
4. **Run the executable:**
    ```sh
    ./a.out
    ```

You can use the provided `main.c` or write your own to test different files.
