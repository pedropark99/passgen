# `passgen`
`passgen` is a command-line application (written in C++) to generate passwords. It supports all options that a password generator normally supports. You can define the password length you want, or include numbers, special characters, lower case and upper case letters in the output password.

- [🛠 How to build](#🛠-how-to-build);
- ⬇️ How to install;
- [⚙️ Usage](#⚙️-usage);

# 🛠 How to build

A `Makefile` is available to build `passgen`. To use this `Makefile`, you need to have GNU `Make` and GNU `g++` compiler installed on your machine. If you have these tools already installed, you can clone this repository with:

```
git clone https://github.com/pedropark99/passgen.git
```

And, then, use the `make` command inside the `passgen` folder to compile the source code. As a result, the binary executable for `passgen` will be generated inside the `build` folder:

```
make
```

# ⚙️ Usage

After the installation, you can open your command line and use the command `passgen`. A 10-digit random password will be generated and printed to the console as a result:

```sh
passgen
```
```
HdeMNJwudc
```

The `passgen` command have some arguments, which you can use to change some characteristics of the passwords that are generated. By default, `passgen` will create a 10-digit password that can contain upper and lower case ANSI letters. However, you can set the password length you want with the `-l` argument:

```sh
passgen -l 25
```
```
XoRNmYibtNOWPXwiAKkzrexZp
```

Or, you can use the `-n` flag to include numbers in the character set for your password:

```sh
passgen -l 13 -n
```
```
k8RA2ml2vk4uX
```

If you want, you can generate a "number-only" password by including the numbers (with the `-n` flag), and, excluding the upper and lower case ANSI letters of your caracter set (with the `-o` and `-u` flags):

```sh
passgen -l 8 -n -o -u
```
```
44883027
```