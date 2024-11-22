
# 👤INFO ABOUT GET NEXT LINE

This project is about a function that can read a line from a file and show the line in the standart output, then always that you call de function, it will return a line from de text in the file.

## Bonus Part

The bonus part is just to read a line by differents files. For example, you read the first line by file 1, when you call the function again but to file 2, it will return the first line of file 2. So, the function will know wich line must read with a variadic files.

![Logo](https://github.com/mcombeau/mcombeau/blob/main/42_badges/get_next_linem.png?raw=true)
## How to use

To use the project you can git clone the repository

```bash
  git@github.com:gabrielbastossobral/get_next_line.git
```
Inside of the project, you should create a file with some text, then you need to create a main.c wich you call the function

With a main created, you gonna compile (personally I preffer to put some flags to verify errors that can be happens)
```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c
```

If you want, you can use a BUFFER_SIZE, just put on the compile -D BUFFER_SIZE=10 for example.

## Running tests

To see automatized tests that show us differents tests about buffer_size and for example empty file or even 1 million characters in the file, you should git clone the francinette

```bash
  bash -c "$(curl -fsSL https://raw.github.com/xicodomingues/francinette/master/bin/install.sh)"
```

GitHub about francinette:


- [@francinette](https://github.com/xicodomingues/francinette)


## Author

- [@gabrielbastossobral](https://www.github.com/gabrielbastossobral)
