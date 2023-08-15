# The Neku and Favour Shell(NAFSH)

**Nafsh** is a basic Unix command line interpreter written in C, designed to replicate some of the functionality of the standard Unix shell (sh). It provides users with a simple interface to interact with the underlying operating system through a command line interface.

This project is intended to serve as an educational tool and starting point for those looking to understand the fundamentals of shell scripting and command line interpretation.

## Features
**Command Execution**: Execute basic shell commands such as ls, cd, echo, etc.

**I/O Redirection**: Redirect standard input and output using < and >.

**Piping**: Chain commands together using the | operator.

**Built-in Commands**: Implement a subset of built-in commands like exit and help.

**Signal Handling**: Handle signals like Ctrl+C gracefully.

## Getting Started
Follow these steps to get the Simple Shell up and running on your local machine.

- Clone the Repository: Start by cloning this repository to your local machine.
```shell
git clone https://github.com/your-username/simple-shell.git nafsh
```
- Compile the Shell: Navigate to the cloned repository's directory and compile the shell using the provided Makefile.

```shell
cd nafsh
make
``` 
- Run the Shell: After compiling, you can run the shell by simply executing the binary.

```shell
./nafsh
```
## Usage
Once the Shell is running, you can start entering commands. The shell supports various features like command execution, I/O redirection, piping. Here are some examples:

- Execute a command:

```shell
nafsh$ ls -l
```
- Redirect input from a file and output to a file:

```shell
nafsh$ sort < input.txt > output.txt
```
- Pipe commands together:

```shell
- Copy code
nafsh$ cat file.txt | grep "pattern"
```

- Use built-in commands:

```shell
simple-shell$ help
simple-shell$ exit
```