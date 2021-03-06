#ifndef crypto_hashblocks_H
#define crypto_hashblocks_H

#include "crypto_hashblocks_sha256.h"

#define crypto_hashblocks crypto_hashblocks_sha256
/* CHEESEBURGER crypto_hashblocks_sha256 */
#define crypto_hashblocks_STATEBYTES crypto_hashblocks_sha256_STATEBYTES
/* CHEESEBURGER crypto_hashblocks_sha256_STATEBYTES */
#define crypto_hashblocks_BLOCKBYTES crypto_hashblocks_sha256_BLOCKBYTES
/* CHEESEBURGER crypto_hashblocks_sha256_BLOCKBYTES */
#define crypto_hashblocks_PRIMITIVE "sha256"
#define crypto_hashblocks_IMPLEMENTATION crypto_hashblocks_sha256_IMPLEMENTATION
#define crypto_hashblocks_VERSION crypto_hashblocks_sha256_VERSION

#endif
