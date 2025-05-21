`// TODO: This sucks so much`

# Datum
Welcome to Datum, a poorly and quickly engineered library for parsing the Datum file and information format. I wrote this quick library for usage in my own software but decided to release it incase anyone wanted to expand upon it or use it or anything. Nothing impressive, just a fun knack.

Datum is still a work-in-progress and I just started working on quite recently. So at the time of writing this it is extremely simplistic and was thrown together quite quickly. However, overhauls and additionss are planned and on the to-do list.

# Usage in C++

In your C++ project, make sure you link datum.dll and include the "datum/datum.hpp" header file where ever you wish to use Datum.

Start by creating a Datum context with:

 `Datum::Context *datum = new Datum::context("path/to/file", true)`

Whats going on here?

The Datum context is the main object for interacting with and reading your target datum file. The constructor takes two arguments: a general string and a bool flag.

The bool determines whether or not you are reading from a file or from the string directly. If the bool is set to true, the string will be treated as a path to the file. If the bool is false, the string will be treated as an array of bytes that equates to the content of a Datum file.

As of now, Datum supports 4 types of data:
- Strings
- 8-bit integers
- 16-bit integers
- 32 bit integers

Each data type is stored in its own vector within the Datum context. The Datum file (or string) will be read and parsed immediatly upon calling the constructor. Once you `new` the context object you can begin pulling data from the vectors.

To access your data, use the "at" functions in the context object. For instance:

```
uint8_t x = datum->At_int8(0);
uint16_t y = datum->At_int16(0);
std::string z = datum->At_string(0);
```

Take note: Each element type is stored independently from eachother, and thus, ordered differently in the vectors. So if your datum file has a string, then a 16-bit integer, then another string, the first string will be element 0 in the string vector, the second string will be element 1 in the vector, and the 16-bit integer will be element 0 in the int16 vector.

# Datum file format
The Datum file format is incrediably simplistic. The Datum library will read your file and perform an operation based on the instruction byte. Heres a list of instructions and their usage:

## 01 - String until null
This will read all bytes as characters until a 0x00 byte is reached, stored in a string.

Example in a hex editor:

`01 48 69 2E 00`

This will give you "Hi." in the string vector.

## 02 - String until set size
This will read a set number of bytes as characters, stored in a string.

Immediatly after the `02` byte, the next 4 bytes (in Big-Endian) will define an unsigned 32-bit integer. That integer will be how many bytes you wish to read as a string.

Example in a hex editor:

`02 00 00 00 03 48 69 2E`

This will give you "Hi." in the string vector.

## 03 - Integer

This will read an integer. Whether or not you will read an 8-bit, 16-bit, or 32-bit integer will be determined by the byte immediatly following the `03` byte.

This will always read in Big-Endian

`03 01` will read the next byte as an 8-bit integer.

`03 02` will read the next two bytes as a 16-bit integer.

`03 03` will read the next four bytes as a 32-bit integer.

Example in a hex editor:

`03 02 07 80` will read a 16-bit integer and put `1920` into the 16-bit integer vector.

# Compiling

Grab yourseslf the latest copy of GNU Make and G++, I use MinGW-64

I'm haven't tested the compilation on Linux but I'd imagine it would work. :shrugs:

In a bash terminal, run `make` in the root folder to compile

You can also run `make full_clean` to delete the output library, all object files, and all precompiled headers.

The output will be in `build`, that folder will contain the DLL and a folder containing the header files you'll need to include in your project.

Oh, and have a 64 bit machine :^)