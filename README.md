# `passgen`
`passgen` is a command-line application (written in C++) to generate passwords. It supports all options that a password generator normally supports. You can define the password length you want, or include numbers, special characters, lower case and upper case letters in the output password.

## Table of contents

- [🛠 How to build](#🛠-how-to-build);
- [⚙️ Usage](#⚙️-usage);

## 🛠 How to build

A `Makefile` is available to build `passgen`. To use this `Makefile`, you need to have GNU `Make` and GNU `g++` compiler installed on your machine. If you have these tools already installed, you can clone this repository with:

```
git clone https://github.com/pedropark99/passgen.git
```

And, then, use the `make` command inside the `passgen` folder to compile the source code. As a result, the binary executable for `passgen` will be generated inside the `build` folder:

```
cd passgen
make
```

## ⚙️ Usage

After the installation, you can open your command line and use the command `passgen`. A 10-characters random password will be printed to the console as a result:

```sh
passgen
```
```
HdeMNJwudc
```

The `passgen` command comes with some built-in options, which you can use to change some characteristics of the passwords that are generated. By default, `passgen` will create a 10-characters password that can contain upper and lower case Basic-Latin letters. However, you can set the password length you want with the `-l` argument:

```sh
passgen -l 25
```
```
XoRNmYibtNOWPXwiAKkzrexZp
```

You can use the `-n` flag to include numbers in the character set for your password:

```sh
passgen -l 13 -n
```
```
k8RA2ml2vk4uX
```

If you want, you can generate a "number-only" password by including numbers in the character set (with the `-n` flag), and, excluding the upper and lower case Basic-Latin letters (with the `-o` and `-u` flags):

```sh
passgen -l 8 -n -o -u
```
```
44883027
```

### List of available command line options

The `passgen` comes with some built-in command line options. Most of these options are used to *include* or *exclude* a specific set of characters from the character set that will be used to generate your passwords:

- `-l` or `--length`: define the length of your password (default to 10). This option expects a integer as argument;
- `-p` or `--number-of-passwords`: the number of passwords to be generated (default to 1). This option expects a integer as argument;
- `-u` or `--no-upper-case-letters`: exclude the Basic-Latin upper case letters from the character set;
- `-o` or `--no-lower-case-letters`: exclude the Basic-Latin lower case letters from the character set;
- `-s` or `--special-chars`: include special characters (e.g. `$`, `%`, `#`, `@` etc.) in the character set;
- `-n` or `--numbers`: include numbers (e.g. `0`, `1`, `2`, etc.) in the character set;
- `-v` or `--version`: prints the current version of the `passgen` program;
- `-h` or `--help`: prints the help documentation;
