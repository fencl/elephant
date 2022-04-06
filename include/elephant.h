#pragma once
#ifndef _elephant_h_
#define _elephant_h_

/* /============================================================================\
 * | Thread-safe variant allocates buffers on the stack (few KiB).              |
 * | This might not be tolerable in some cases.                                 |
 * \============================================================================/
 */
#ifndef ELEPHANT_THREADSAFE
#define ELEPHANT_THREADSAFE 1
#endif

/* /============================================================================\
 * | Elephant - DEFLATE decoder.                                                |
 * |============================================================================|
 * | in      | input data buffer (read in bytes, least to most significant bit) |
 * | out     | output data buffer (has to be big enough, no overflow checking)  |
 * |============================================================================|
 * | returns | number of bytes written to the output buffer                     |
 * \============================================================================/
 */
unsigned inflate(const void *restrict in, void *restrict out);

#endif
