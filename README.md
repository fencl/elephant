# Elephant
Simple __DEFLATE__ decoder, cca 150 lines of _horrible_ __C99__ code (intentionaly, _sometimes_ I can write somewhat readable code). No heap allocation, no dependencies, no stdlib (except for single use of stdint.h which is only used for uint_least8_t and uint_least16_t and can be simplified to unsigned char and unsigned short respectively in most cases).

There is only one function exposed.
Use this function
```c
unsigned inflate(const void *restrict in, void *restrict out);
```
to decompress DEFLATE bit stream. The stream is stored in a buffer passed through the `in` argument and is read byte by byte from the least to the most significat bit. Decompressed data will be written to a buffer passed through the `out` argument. This buffer has to be big enough to hold the decompressed data.

## Configuration
In the header there is a `INFLATE_THREADSAFE` macro. If it is set to 0 (false) it means that the inflate function will be called only sequentialy and can use global variables. Those are used to store the huffman trees and other tables. In case the macro is set to 1, the library will allocate those trees and tables on the stack. This amounts to cca 4 additional KiB on the stack and might not be tolerable in cases where the stack is quite limited.

## Compilation
There is no need for build system and so no build system or script is provided. Just add elephant.c in your sources and elephant.h in your include directories.

## Remarks
This library has no error codes, asserts or any runtime checks whatsoever. The input stream has to be correct otherwise your program will output garbage or more likely crash.

## License
```
Copyright (c) 2022 Matej Fencl
Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
```
