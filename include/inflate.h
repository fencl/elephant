#pragma once
#ifndef _inflate_h_
#define _inflate_h_

/* /============================================================================\
 * | Multithreaded variant allocates buffers on the stack (few KiB).            |
 * | This might not be tolerable in some cases.                                 |
 * \============================================================================/
 */
#ifndef INFLATE_MULTITHREADED
#define INFLATE_MULTITHREADED 1
#endif

/* /============================================================================\
 * | DEFLATE decoder.                                                           |
 * |============================================================================|
 * | in      | input data buffer (read in bytes, least to most significant bit) |
 * | out     | output data buffer (has to be big enough, no overflow checking)  |
 * |============================================================================|
 * | returns | number of bytes written to the output buffer                     |
 * \============================================================================/
 */
unsigned inflate(const void *restrict in, void *restrict out);

#endif
