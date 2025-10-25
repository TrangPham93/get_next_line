#  get_next_line

The function reads from a file descriptor and **returns one line at a time**, no matter the line length or buffer size.

In this project, I learn about
- File descriptors and system calls (`read`)
- Dynamic memory allocation (`malloc`, `free`)
- Managing **persistent data** between function calls (using `static` variables)

## Function Prototype

```c
char *get_next_line(int fd);
```

## Usage
### Requirement: 
Linux OS
### Installment:
#### 1. Clone the Repository
   ```bash
   git clone https://github.com/TrangPham93/get_next_line.git getNextLine
   cd getNextLine
   ```
#### 2. Compile the Project
To compile both the mandatory and bonus
```bash 
cc *.c 
```
#### 3. Run
There are multiple test files included in folder tests to test the function get_next_line. 
```bash 
./a.out tests/test_file_name
```

