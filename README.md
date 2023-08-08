# Sorting competition
## Description
The goal is to make a c++ class that competes various sorting algorithms against each other, the fastest wins. This project will work with any numerical type as it will be implemented using templates and each algorithm is independant so it can be used outside the competition. I also want to add stupid sorting algorithms for fun.

## Requirements

To compile and execute this program you will need to have a cpp compiler (g++) and the command make installed as well. You might need to install valgrind as the rule "make run-debug" (explained in the running section) uses it. If you want to run the test you will need to have the criterion library installed.

## Compiling

### Compilation rules
The program **compiles** using make file, there are different compilation rules:
- **make** or **make build**: Compiles the source files that are necessary in with no extra flags
- **make re**: Cleans the build and compiles the source files with no extra flags
- **make debug**: Compiles the source files with the -g flag
- **make release**: Compiles the source files with the -O3 flag
- **make test**: Compiles the source files and the test files but without the main and runs the tests
- **make all**: Compiles the build, debug, release and compiles and runs the tests 
- **make full**: Cleans the build and then compiles the build, debug, release and compiles and runs the tests 

All compilation rules are independent, they all have their own build folder and binary files so compiling one rule will not affect the others.

```bash
make
# or
make build
# or
make re
# or
make debug
# or
make release
# or
make test
# or
make all
# or
make full
```

### Cleaning rules

You can **remove the build files** using the clean command as followed:

```bash
make clean # Remove all build files and delte the build folder
```

Once you are done with the project you can **remove the binary and the build files** using the fclean command as followed:

```bash
make fclean # remove all generated files and folders
```

## Running

### Binary name and locaiton

All binary files are generated in the bin folder, specific compilation rules will generate different binary files all starting with the default binary name plus a dash followed by the name of the rule

*(example: binary-debug)*

### Running commands

The makefile include running commands that will run the binary files for you, the commands are as followed:

```bash
make run # run the binary file
make run-debug # run the binary-debug file with valgrind
make run-release # run the binary-release file
make run-test # run the binary-test file
```

You can also run the binary files manually, they are located in the bin folder and are named as followed:
- **SortingCompetition**
- **SortingCompetition-debug**
- **SortingCompetition-release**
- **SortingCompetition-test**

To see what arguments the program can take, execute the generated binary with the "-h" parameter such as followed:

```bash
./bin/SortingCompetition -h # display help
```

For this project the program do not required any arguments so to run the program you can simply execute one of the following commands:

```bash
./bin/SortingCompetition # run the SortingCompetition file
# or
valgrind ./bin/SortingCompetition-debug # run the SortingCompetition-debug file with valgrind
# or
./bin/SortingCompetition-release # run the SortingCompetition-release file
# or
./bin/SortingCompetition-test # run the tests
```
To run program manually the following command (dont forget to respect the arguments required):

```bash
./bin/SortingCompetition [optional_arguments, ...]
```