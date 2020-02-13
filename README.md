# C20

C20 is a C version of my D20 Python program.

It's a command line program that rolls D&D dice.

### Installation

```
$ git clone https://github.com/breakthatbass/D20.git
```
cd to the directory
```
$ cd C20 or cd path/to/C20
```
complile with Make
```
$ make dice
```

### Usage

This program takes one mandatory argument and two optional arguments.

The first argument is the type of die to roll (e.g. d20) which by default it rolls once.

The second argument is a number which tells the program the amount of rolls to do if there are more than one roll wanted.

The third argument is a modifier which is a number with '+' or '-' in front of it.

run with one of 6 dice: d4, d6, d8, d10, d12, d20
```
$ ./dice die
```
or with additional arguments
```
$ ./dice die rolls modifier
```
Example with all three arguments
```
$ ./dice d20 3 +3
```
which might return something like
```
-----------
Base roll is 7
Modifier is +3
Roll 1 is 10.
-----------
Roll 2 is 20. Critical hit!
-----------
Base roll is 13
Modifier is +3
Roll 3 is 16
-----------
```
If you would like to use the command ```roll``` in place of ```python dice.py```, add this function to your ```.bash_profile``` after compiling:

``` bash
function roll 
{ 
  ~/path/to/c20/dice $1 $2 $3 
}
```