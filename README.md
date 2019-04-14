# CMOC-for-Thomson
Minimal library support for CMOC C compiler for the Thomson 8-bit computers

This is a minimal input/output support library to use the CMOC C compiler by Pierre Sarrazin
https://perso.b2b2c.ca/~sarrazip/dev/cmoc.html
to code programs for the Thomson 8-bit computers and their clones (i.e., Thomson Mo5/Mo6/To7/To8/To9, Olivetti Prodest PC128).

The CMOC C compiler is currently meant only for the CoCo/Dragon computers and the Vectrex console.
With this library you can use it also to write and compile programs for the Thomson computers.
I have only currently written and tested a version of the library of the M series (i.e., Thomson Mo5/Mo6, Olivetti Prodest PC128).
Support for the T series (Thomson To7/To8/To9) will be added later.

A slightly different and more complete version of this library is used in my universal game Cross Chase:
https://github.com/Fabrizio-Caruso/CROSS-CHASE

PREREQUISITES
1) A POSIX environment (e.g., Linux, Cygwin under Windows, etc.)
1) The CMOC compiler installed in your POSIX environment : https://perso.b2b2c.ca/~sarrazip/dev/cmoc.html
2) Makefile installed in your environment
3) The content of this repository or at least the provided C files

HOW TO BUILD THE EXAMPLE:
- Run: make mo5_ex1
- The produced binaries are found in the "build" directory. They can be loaded into an emulator (or real hardware). 

HOW TO LOAD THE BINARY:
- Use DCMOTO: http://dcmoto.free.fr/
- Select the model (Use any model M for the example mo5_ex) through "Options"
- Attach the .k5 file in the build directory through "Support amovibles" -> "Cassette..."
- Type: LOADM followed by EXEC
