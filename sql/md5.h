
/* MD5.H - header file for MD5C.C
 */

/* Copyright (C) 1991-2, RSA Data Security, Inc. Created 1991. All
rights reserved.

License to copy and use this software is granted provided that it
is identified as the "RSA Data Security, Inc. MD5 Message-Digest
Algorithm" in all material mentioning or referencing this software
or this function.

License is also granted to make and use derivative works provided
that such works are identified as "derived from the RSA Data
Security, Inc. MD5 Message-Digest Algorithm" in all material
mentioning or referencing the derived work.

RSA Data Security, Inc. makes no representations concerning either
the merchantability of this software or the suitability of this
software for any particular purpose. It is provided "as is"
without express or implied warranty of any kind.

These notices must be retained in any copies of any part of this
documentation and/or software.
 */

/* GLOBAL.H - RSAREF types and constants
 */

/* PROTOTYPES should be set to one if and only if the compiler supports
  function argument prototyping.
The following makes PROTOTYPES default to 0 if it has not already
  been defined with C compiler flags.
 */

/* egcs 1.1.2 under linux didn't defined it.... :( */

#ifndef PROTOTYPES
#define PROTOTYPES 1				/* Assume prototypes */
#endif

/* POINTER defines a generic pointer type */
typedef unsigned char *POINTER;

/* UINT2 defines a two byte word */
typedef uint16 UINT2;				/* Fix for MySQL / Alpha */

/* UINT4 defines a four byte word */
typedef uint32 UINT4;				/* Fix for MySQL / Alpha */

/* PROTO_LIST is defined depending on how PROTOTYPES is defined above.
If using PROTOTYPES, then PROTO_LIST returns the list, otherwise it
  returns an empty list.
 */
#if PROTOTYPES
#define PROTO_LIST(list) list
#else
#define PROTO_LIST(list) ()
#endif
/* MD5 context. */
typedef struct {
  UINT4 state[4];                                   /* state (ABCD) */
  UINT4 count[2];        /* number of bits, modulo 2^64 (lsb first) */
  unsigned char buffer[64];                         /* input buffer */
} my_MD5_CTX;

#ifdef __cplusplus
extern "C" {
#endif
       void my_MD5Init PROTO_LIST ((my_MD5_CTX *));
       void my_MD5Update PROTO_LIST
         ((my_MD5_CTX *, unsigned char *, unsigned int));
       void my_MD5Final PROTO_LIST ((unsigned char [16], my_MD5_CTX *));

#ifdef __cplusplus
}
#endif

