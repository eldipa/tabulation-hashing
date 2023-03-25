#include <stdint.h>
#include <stdlib.h>
#include "hash_impl.h"



static CYTHON_INLINE uint32_t c_hash_x_32_32(uint32_t __pyx_v_x, __Pyx_memviewslice __pyx_v_table) {
  uint32_t __pyx_v_h;
  uint32_t __pyx_v_h0;
  uint32_t __pyx_v_h1;
  uint32_t __pyx_v_h2;
  uint32_t __pyx_v_h3;
  uint32_t __pyx_v_x0;
  uint32_t __pyx_v_x1;
  uint32_t __pyx_v_x2;
  uint32_t __pyx_v_x3;
  uint32_t __pyx_r;
  size_t __pyx_t_1;
  Py_ssize_t __pyx_t_2;

  /* "tabulationhashing/c_tabulationhashing.pyx":26
 * cdef inline hash_dtype c_hash_x(input_dtype x, hash_dtype[::1] table) nogil:
 *     cdef:
 *         hash_dtype h = 0, h0, h1, h2, h3, h4, h5, h6, h7             # <<<<<<<<<<<<<<
 *         input_dtype x0, x1, x2, x3, x4, x5, x6, x7
 * 
 */
  __pyx_v_h = 0;

  /* "tabulationhashing/c_tabulationhashing.pyx":29
 *         input_dtype x0, x1, x2, x3, x4, x5, x6, x7
 * 
 *     x0 = x & 0x000000ff             # <<<<<<<<<<<<<<
 *     x1 = (x >> 8) & 0x000000ff
 *     x2 = (x >> 16) & 0x000000ff
 */
  __pyx_v_x0 = (__pyx_v_x & 0x000000ff);

  /* "tabulationhashing/c_tabulationhashing.pyx":30
 * 
 *     x0 = x & 0x000000ff
 *     x1 = (x >> 8) & 0x000000ff             # <<<<<<<<<<<<<<
 *     x2 = (x >> 16) & 0x000000ff
 *     x3 = (x >> 24) & 0x000000ff
 */
  __pyx_v_x1 = ((__pyx_v_x >> 8) & 0x000000ff);

  /* "tabulationhashing/c_tabulationhashing.pyx":31
 *     x0 = x & 0x000000ff
 *     x1 = (x >> 8) & 0x000000ff
 *     x2 = (x >> 16) & 0x000000ff             # <<<<<<<<<<<<<<
 *     x3 = (x >> 24) & 0x000000ff
 * 
 */
  __pyx_v_x2 = ((__pyx_v_x >> 16) & 0x000000ff);

  /* "tabulationhashing/c_tabulationhashing.pyx":32
 *     x1 = (x >> 8) & 0x000000ff
 *     x2 = (x >> 16) & 0x000000ff
 *     x3 = (x >> 24) & 0x000000ff             # <<<<<<<<<<<<<<
 * 
 *     # Note: table is assumed to be C-contiguous array of
 */
  __pyx_v_x3 = ((__pyx_v_x >> 24) & 0x000000ff);

  /* "tabulationhashing/c_tabulationhashing.pyx":39
 *     # With this, we can avoid the multiplication required
 *     # manage non-one strides (aka non-contiguous arrays)
 *     h0 = table[x0]             # <<<<<<<<<<<<<<
 *     h1 = table[x1 + 256]
 *     h2 = table[x2 + 256 * 2]
 */
  __pyx_t_1 = __pyx_v_x0;
  __pyx_v_h0 = (*((uint32_t *) ( /* dim=0 */ ((char *) (((uint32_t *) __pyx_v_table.data) + __pyx_t_1)) )));

  /* "tabulationhashing/c_tabulationhashing.pyx":40
 *     # manage non-one strides (aka non-contiguous arrays)
 *     h0 = table[x0]
 *     h1 = table[x1 + 256]             # <<<<<<<<<<<<<<
 *     h2 = table[x2 + 256 * 2]
 *     h3 = table[x3 + 256 * 3]
 */
  __pyx_t_2 = (__pyx_v_x1 + 0x100);
  __pyx_v_h1 = (*((uint32_t *) ( /* dim=0 */ ((char *) (((uint32_t *) __pyx_v_table.data) + __pyx_t_2)) )));

  /* "tabulationhashing/c_tabulationhashing.pyx":41
 *     h0 = table[x0]
 *     h1 = table[x1 + 256]
 *     h2 = table[x2 + 256 * 2]             # <<<<<<<<<<<<<<
 *     h3 = table[x3 + 256 * 3]
 * 
 */
  __pyx_t_2 = (__pyx_v_x2 + 0x200);
  __pyx_v_h2 = (*((uint32_t *) ( /* dim=0 */ ((char *) (((uint32_t *) __pyx_v_table.data) + __pyx_t_2)) )));

  /* "tabulationhashing/c_tabulationhashing.pyx":42
 *     h1 = table[x1 + 256]
 *     h2 = table[x2 + 256 * 2]
 *     h3 = table[x3 + 256 * 3]             # <<<<<<<<<<<<<<
 * 
 *     h = h0 ^ h1 ^ h2 ^ h3
 */
  __pyx_t_2 = (__pyx_v_x3 + 0x300);
  __pyx_v_h3 = (*((uint32_t *) ( /* dim=0 */ ((char *) (((uint32_t *) __pyx_v_table.data) + __pyx_t_2)) )));

  /* "tabulationhashing/c_tabulationhashing.pyx":44
 *     h3 = table[x3 + 256 * 3]
 * 
 *     h = h0 ^ h1 ^ h2 ^ h3             # <<<<<<<<<<<<<<
 * 
 *     if input_dtype is uint64_t:
 */
  __pyx_v_h = (((__pyx_v_h0 ^ __pyx_v_h1) ^ __pyx_v_h2) ^ __pyx_v_h3);

  /* "tabulationhashing/c_tabulationhashing.pyx":59
 *         h ^= h4 ^ h5 ^ h6 ^ h7
 * 
 *     return h             # <<<<<<<<<<<<<<
 * 
 * # Make c_hash_x callable from Python
 */
  __pyx_r = __pyx_v_h;
  goto __pyx_L0;

  /* "tabulationhashing/c_tabulationhashing.pyx":24
 * @cython.wraparound(False)
 * @cython.infer_types(True)
 * cdef inline hash_dtype c_hash_x(input_dtype x, hash_dtype[::1] table) nogil:             # <<<<<<<<<<<<<<
 *     cdef:
 *         hash_dtype h = 0, h0, h1, h2, h3, h4, h5, h6, h7
 */

  /* function exit code */
  __pyx_L0:;
  return __pyx_r;
}

static CYTHON_INLINE uint64_t c_hash_x_32_64(uint32_t __pyx_v_x, __Pyx_memviewslice __pyx_v_table) {
  uint64_t __pyx_v_h;
  uint64_t __pyx_v_h0;
  uint64_t __pyx_v_h1;
  uint64_t __pyx_v_h2;
  uint64_t __pyx_v_h3;
  uint32_t __pyx_v_x0;
  uint32_t __pyx_v_x1;
  uint32_t __pyx_v_x2;
  uint32_t __pyx_v_x3;
  uint64_t __pyx_r;
  size_t __pyx_t_1;
  Py_ssize_t __pyx_t_2;

  /* "tabulationhashing/c_tabulationhashing.pyx":26
 * cdef inline hash_dtype c_hash_x(input_dtype x, hash_dtype[::1] table) nogil:
 *     cdef:
 *         hash_dtype h = 0, h0, h1, h2, h3, h4, h5, h6, h7             # <<<<<<<<<<<<<<
 *         input_dtype x0, x1, x2, x3, x4, x5, x6, x7
 * 
 */
  __pyx_v_h = 0;

  /* "tabulationhashing/c_tabulationhashing.pyx":29
 *         input_dtype x0, x1, x2, x3, x4, x5, x6, x7
 * 
 *     x0 = x & 0x000000ff             # <<<<<<<<<<<<<<
 *     x1 = (x >> 8) & 0x000000ff
 *     x2 = (x >> 16) & 0x000000ff
 */
  __pyx_v_x0 = (__pyx_v_x & 0x000000ff);

  /* "tabulationhashing/c_tabulationhashing.pyx":30
 * 
 *     x0 = x & 0x000000ff
 *     x1 = (x >> 8) & 0x000000ff             # <<<<<<<<<<<<<<
 *     x2 = (x >> 16) & 0x000000ff
 *     x3 = (x >> 24) & 0x000000ff
 */
  __pyx_v_x1 = ((__pyx_v_x >> 8) & 0x000000ff);

  /* "tabulationhashing/c_tabulationhashing.pyx":31
 *     x0 = x & 0x000000ff
 *     x1 = (x >> 8) & 0x000000ff
 *     x2 = (x >> 16) & 0x000000ff             # <<<<<<<<<<<<<<
 *     x3 = (x >> 24) & 0x000000ff
 * 
 */
  __pyx_v_x2 = ((__pyx_v_x >> 16) & 0x000000ff);

  /* "tabulationhashing/c_tabulationhashing.pyx":32
 *     x1 = (x >> 8) & 0x000000ff
 *     x2 = (x >> 16) & 0x000000ff
 *     x3 = (x >> 24) & 0x000000ff             # <<<<<<<<<<<<<<
 * 
 *     # Note: table is assumed to be C-contiguous array of
 */
  __pyx_v_x3 = ((__pyx_v_x >> 24) & 0x000000ff);

  /* "tabulationhashing/c_tabulationhashing.pyx":39
 *     # With this, we can avoid the multiplication required
 *     # manage non-one strides (aka non-contiguous arrays)
 *     h0 = table[x0]             # <<<<<<<<<<<<<<
 *     h1 = table[x1 + 256]
 *     h2 = table[x2 + 256 * 2]
 */
  __pyx_t_1 = __pyx_v_x0;
  __pyx_v_h0 = (*((uint64_t *) ( /* dim=0 */ ((char *) (((uint64_t *) __pyx_v_table.data) + __pyx_t_1)) )));

  /* "tabulationhashing/c_tabulationhashing.pyx":40
 *     # manage non-one strides (aka non-contiguous arrays)
 *     h0 = table[x0]
 *     h1 = table[x1 + 256]             # <<<<<<<<<<<<<<
 *     h2 = table[x2 + 256 * 2]
 *     h3 = table[x3 + 256 * 3]
 */
  __pyx_t_2 = (__pyx_v_x1 + 0x100);
  __pyx_v_h1 = (*((uint64_t *) ( /* dim=0 */ ((char *) (((uint64_t *) __pyx_v_table.data) + __pyx_t_2)) )));

  /* "tabulationhashing/c_tabulationhashing.pyx":41
 *     h0 = table[x0]
 *     h1 = table[x1 + 256]
 *     h2 = table[x2 + 256 * 2]             # <<<<<<<<<<<<<<
 *     h3 = table[x3 + 256 * 3]
 * 
 */
  __pyx_t_2 = (__pyx_v_x2 + 0x200);
  __pyx_v_h2 = (*((uint64_t *) ( /* dim=0 */ ((char *) (((uint64_t *) __pyx_v_table.data) + __pyx_t_2)) )));

  /* "tabulationhashing/c_tabulationhashing.pyx":42
 *     h1 = table[x1 + 256]
 *     h2 = table[x2 + 256 * 2]
 *     h3 = table[x3 + 256 * 3]             # <<<<<<<<<<<<<<
 * 
 *     h = h0 ^ h1 ^ h2 ^ h3
 */
  __pyx_t_2 = (__pyx_v_x3 + 0x300);
  __pyx_v_h3 = (*((uint64_t *) ( /* dim=0 */ ((char *) (((uint64_t *) __pyx_v_table.data) + __pyx_t_2)) )));

  /* "tabulationhashing/c_tabulationhashing.pyx":44
 *     h3 = table[x3 + 256 * 3]
 * 
 *     h = h0 ^ h1 ^ h2 ^ h3             # <<<<<<<<<<<<<<
 * 
 *     if input_dtype is uint64_t:
 */
  __pyx_v_h = (((__pyx_v_h0 ^ __pyx_v_h1) ^ __pyx_v_h2) ^ __pyx_v_h3);

  /* "tabulationhashing/c_tabulationhashing.pyx":59
 *         h ^= h4 ^ h5 ^ h6 ^ h7
 * 
 *     return h             # <<<<<<<<<<<<<<
 * 
 * # Make c_hash_x callable from Python
 */
  __pyx_r = __pyx_v_h;
  goto __pyx_L0;

  /* "tabulationhashing/c_tabulationhashing.pyx":24
 * @cython.wraparound(False)
 * @cython.infer_types(True)
 * cdef inline hash_dtype c_hash_x(input_dtype x, hash_dtype[::1] table) nogil:             # <<<<<<<<<<<<<<
 *     cdef:
 *         hash_dtype h = 0, h0, h1, h2, h3, h4, h5, h6, h7
 */

  /* function exit code */
  __pyx_L0:;
  return __pyx_r;
}

static CYTHON_INLINE uint32_t c_hash_x_64_32(uint64_t __pyx_v_x, __Pyx_memviewslice __pyx_v_table) {
  uint32_t __pyx_v_h;
  uint32_t __pyx_v_h0;
  uint32_t __pyx_v_h1;
  uint32_t __pyx_v_h2;
  uint32_t __pyx_v_h3;
  uint32_t __pyx_v_h4;
  uint32_t __pyx_v_h5;
  uint32_t __pyx_v_h6;
  uint32_t __pyx_v_h7;
  uint64_t __pyx_v_x0;
  uint64_t __pyx_v_x1;
  uint64_t __pyx_v_x2;
  uint64_t __pyx_v_x3;
  uint64_t __pyx_v_x4;
  uint64_t __pyx_v_x5;
  uint64_t __pyx_v_x6;
  uint64_t __pyx_v_x7;
  uint32_t __pyx_r;
  uint64_t __pyx_t_1;

  /* "tabulationhashing/c_tabulationhashing.pyx":26
 * cdef inline hash_dtype c_hash_x(input_dtype x, hash_dtype[::1] table) nogil:
 *     cdef:
 *         hash_dtype h = 0, h0, h1, h2, h3, h4, h5, h6, h7             # <<<<<<<<<<<<<<
 *         input_dtype x0, x1, x2, x3, x4, x5, x6, x7
 * 
 */
  __pyx_v_h = 0;

  /* "tabulationhashing/c_tabulationhashing.pyx":29
 *         input_dtype x0, x1, x2, x3, x4, x5, x6, x7
 * 
 *     x0 = x & 0x000000ff             # <<<<<<<<<<<<<<
 *     x1 = (x >> 8) & 0x000000ff
 *     x2 = (x >> 16) & 0x000000ff
 */
  __pyx_v_x0 = (__pyx_v_x & 0x000000ff);

  /* "tabulationhashing/c_tabulationhashing.pyx":30
 * 
 *     x0 = x & 0x000000ff
 *     x1 = (x >> 8) & 0x000000ff             # <<<<<<<<<<<<<<
 *     x2 = (x >> 16) & 0x000000ff
 *     x3 = (x >> 24) & 0x000000ff
 */
  __pyx_v_x1 = ((__pyx_v_x >> 8) & 0x000000ff);

  /* "tabulationhashing/c_tabulationhashing.pyx":31
 *     x0 = x & 0x000000ff
 *     x1 = (x >> 8) & 0x000000ff
 *     x2 = (x >> 16) & 0x000000ff             # <<<<<<<<<<<<<<
 *     x3 = (x >> 24) & 0x000000ff
 * 
 */
  __pyx_v_x2 = ((__pyx_v_x >> 16) & 0x000000ff);

  /* "tabulationhashing/c_tabulationhashing.pyx":32
 *     x1 = (x >> 8) & 0x000000ff
 *     x2 = (x >> 16) & 0x000000ff
 *     x3 = (x >> 24) & 0x000000ff             # <<<<<<<<<<<<<<
 * 
 *     # Note: table is assumed to be C-contiguous array of
 */
  __pyx_v_x3 = ((__pyx_v_x >> 24) & 0x000000ff);

  /* "tabulationhashing/c_tabulationhashing.pyx":39
 *     # With this, we can avoid the multiplication required
 *     # manage non-one strides (aka non-contiguous arrays)
 *     h0 = table[x0]             # <<<<<<<<<<<<<<
 *     h1 = table[x1 + 256]
 *     h2 = table[x2 + 256 * 2]
 */
  __pyx_t_1 = __pyx_v_x0;
  __pyx_v_h0 = (*((uint32_t *) ( /* dim=0 */ ((char *) (((uint32_t *) __pyx_v_table.data) + __pyx_t_1)) )));

  /* "tabulationhashing/c_tabulationhashing.pyx":40
 *     # manage non-one strides (aka non-contiguous arrays)
 *     h0 = table[x0]
 *     h1 = table[x1 + 256]             # <<<<<<<<<<<<<<
 *     h2 = table[x2 + 256 * 2]
 *     h3 = table[x3 + 256 * 3]
 */
  __pyx_t_1 = (__pyx_v_x1 + 0x100);
  __pyx_v_h1 = (*((uint32_t *) ( /* dim=0 */ ((char *) (((uint32_t *) __pyx_v_table.data) + __pyx_t_1)) )));

  /* "tabulationhashing/c_tabulationhashing.pyx":41
 *     h0 = table[x0]
 *     h1 = table[x1 + 256]
 *     h2 = table[x2 + 256 * 2]             # <<<<<<<<<<<<<<
 *     h3 = table[x3 + 256 * 3]
 * 
 */
  __pyx_t_1 = (__pyx_v_x2 + 0x200);
  __pyx_v_h2 = (*((uint32_t *) ( /* dim=0 */ ((char *) (((uint32_t *) __pyx_v_table.data) + __pyx_t_1)) )));

  /* "tabulationhashing/c_tabulationhashing.pyx":42
 *     h1 = table[x1 + 256]
 *     h2 = table[x2 + 256 * 2]
 *     h3 = table[x3 + 256 * 3]             # <<<<<<<<<<<<<<
 * 
 *     h = h0 ^ h1 ^ h2 ^ h3
 */
  __pyx_t_1 = (__pyx_v_x3 + 0x300);
  __pyx_v_h3 = (*((uint32_t *) ( /* dim=0 */ ((char *) (((uint32_t *) __pyx_v_table.data) + __pyx_t_1)) )));

  /* "tabulationhashing/c_tabulationhashing.pyx":44
 *     h3 = table[x3 + 256 * 3]
 * 
 *     h = h0 ^ h1 ^ h2 ^ h3             # <<<<<<<<<<<<<<
 * 
 *     if input_dtype is uint64_t:
 */
  __pyx_v_h = (((__pyx_v_h0 ^ __pyx_v_h1) ^ __pyx_v_h2) ^ __pyx_v_h3);

  /* "tabulationhashing/c_tabulationhashing.pyx":47
 * 
 *     if input_dtype is uint64_t:
 *         x4 = (x >> 32) & 0x000000ff             # <<<<<<<<<<<<<<
 *         x5 = (x >> 40) & 0x000000ff
 *         x6 = (x >> 48) & 0x000000ff
 */
  __pyx_v_x4 = ((__pyx_v_x >> 32) & 0x000000ff);

  /* "tabulationhashing/c_tabulationhashing.pyx":48
 *     if input_dtype is uint64_t:
 *         x4 = (x >> 32) & 0x000000ff
 *         x5 = (x >> 40) & 0x000000ff             # <<<<<<<<<<<<<<
 *         x6 = (x >> 48) & 0x000000ff
 *         x7 = (x >> 56) & 0x000000ff
 */
  __pyx_v_x5 = ((__pyx_v_x >> 40) & 0x000000ff);

  /* "tabulationhashing/c_tabulationhashing.pyx":49
 *         x4 = (x >> 32) & 0x000000ff
 *         x5 = (x >> 40) & 0x000000ff
 *         x6 = (x >> 48) & 0x000000ff             # <<<<<<<<<<<<<<
 *         x7 = (x >> 56) & 0x000000ff
 * 
 */
  __pyx_v_x6 = ((__pyx_v_x >> 48) & 0x000000ff);

  /* "tabulationhashing/c_tabulationhashing.pyx":50
 *         x5 = (x >> 40) & 0x000000ff
 *         x6 = (x >> 48) & 0x000000ff
 *         x7 = (x >> 56) & 0x000000ff             # <<<<<<<<<<<<<<
 * 
 *         h4 = table[x4 + 256 * 4]
 */
  __pyx_v_x7 = ((__pyx_v_x >> 56) & 0x000000ff);

  /* "tabulationhashing/c_tabulationhashing.pyx":52
 *         x7 = (x >> 56) & 0x000000ff
 * 
 *         h4 = table[x4 + 256 * 4]             # <<<<<<<<<<<<<<
 *         h5 = table[x5 + 256 * 5]
 *         h6 = table[x6 + 256 * 6]
 */
  __pyx_t_1 = (__pyx_v_x4 + 0x400);
  __pyx_v_h4 = (*((uint32_t *) ( /* dim=0 */ ((char *) (((uint32_t *) __pyx_v_table.data) + __pyx_t_1)) )));

  /* "tabulationhashing/c_tabulationhashing.pyx":53
 * 
 *         h4 = table[x4 + 256 * 4]
 *         h5 = table[x5 + 256 * 5]             # <<<<<<<<<<<<<<
 *         h6 = table[x6 + 256 * 6]
 *         h7 = table[x7 + 256 * 7]
 */
  __pyx_t_1 = (__pyx_v_x5 + 0x500);
  __pyx_v_h5 = (*((uint32_t *) ( /* dim=0 */ ((char *) (((uint32_t *) __pyx_v_table.data) + __pyx_t_1)) )));

  /* "tabulationhashing/c_tabulationhashing.pyx":54
 *         h4 = table[x4 + 256 * 4]
 *         h5 = table[x5 + 256 * 5]
 *         h6 = table[x6 + 256 * 6]             # <<<<<<<<<<<<<<
 *         h7 = table[x7 + 256 * 7]
 * 
 */
  __pyx_t_1 = (__pyx_v_x6 + 0x600);
  __pyx_v_h6 = (*((uint32_t *) ( /* dim=0 */ ((char *) (((uint32_t *) __pyx_v_table.data) + __pyx_t_1)) )));

  /* "tabulationhashing/c_tabulationhashing.pyx":55
 *         h5 = table[x5 + 256 * 5]
 *         h6 = table[x6 + 256 * 6]
 *         h7 = table[x7 + 256 * 7]             # <<<<<<<<<<<<<<
 * 
 *         h ^= h4 ^ h5 ^ h6 ^ h7
 */
  __pyx_t_1 = (__pyx_v_x7 + 0x700);
  __pyx_v_h7 = (*((uint32_t *) ( /* dim=0 */ ((char *) (((uint32_t *) __pyx_v_table.data) + __pyx_t_1)) )));

  /* "tabulationhashing/c_tabulationhashing.pyx":57
 *         h7 = table[x7 + 256 * 7]
 * 
 *         h ^= h4 ^ h5 ^ h6 ^ h7             # <<<<<<<<<<<<<<
 * 
 *     return h
 */
  __pyx_v_h = (__pyx_v_h ^ (((__pyx_v_h4 ^ __pyx_v_h5) ^ __pyx_v_h6) ^ __pyx_v_h7));

  /* "tabulationhashing/c_tabulationhashing.pyx":59
 *         h ^= h4 ^ h5 ^ h6 ^ h7
 * 
 *     return h             # <<<<<<<<<<<<<<
 * 
 * # Make c_hash_x callable from Python
 */
  __pyx_r = __pyx_v_h;
  goto __pyx_L0;

  /* "tabulationhashing/c_tabulationhashing.pyx":24
 * @cython.wraparound(False)
 * @cython.infer_types(True)
 * cdef inline hash_dtype c_hash_x(input_dtype x, hash_dtype[::1] table) nogil:             # <<<<<<<<<<<<<<
 *     cdef:
 *         hash_dtype h = 0, h0, h1, h2, h3, h4, h5, h6, h7
 */

  /* function exit code */
  __pyx_L0:;
  return __pyx_r;
}

static CYTHON_INLINE uint64_t c_hash_x_64_64(uint64_t __pyx_v_x, __Pyx_memviewslice __pyx_v_table) {
  uint64_t __pyx_v_h;
  uint64_t __pyx_v_h0;
  uint64_t __pyx_v_h1;
  uint64_t __pyx_v_h2;
  uint64_t __pyx_v_h3;
  uint64_t __pyx_v_h4;
  uint64_t __pyx_v_h5;
  uint64_t __pyx_v_h6;
  uint64_t __pyx_v_h7;
  uint64_t __pyx_v_x0;
  uint64_t __pyx_v_x1;
  uint64_t __pyx_v_x2;
  uint64_t __pyx_v_x3;
  uint64_t __pyx_v_x4;
  uint64_t __pyx_v_x5;
  uint64_t __pyx_v_x6;
  uint64_t __pyx_v_x7;
  uint64_t __pyx_r;
  uint64_t __pyx_t_1;

  /* "tabulationhashing/c_tabulationhashing.pyx":26
 * cdef inline hash_dtype c_hash_x(input_dtype x, hash_dtype[::1] table) nogil:
 *     cdef:
 *         hash_dtype h = 0, h0, h1, h2, h3, h4, h5, h6, h7             # <<<<<<<<<<<<<<
 *         input_dtype x0, x1, x2, x3, x4, x5, x6, x7
 * 
 */
  __pyx_v_h = 0;

  /* "tabulationhashing/c_tabulationhashing.pyx":29
 *         input_dtype x0, x1, x2, x3, x4, x5, x6, x7
 * 
 *     x0 = x & 0x000000ff             # <<<<<<<<<<<<<<
 *     x1 = (x >> 8) & 0x000000ff
 *     x2 = (x >> 16) & 0x000000ff
 */
  __pyx_v_x0 = (__pyx_v_x & 0x000000ff);

  /* "tabulationhashing/c_tabulationhashing.pyx":30
 * 
 *     x0 = x & 0x000000ff
 *     x1 = (x >> 8) & 0x000000ff             # <<<<<<<<<<<<<<
 *     x2 = (x >> 16) & 0x000000ff
 *     x3 = (x >> 24) & 0x000000ff
 */
  __pyx_v_x1 = ((__pyx_v_x >> 8) & 0x000000ff);

  /* "tabulationhashing/c_tabulationhashing.pyx":31
 *     x0 = x & 0x000000ff
 *     x1 = (x >> 8) & 0x000000ff
 *     x2 = (x >> 16) & 0x000000ff             # <<<<<<<<<<<<<<
 *     x3 = (x >> 24) & 0x000000ff
 * 
 */
  __pyx_v_x2 = ((__pyx_v_x >> 16) & 0x000000ff);

  /* "tabulationhashing/c_tabulationhashing.pyx":32
 *     x1 = (x >> 8) & 0x000000ff
 *     x2 = (x >> 16) & 0x000000ff
 *     x3 = (x >> 24) & 0x000000ff             # <<<<<<<<<<<<<<
 * 
 *     # Note: table is assumed to be C-contiguous array of
 */
  __pyx_v_x3 = ((__pyx_v_x >> 24) & 0x000000ff);

  /* "tabulationhashing/c_tabulationhashing.pyx":39
 *     # With this, we can avoid the multiplication required
 *     # manage non-one strides (aka non-contiguous arrays)
 *     h0 = table[x0]             # <<<<<<<<<<<<<<
 *     h1 = table[x1 + 256]
 *     h2 = table[x2 + 256 * 2]
 */
  __pyx_t_1 = __pyx_v_x0;
  __pyx_v_h0 = (*((uint64_t *) ( /* dim=0 */ ((char *) (((uint64_t *) __pyx_v_table.data) + __pyx_t_1)) )));

  /* "tabulationhashing/c_tabulationhashing.pyx":40
 *     # manage non-one strides (aka non-contiguous arrays)
 *     h0 = table[x0]
 *     h1 = table[x1 + 256]             # <<<<<<<<<<<<<<
 *     h2 = table[x2 + 256 * 2]
 *     h3 = table[x3 + 256 * 3]
 */
  __pyx_t_1 = (__pyx_v_x1 + 0x100);
  __pyx_v_h1 = (*((uint64_t *) ( /* dim=0 */ ((char *) (((uint64_t *) __pyx_v_table.data) + __pyx_t_1)) )));

  /* "tabulationhashing/c_tabulationhashing.pyx":41
 *     h0 = table[x0]
 *     h1 = table[x1 + 256]
 *     h2 = table[x2 + 256 * 2]             # <<<<<<<<<<<<<<
 *     h3 = table[x3 + 256 * 3]
 * 
 */
  __pyx_t_1 = (__pyx_v_x2 + 0x200);
  __pyx_v_h2 = (*((uint64_t *) ( /* dim=0 */ ((char *) (((uint64_t *) __pyx_v_table.data) + __pyx_t_1)) )));

  /* "tabulationhashing/c_tabulationhashing.pyx":42
 *     h1 = table[x1 + 256]
 *     h2 = table[x2 + 256 * 2]
 *     h3 = table[x3 + 256 * 3]             # <<<<<<<<<<<<<<
 * 
 *     h = h0 ^ h1 ^ h2 ^ h3
 */
  __pyx_t_1 = (__pyx_v_x3 + 0x300);
  __pyx_v_h3 = (*((uint64_t *) ( /* dim=0 */ ((char *) (((uint64_t *) __pyx_v_table.data) + __pyx_t_1)) )));

  /* "tabulationhashing/c_tabulationhashing.pyx":44
 *     h3 = table[x3 + 256 * 3]
 * 
 *     h = h0 ^ h1 ^ h2 ^ h3             # <<<<<<<<<<<<<<
 * 
 *     if input_dtype is uint64_t:
 */
  __pyx_v_h = (((__pyx_v_h0 ^ __pyx_v_h1) ^ __pyx_v_h2) ^ __pyx_v_h3);

  /* "tabulationhashing/c_tabulationhashing.pyx":47
 * 
 *     if input_dtype is uint64_t:
 *         x4 = (x >> 32) & 0x000000ff             # <<<<<<<<<<<<<<
 *         x5 = (x >> 40) & 0x000000ff
 *         x6 = (x >> 48) & 0x000000ff
 */
  __pyx_v_x4 = ((__pyx_v_x >> 32) & 0x000000ff);

  /* "tabulationhashing/c_tabulationhashing.pyx":48
 *     if input_dtype is uint64_t:
 *         x4 = (x >> 32) & 0x000000ff
 *         x5 = (x >> 40) & 0x000000ff             # <<<<<<<<<<<<<<
 *         x6 = (x >> 48) & 0x000000ff
 *         x7 = (x >> 56) & 0x000000ff
 */
  __pyx_v_x5 = ((__pyx_v_x >> 40) & 0x000000ff);

  /* "tabulationhashing/c_tabulationhashing.pyx":49
 *         x4 = (x >> 32) & 0x000000ff
 *         x5 = (x >> 40) & 0x000000ff
 *         x6 = (x >> 48) & 0x000000ff             # <<<<<<<<<<<<<<
 *         x7 = (x >> 56) & 0x000000ff
 * 
 */
  __pyx_v_x6 = ((__pyx_v_x >> 48) & 0x000000ff);

  /* "tabulationhashing/c_tabulationhashing.pyx":50
 *         x5 = (x >> 40) & 0x000000ff
 *         x6 = (x >> 48) & 0x000000ff
 *         x7 = (x >> 56) & 0x000000ff             # <<<<<<<<<<<<<<
 * 
 *         h4 = table[x4 + 256 * 4]
 */
  __pyx_v_x7 = ((__pyx_v_x >> 56) & 0x000000ff);

  /* "tabulationhashing/c_tabulationhashing.pyx":52
 *         x7 = (x >> 56) & 0x000000ff
 * 
 *         h4 = table[x4 + 256 * 4]             # <<<<<<<<<<<<<<
 *         h5 = table[x5 + 256 * 5]
 *         h6 = table[x6 + 256 * 6]
 */
  __pyx_t_1 = (__pyx_v_x4 + 0x400);
  __pyx_v_h4 = (*((uint64_t *) ( /* dim=0 */ ((char *) (((uint64_t *) __pyx_v_table.data) + __pyx_t_1)) )));

  /* "tabulationhashing/c_tabulationhashing.pyx":53
 * 
 *         h4 = table[x4 + 256 * 4]
 *         h5 = table[x5 + 256 * 5]             # <<<<<<<<<<<<<<
 *         h6 = table[x6 + 256 * 6]
 *         h7 = table[x7 + 256 * 7]
 */
  __pyx_t_1 = (__pyx_v_x5 + 0x500);
  __pyx_v_h5 = (*((uint64_t *) ( /* dim=0 */ ((char *) (((uint64_t *) __pyx_v_table.data) + __pyx_t_1)) )));

  /* "tabulationhashing/c_tabulationhashing.pyx":54
 *         h4 = table[x4 + 256 * 4]
 *         h5 = table[x5 + 256 * 5]
 *         h6 = table[x6 + 256 * 6]             # <<<<<<<<<<<<<<
 *         h7 = table[x7 + 256 * 7]
 * 
 */
  __pyx_t_1 = (__pyx_v_x6 + 0x600);
  __pyx_v_h6 = (*((uint64_t *) ( /* dim=0 */ ((char *) (((uint64_t *) __pyx_v_table.data) + __pyx_t_1)) )));

  /* "tabulationhashing/c_tabulationhashing.pyx":55
 *         h5 = table[x5 + 256 * 5]
 *         h6 = table[x6 + 256 * 6]
 *         h7 = table[x7 + 256 * 7]             # <<<<<<<<<<<<<<
 * 
 *         h ^= h4 ^ h5 ^ h6 ^ h7
 */
  __pyx_t_1 = (__pyx_v_x7 + 0x700);
  __pyx_v_h7 = (*((uint64_t *) ( /* dim=0 */ ((char *) (((uint64_t *) __pyx_v_table.data) + __pyx_t_1)) )));

  /* "tabulationhashing/c_tabulationhashing.pyx":57
 *         h7 = table[x7 + 256 * 7]
 * 
 *         h ^= h4 ^ h5 ^ h6 ^ h7             # <<<<<<<<<<<<<<
 * 
 *     return h
 */
  __pyx_v_h = (__pyx_v_h ^ (((__pyx_v_h4 ^ __pyx_v_h5) ^ __pyx_v_h6) ^ __pyx_v_h7));

  /* "tabulationhashing/c_tabulationhashing.pyx":59
 *         h ^= h4 ^ h5 ^ h6 ^ h7
 * 
 *     return h             # <<<<<<<<<<<<<<
 * 
 * # Make c_hash_x callable from Python
 */
  __pyx_r = __pyx_v_h;
  goto __pyx_L0;

  /* "tabulationhashing/c_tabulationhashing.pyx":24
 * @cython.wraparound(False)
 * @cython.infer_types(True)
 * cdef inline hash_dtype c_hash_x(input_dtype x, hash_dtype[::1] table) nogil:             # <<<<<<<<<<<<<<
 *     cdef:
 *         hash_dtype h = 0, h0, h1, h2, h3, h4, h5, h6, h7
 */

  /* function exit code */
  __pyx_L0:;
  return __pyx_r;
}








PyObject *hash_vec_full_32_32(CYTHON_UNUSED PyObject *__pyx_self, __Pyx_memviewslice __pyx_v_xvec, __Pyx_memviewslice __pyx_v_table, __Pyx_memviewslice __pyx_v_out) {
  uint32_t __pyx_v_h;
  uint32_t __pyx_v_x;
  uint32_t __pyx_v_vec_size;
  long __pyx_v_i;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  uint32_t __pyx_t_1;
  uint32_t __pyx_t_2;
  long __pyx_t_3;
  Py_ssize_t __pyx_t_4;
  __Pyx_RefNannySetupContext("__pyx_fuse_0_0hash_vec_full", 0);

  /* "tabulationhashing/c_tabulationhashing.pyx":85
 *         input_dtype x, xi
 * 
 *         uint32_t vec_size = xvec.shape[0]             # <<<<<<<<<<<<<<
 *         uint32_t row, shift, rebase
 *         uint32_t nrows
 */
  __pyx_v_vec_size = (__pyx_v_xvec.shape[0]);

  /* "tabulationhashing/c_tabulationhashing.pyx":90
 * 
 *     # Disable the GIL as this loop will not interact with the Python VM
 *     with nogil:             # <<<<<<<<<<<<<<
 *         for i in range(0, vec_size):
 *             x = xvec[i]
 */
  {
      #ifdef WITH_THREAD
      PyThreadState *_save;
      Py_UNBLOCK_THREADS
      __Pyx_FastGIL_Remember();
      #endif
      /*try:*/ {

        /* "tabulationhashing/c_tabulationhashing.pyx":91
 *     # Disable the GIL as this loop will not interact with the Python VM
 *     with nogil:
 *         for i in range(0, vec_size):             # <<<<<<<<<<<<<<
 *             x = xvec[i]
 * 
 */
        __pyx_t_1 = __pyx_v_vec_size;
        __pyx_t_2 = __pyx_t_1;
        for (__pyx_t_3 = 0; __pyx_t_3 < __pyx_t_2; __pyx_t_3+=1) {
          __pyx_v_i = __pyx_t_3;

          /* "tabulationhashing/c_tabulationhashing.pyx":92
 *     with nogil:
 *         for i in range(0, vec_size):
 *             x = xvec[i]             # <<<<<<<<<<<<<<
 * 
 *             # The C compiler should be smart enough to inline this call
 */
          __pyx_t_4 = __pyx_v_i;
          __pyx_v_x = (*((uint32_t *) ( /* dim=0 */ ((char *) (((uint32_t *) __pyx_v_xvec.data) + __pyx_t_4)) )));

          /* "tabulationhashing/c_tabulationhashing.pyx":98
 *             # Note: it should not be necessary but just to make it explicit
 *             # I'm telling Cython which specialization of c_hash_x I want to call
 *             h = c_hash_x[input_dtype, hash_dtype](x, table)             # <<<<<<<<<<<<<<
 *             out[i] = h
 * 
 */
          __pyx_v_h = c_hash_x_32_32(__pyx_v_x, __pyx_v_table);

          /* "tabulationhashing/c_tabulationhashing.pyx":99
 *             # I'm telling Cython which specialization of c_hash_x I want to call
 *             h = c_hash_x[input_dtype, hash_dtype](x, table)
 *             out[i] = h             # <<<<<<<<<<<<<<
 * 
 * 
 */
          __pyx_t_4 = __pyx_v_i;
          *((uint32_t *) ( /* dim=0 */ ((char *) (((uint32_t *) __pyx_v_out.data) + __pyx_t_4)) )) = __pyx_v_h;
        }
      }

      /* "tabulationhashing/c_tabulationhashing.pyx":90
 * 
 *     # Disable the GIL as this loop will not interact with the Python VM
 *     with nogil:             # <<<<<<<<<<<<<<
 *         for i in range(0, vec_size):
 *             x = xvec[i]
 */
      /*finally:*/ {
        /*normal exit:*/{
          #ifdef WITH_THREAD
          __Pyx_FastGIL_Forget();
          Py_BLOCK_THREADS
          #endif
          goto __pyx_L5;
        }
        __pyx_L5:;
      }
  }

  /* "tabulationhashing/c_tabulationhashing.pyx":70
 * @cython.infer_types(True)
 * @cython.cdivision(True)
 * def hash_vec_full(input_dtype[::1] xvec, hash_dtype[::1] table, hash_dtype[::1] out):             # <<<<<<<<<<<<<<
 *     # Hash a vector of numbers and save the hashes into another.
 *     #
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  __PYX_XDEC_MEMVIEW(&__pyx_v_xvec, 1);
  __PYX_XDEC_MEMVIEW(&__pyx_v_table, 1);
  __PYX_XDEC_MEMVIEW(&__pyx_v_out, 1);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
PyObject *hash_vec_full_32_64(CYTHON_UNUSED PyObject *__pyx_self, __Pyx_memviewslice __pyx_v_xvec, __Pyx_memviewslice __pyx_v_table, __Pyx_memviewslice __pyx_v_out) {
  uint64_t __pyx_v_h;
  uint32_t __pyx_v_x;
  uint32_t __pyx_v_vec_size;
  long __pyx_v_i;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  uint32_t __pyx_t_1;
  uint32_t __pyx_t_2;
  long __pyx_t_3;
  Py_ssize_t __pyx_t_4;
  __Pyx_RefNannySetupContext("__pyx_fuse_0_1hash_vec_full", 0);

  /* "tabulationhashing/c_tabulationhashing.pyx":85
 *         input_dtype x, xi
 * 
 *         uint32_t vec_size = xvec.shape[0]             # <<<<<<<<<<<<<<
 *         uint32_t row, shift, rebase
 *         uint32_t nrows
 */
  __pyx_v_vec_size = (__pyx_v_xvec.shape[0]);

  /* "tabulationhashing/c_tabulationhashing.pyx":90
 * 
 *     # Disable the GIL as this loop will not interact with the Python VM
 *     with nogil:             # <<<<<<<<<<<<<<
 *         for i in range(0, vec_size):
 *             x = xvec[i]
 */
  {
      #ifdef WITH_THREAD
      PyThreadState *_save;
      Py_UNBLOCK_THREADS
      __Pyx_FastGIL_Remember();
      #endif
      /*try:*/ {

        /* "tabulationhashing/c_tabulationhashing.pyx":91
 *     # Disable the GIL as this loop will not interact with the Python VM
 *     with nogil:
 *         for i in range(0, vec_size):             # <<<<<<<<<<<<<<
 *             x = xvec[i]
 * 
 */
        __pyx_t_1 = __pyx_v_vec_size;
        __pyx_t_2 = __pyx_t_1;
        for (__pyx_t_3 = 0; __pyx_t_3 < __pyx_t_2; __pyx_t_3+=1) {
          __pyx_v_i = __pyx_t_3;

          /* "tabulationhashing/c_tabulationhashing.pyx":92
 *     with nogil:
 *         for i in range(0, vec_size):
 *             x = xvec[i]             # <<<<<<<<<<<<<<
 * 
 *             # The C compiler should be smart enough to inline this call
 */
          __pyx_t_4 = __pyx_v_i;
          __pyx_v_x = (*((uint32_t *) ( /* dim=0 */ ((char *) (((uint32_t *) __pyx_v_xvec.data) + __pyx_t_4)) )));

          /* "tabulationhashing/c_tabulationhashing.pyx":98
 *             # Note: it should not be necessary but just to make it explicit
 *             # I'm telling Cython which specialization of c_hash_x I want to call
 *             h = c_hash_x[input_dtype, hash_dtype](x, table)             # <<<<<<<<<<<<<<
 *             out[i] = h
 * 
 */
          __pyx_v_h = c_hash_x_32_64(__pyx_v_x, __pyx_v_table);

          /* "tabulationhashing/c_tabulationhashing.pyx":99
 *             # I'm telling Cython which specialization of c_hash_x I want to call
 *             h = c_hash_x[input_dtype, hash_dtype](x, table)
 *             out[i] = h             # <<<<<<<<<<<<<<
 * 
 * 
 */
          __pyx_t_4 = __pyx_v_i;
          *((uint64_t *) ( /* dim=0 */ ((char *) (((uint64_t *) __pyx_v_out.data) + __pyx_t_4)) )) = __pyx_v_h;
        }
      }

      /* "tabulationhashing/c_tabulationhashing.pyx":90
 * 
 *     # Disable the GIL as this loop will not interact with the Python VM
 *     with nogil:             # <<<<<<<<<<<<<<
 *         for i in range(0, vec_size):
 *             x = xvec[i]
 */
      /*finally:*/ {
        /*normal exit:*/{
          #ifdef WITH_THREAD
          __Pyx_FastGIL_Forget();
          Py_BLOCK_THREADS
          #endif
          goto __pyx_L5;
        }
        __pyx_L5:;
      }
  }

  /* "tabulationhashing/c_tabulationhashing.pyx":70
 * @cython.infer_types(True)
 * @cython.cdivision(True)
 * def hash_vec_full(input_dtype[::1] xvec, hash_dtype[::1] table, hash_dtype[::1] out):             # <<<<<<<<<<<<<<
 *     # Hash a vector of numbers and save the hashes into another.
 *     #
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  __PYX_XDEC_MEMVIEW(&__pyx_v_xvec, 1);
  __PYX_XDEC_MEMVIEW(&__pyx_v_table, 1);
  __PYX_XDEC_MEMVIEW(&__pyx_v_out, 1);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
PyObject *hash_vec_full_64_32(CYTHON_UNUSED PyObject *__pyx_self, __Pyx_memviewslice __pyx_v_xvec, __Pyx_memviewslice __pyx_v_table, __Pyx_memviewslice __pyx_v_out) {
  uint32_t __pyx_v_h;
  uint64_t __pyx_v_x;
  uint32_t __pyx_v_vec_size;
  long __pyx_v_i;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  uint32_t __pyx_t_1;
  uint32_t __pyx_t_2;
  long __pyx_t_3;
  Py_ssize_t __pyx_t_4;
  __Pyx_RefNannySetupContext("__pyx_fuse_1_0hash_vec_full", 0);

  /* "tabulationhashing/c_tabulationhashing.pyx":85
 *         input_dtype x, xi
 * 
 *         uint32_t vec_size = xvec.shape[0]             # <<<<<<<<<<<<<<
 *         uint32_t row, shift, rebase
 *         uint32_t nrows
 */
  __pyx_v_vec_size = (__pyx_v_xvec.shape[0]);

  /* "tabulationhashing/c_tabulationhashing.pyx":90
 * 
 *     # Disable the GIL as this loop will not interact with the Python VM
 *     with nogil:             # <<<<<<<<<<<<<<
 *         for i in range(0, vec_size):
 *             x = xvec[i]
 */
  {
      #ifdef WITH_THREAD
      PyThreadState *_save;
      Py_UNBLOCK_THREADS
      __Pyx_FastGIL_Remember();
      #endif
      /*try:*/ {

        /* "tabulationhashing/c_tabulationhashing.pyx":91
 *     # Disable the GIL as this loop will not interact with the Python VM
 *     with nogil:
 *         for i in range(0, vec_size):             # <<<<<<<<<<<<<<
 *             x = xvec[i]
 * 
 */
        __pyx_t_1 = __pyx_v_vec_size;
        __pyx_t_2 = __pyx_t_1;
        for (__pyx_t_3 = 0; __pyx_t_3 < __pyx_t_2; __pyx_t_3+=1) {
          __pyx_v_i = __pyx_t_3;

          /* "tabulationhashing/c_tabulationhashing.pyx":92
 *     with nogil:
 *         for i in range(0, vec_size):
 *             x = xvec[i]             # <<<<<<<<<<<<<<
 * 
 *             # The C compiler should be smart enough to inline this call
 */
          __pyx_t_4 = __pyx_v_i;
          __pyx_v_x = (*((uint64_t *) ( /* dim=0 */ ((char *) (((uint64_t *) __pyx_v_xvec.data) + __pyx_t_4)) )));

          /* "tabulationhashing/c_tabulationhashing.pyx":98
 *             # Note: it should not be necessary but just to make it explicit
 *             # I'm telling Cython which specialization of c_hash_x I want to call
 *             h = c_hash_x[input_dtype, hash_dtype](x, table)             # <<<<<<<<<<<<<<
 *             out[i] = h
 * 
 */
          __pyx_v_h = c_hash_x_64_32(__pyx_v_x, __pyx_v_table);

          /* "tabulationhashing/c_tabulationhashing.pyx":99
 *             # I'm telling Cython which specialization of c_hash_x I want to call
 *             h = c_hash_x[input_dtype, hash_dtype](x, table)
 *             out[i] = h             # <<<<<<<<<<<<<<
 * 
 * 
 */
          __pyx_t_4 = __pyx_v_i;
          *((uint32_t *) ( /* dim=0 */ ((char *) (((uint32_t *) __pyx_v_out.data) + __pyx_t_4)) )) = __pyx_v_h;
        }
      }

      /* "tabulationhashing/c_tabulationhashing.pyx":90
 * 
 *     # Disable the GIL as this loop will not interact with the Python VM
 *     with nogil:             # <<<<<<<<<<<<<<
 *         for i in range(0, vec_size):
 *             x = xvec[i]
 */
      /*finally:*/ {
        /*normal exit:*/{
          #ifdef WITH_THREAD
          __Pyx_FastGIL_Forget();
          Py_BLOCK_THREADS
          #endif
          goto __pyx_L5;
        }
        __pyx_L5:;
      }
  }

  /* "tabulationhashing/c_tabulationhashing.pyx":70
 * @cython.infer_types(True)
 * @cython.cdivision(True)
 * def hash_vec_full(input_dtype[::1] xvec, hash_dtype[::1] table, hash_dtype[::1] out):             # <<<<<<<<<<<<<<
 *     # Hash a vector of numbers and save the hashes into another.
 *     #
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  __PYX_XDEC_MEMVIEW(&__pyx_v_xvec, 1);
  __PYX_XDEC_MEMVIEW(&__pyx_v_table, 1);
  __PYX_XDEC_MEMVIEW(&__pyx_v_out, 1);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
PyObject *hash_vec_full_64_64(CYTHON_UNUSED PyObject *__pyx_self, __Pyx_memviewslice __pyx_v_xvec, __Pyx_memviewslice __pyx_v_table, __Pyx_memviewslice __pyx_v_out) {
  uint64_t __pyx_v_h;
  uint64_t __pyx_v_x;
  uint32_t __pyx_v_vec_size;
  long __pyx_v_i;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  uint32_t __pyx_t_1;
  uint32_t __pyx_t_2;
  long __pyx_t_3;
  Py_ssize_t __pyx_t_4;
  __Pyx_RefNannySetupContext("__pyx_fuse_1_1hash_vec_full", 0);

  /* "tabulationhashing/c_tabulationhashing.pyx":85
 *         input_dtype x, xi
 * 
 *         uint32_t vec_size = xvec.shape[0]             # <<<<<<<<<<<<<<
 *         uint32_t row, shift, rebase
 *         uint32_t nrows
 */
  __pyx_v_vec_size = (__pyx_v_xvec.shape[0]);

  /* "tabulationhashing/c_tabulationhashing.pyx":90
 * 
 *     # Disable the GIL as this loop will not interact with the Python VM
 *     with nogil:             # <<<<<<<<<<<<<<
 *         for i in range(0, vec_size):
 *             x = xvec[i]
 */
  {
      #ifdef WITH_THREAD
      PyThreadState *_save;
      Py_UNBLOCK_THREADS
      __Pyx_FastGIL_Remember();
      #endif
      /*try:*/ {

        /* "tabulationhashing/c_tabulationhashing.pyx":91
 *     # Disable the GIL as this loop will not interact with the Python VM
 *     with nogil:
 *         for i in range(0, vec_size):             # <<<<<<<<<<<<<<
 *             x = xvec[i]
 * 
 */
        __pyx_t_1 = __pyx_v_vec_size;
        __pyx_t_2 = __pyx_t_1;
        for (__pyx_t_3 = 0; __pyx_t_3 < __pyx_t_2; __pyx_t_3+=1) {
          __pyx_v_i = __pyx_t_3;

          /* "tabulationhashing/c_tabulationhashing.pyx":92
 *     with nogil:
 *         for i in range(0, vec_size):
 *             x = xvec[i]             # <<<<<<<<<<<<<<
 * 
 *             # The C compiler should be smart enough to inline this call
 */
          __pyx_t_4 = __pyx_v_i;
          __pyx_v_x = (*((uint64_t *) ( /* dim=0 */ ((char *) (((uint64_t *) __pyx_v_xvec.data) + __pyx_t_4)) )));

          /* "tabulationhashing/c_tabulationhashing.pyx":98
 *             # Note: it should not be necessary but just to make it explicit
 *             # I'm telling Cython which specialization of c_hash_x I want to call
 *             h = c_hash_x[input_dtype, hash_dtype](x, table)             # <<<<<<<<<<<<<<
 *             out[i] = h
 * 
 */
          __pyx_v_h = c_hash_x_64_64(__pyx_v_x, __pyx_v_table);

          /* "tabulationhashing/c_tabulationhashing.pyx":99
 *             # I'm telling Cython which specialization of c_hash_x I want to call
 *             h = c_hash_x[input_dtype, hash_dtype](x, table)
 *             out[i] = h             # <<<<<<<<<<<<<<
 * 
 * 
 */
          __pyx_t_4 = __pyx_v_i;
          *((uint64_t *) ( /* dim=0 */ ((char *) (((uint64_t *) __pyx_v_out.data) + __pyx_t_4)) )) = __pyx_v_h;
        }
      }

      /* "tabulationhashing/c_tabulationhashing.pyx":90
 * 
 *     # Disable the GIL as this loop will not interact with the Python VM
 *     with nogil:             # <<<<<<<<<<<<<<
 *         for i in range(0, vec_size):
 *             x = xvec[i]
 */
      /*finally:*/ {
        /*normal exit:*/{
          #ifdef WITH_THREAD
          __Pyx_FastGIL_Forget();
          Py_BLOCK_THREADS
          #endif
          goto __pyx_L5;
        }
        __pyx_L5:;
      }
  }

  /* "tabulationhashing/c_tabulationhashing.pyx":70
 * @cython.infer_types(True)
 * @cython.cdivision(True)
 * def hash_vec_full(input_dtype[::1] xvec, hash_dtype[::1] table, hash_dtype[::1] out):             # <<<<<<<<<<<<<<
 *     # Hash a vector of numbers and save the hashes into another.
 *     #
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  __PYX_XDEC_MEMVIEW(&__pyx_v_xvec, 1);
  __PYX_XDEC_MEMVIEW(&__pyx_v_table, 1);
  __PYX_XDEC_MEMVIEW(&__pyx_v_out, 1);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}





PyObject *hash_vec_batch_32_32(CYTHON_UNUSED PyObject *__pyx_self, __Pyx_memviewslice __pyx_v_xvec, __Pyx_memviewslice __pyx_v_table, __Pyx_memviewslice __pyx_v_out, uint32_t __pyx_v_batch_len) {
  uint32_t __pyx_v_hi;
  uint32_t __pyx_v_x;
  uint32_t __pyx_v_xi;
  uint32_t __pyx_v_batch_start;
  uint32_t __pyx_v_batch_end;
  uint32_t __pyx_v_vec_size;
  uint32_t __pyx_v_row;
  uint32_t __pyx_v_shift;
  uint32_t __pyx_v_rebase;
  uint32_t __pyx_v_nrows;
  uint32_t __pyx_v_last_batch_end;
  uint32_t __pyx_v_i;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_t_1;
  uint32_t __pyx_t_2;
  uint32_t __pyx_t_3;
  uint32_t __pyx_t_4;
  size_t __pyx_t_5;
  uint32_t __pyx_t_6;
  uint32_t __pyx_t_7;
  uint32_t __pyx_t_8;
  __Pyx_RefNannySetupContext("__pyx_fuse_0_0hash_vec_batch", 0);

  /* "tabulationhashing/c_tabulationhashing.pyx":111
 *         input_dtype x, xi
 * 
 *         uint32_t batch_start = 0, batch_end = batch_len, vec_size = xvec.shape[0]             # <<<<<<<<<<<<<<
 *         uint32_t row, shift, rebase
 *         uint32_t nrows
 */
  __pyx_v_batch_start = 0;
  __pyx_v_batch_end = __pyx_v_batch_len;
  __pyx_v_vec_size = (__pyx_v_xvec.shape[0]);

  /* "tabulationhashing/c_tabulationhashing.pyx":119
 *     # by the C compiler
 *     if input_dtype is uint32_t:
 *         nrows = 4             # <<<<<<<<<<<<<<
 *     elif input_dtype is uint64_t:
 *         nrows = 8
 */
  __pyx_v_nrows = 4;

  /* "tabulationhashing/c_tabulationhashing.pyx":127
 *     # Calculate the position of the last "complete" batch
 *     # We'll handle the (possible) last incomplete batch later
 *     last_batch_end = vec_size - (vec_size % batch_len)             # <<<<<<<<<<<<<<
 * 
 *     # Disable the GIL as this loop will not interact with the Python VM
 */
  __pyx_v_last_batch_end = (__pyx_v_vec_size - (__pyx_v_vec_size % __pyx_v_batch_len));

  /* "tabulationhashing/c_tabulationhashing.pyx":130
 * 
 *     # Disable the GIL as this loop will not interact with the Python VM
 *     with nogil:             # <<<<<<<<<<<<<<
 *         # Perform 2 rounds:
 *         #   - the first round will process all the complete batches
 */
  {
      #ifdef WITH_THREAD
      PyThreadState *_save;
      Py_UNBLOCK_THREADS
      __Pyx_FastGIL_Remember();
      #endif
      /*try:*/ {

        /* "tabulationhashing/c_tabulationhashing.pyx":134
 *         #   - the first round will process all the complete batches
 *         #   - the second round will process the last incomplete batch, if any
 *         while (1):             # <<<<<<<<<<<<<<
 *             # Hash the input vector by batches.
 *             # The idea is that a batch of the input vector and output vector
 */
        while (1) {

          /* "tabulationhashing/c_tabulationhashing.pyx":151
 *             # Note: cython cannot handle range-loops with steps unknown in compile-time
 *             # See https://github.com/cython/cython/issues/1106
 *             while batch_start < last_batch_end:             # <<<<<<<<<<<<<<
 *                 # Process the batch with the first row (partial hash).
 *                 # This allows us to initialize the out vector
 */
          while (1) {
            __pyx_t_1 = ((__pyx_v_batch_start < __pyx_v_last_batch_end) != 0);
            if (!__pyx_t_1) break;

            /* "tabulationhashing/c_tabulationhashing.pyx":154
 *                 # Process the batch with the first row (partial hash).
 *                 # This allows us to initialize the out vector
 *                 for i in range(batch_start, batch_end):             # <<<<<<<<<<<<<<
 *                     x = xvec[i]
 * 
 */
            __pyx_t_2 = __pyx_v_batch_end;
            __pyx_t_3 = __pyx_t_2;
            for (__pyx_t_4 = __pyx_v_batch_start; __pyx_t_4 < __pyx_t_3; __pyx_t_4+=1) {
              __pyx_v_i = __pyx_t_4;

              /* "tabulationhashing/c_tabulationhashing.pyx":155
 *                 # This allows us to initialize the out vector
 *                 for i in range(batch_start, batch_end):
 *                     x = xvec[i]             # <<<<<<<<<<<<<<
 * 
 *                     xi = (x) & 0x000000ff
 */
              __pyx_t_5 = __pyx_v_i;
              __pyx_v_x = (*((uint32_t *) ( /* dim=0 */ ((char *) (((uint32_t *) __pyx_v_xvec.data) + __pyx_t_5)) )));

              /* "tabulationhashing/c_tabulationhashing.pyx":157
 *                     x = xvec[i]
 * 
 *                     xi = (x) & 0x000000ff             # <<<<<<<<<<<<<<
 *                     hi = table[xi]
 * 
 */
              __pyx_v_xi = (__pyx_v_x & 0x000000ff);

              /* "tabulationhashing/c_tabulationhashing.pyx":158
 * 
 *                     xi = (x) & 0x000000ff
 *                     hi = table[xi]             # <<<<<<<<<<<<<<
 * 
 *                     out[i] = hi
 */
              __pyx_t_5 = __pyx_v_xi;
              __pyx_v_hi = (*((uint32_t *) ( /* dim=0 */ ((char *) (((uint32_t *) __pyx_v_table.data) + __pyx_t_5)) )));

              /* "tabulationhashing/c_tabulationhashing.pyx":160
 *                     hi = table[xi]
 * 
 *                     out[i] = hi             # <<<<<<<<<<<<<<
 * 
 *                 # The C compiler should be smart enough to unroll this for loop
 */
              __pyx_t_5 = __pyx_v_i;
              *((uint32_t *) ( /* dim=0 */ ((char *) (((uint32_t *) __pyx_v_out.data) + __pyx_t_5)) )) = __pyx_v_hi;
            }

            /* "tabulationhashing/c_tabulationhashing.pyx":170
 *                 # If a single row fits in the cache, we will have a constant
 *                 # amount of misses.
 *                 for row in range(1, nrows):             # <<<<<<<<<<<<<<
 *                     shift = row * 8
 *                     rebase = row * 256
 */
            __pyx_t_2 = __pyx_v_nrows;
            __pyx_t_3 = __pyx_t_2;
            for (__pyx_t_4 = 1; __pyx_t_4 < __pyx_t_3; __pyx_t_4+=1) {
              __pyx_v_row = __pyx_t_4;

              /* "tabulationhashing/c_tabulationhashing.pyx":171
 *                 # amount of misses.
 *                 for row in range(1, nrows):
 *                     shift = row * 8             # <<<<<<<<<<<<<<
 *                     rebase = row * 256
 *                     for i in range(batch_start, batch_end):
 */
              __pyx_v_shift = (__pyx_v_row * 8);

              /* "tabulationhashing/c_tabulationhashing.pyx":172
 *                 for row in range(1, nrows):
 *                     shift = row * 8
 *                     rebase = row * 256             # <<<<<<<<<<<<<<
 *                     for i in range(batch_start, batch_end):
 *                         x = xvec[i]
 */
              __pyx_v_rebase = (__pyx_v_row * 0x100);

              /* "tabulationhashing/c_tabulationhashing.pyx":173
 *                     shift = row * 8
 *                     rebase = row * 256
 *                     for i in range(batch_start, batch_end):             # <<<<<<<<<<<<<<
 *                         x = xvec[i]
 * 
 */
              __pyx_t_6 = __pyx_v_batch_end;
              __pyx_t_7 = __pyx_t_6;
              for (__pyx_t_8 = __pyx_v_batch_start; __pyx_t_8 < __pyx_t_7; __pyx_t_8+=1) {
                __pyx_v_i = __pyx_t_8;

                /* "tabulationhashing/c_tabulationhashing.pyx":174
 *                     rebase = row * 256
 *                     for i in range(batch_start, batch_end):
 *                         x = xvec[i]             # <<<<<<<<<<<<<<
 * 
 *                         xi = (x >> shift) & 0x000000ff
 */
                __pyx_t_5 = __pyx_v_i;
                __pyx_v_x = (*((uint32_t *) ( /* dim=0 */ ((char *) (((uint32_t *) __pyx_v_xvec.data) + __pyx_t_5)) )));

                /* "tabulationhashing/c_tabulationhashing.pyx":176
 *                         x = xvec[i]
 * 
 *                         xi = (x >> shift) & 0x000000ff             # <<<<<<<<<<<<<<
 *                         hi = table[xi + rebase]
 * 
 */
                __pyx_v_xi = ((__pyx_v_x >> __pyx_v_shift) & 0x000000ff);

                /* "tabulationhashing/c_tabulationhashing.pyx":177
 * 
 *                         xi = (x >> shift) & 0x000000ff
 *                         hi = table[xi + rebase]             # <<<<<<<<<<<<<<
 * 
 *                         out[i] ^= hi
 */
                __pyx_t_5 = (__pyx_v_xi + __pyx_v_rebase);
                __pyx_v_hi = (*((uint32_t *) ( /* dim=0 */ ((char *) (((uint32_t *) __pyx_v_table.data) + __pyx_t_5)) )));

                /* "tabulationhashing/c_tabulationhashing.pyx":179
 *                         hi = table[xi + rebase]
 * 
 *                         out[i] ^= hi             # <<<<<<<<<<<<<<
 * 
 *                 batch_start = batch_end
 */
                __pyx_t_5 = __pyx_v_i;
                *((uint32_t *) ( /* dim=0 */ ((char *) (((uint32_t *) __pyx_v_out.data) + __pyx_t_5)) )) ^= __pyx_v_hi;
              }
            }

            /* "tabulationhashing/c_tabulationhashing.pyx":181
 *                         out[i] ^= hi
 * 
 *                 batch_start = batch_end             # <<<<<<<<<<<<<<
 *                 batch_end += batch_len
 * 
 */
            __pyx_v_batch_start = __pyx_v_batch_end;

            /* "tabulationhashing/c_tabulationhashing.pyx":182
 * 
 *                 batch_start = batch_end
 *                 batch_end += batch_len             # <<<<<<<<<<<<<<
 * 
 *             # Last, probably partial batch. This even handles the case that
 */
            __pyx_v_batch_end = (__pyx_v_batch_end + __pyx_v_batch_len);
          }

          /* "tabulationhashing/c_tabulationhashing.pyx":190
 *             # so if there is another partial batch to hash, update last_batch_end
 *             # and batch_end too
 *             batch_end = batch_start + (vec_size - batch_start)             # <<<<<<<<<<<<<<
 *             last_batch_end = batch_end
 * 
 */
          __pyx_v_batch_end = (__pyx_v_batch_start + (__pyx_v_vec_size - __pyx_v_batch_start));

          /* "tabulationhashing/c_tabulationhashing.pyx":191
 *             # and batch_end too
 *             batch_end = batch_start + (vec_size - batch_start)
 *             last_batch_end = batch_end             # <<<<<<<<<<<<<<
 * 
 *             # If the last batch is complete it means that it was already
 */
          __pyx_v_last_batch_end = __pyx_v_batch_end;

          /* "tabulationhashing/c_tabulationhashing.pyx":199
 *             # With this trick we have 1 branch check (aka if) per batch
 *             # (well technically more due the for loops)
 *             if batch_start == batch_end:             # <<<<<<<<<<<<<<
 *                 break
 */
          __pyx_t_1 = ((__pyx_v_batch_start == __pyx_v_batch_end) != 0);
          if (__pyx_t_1) {

            /* "tabulationhashing/c_tabulationhashing.pyx":200
 *             # (well technically more due the for loops)
 *             if batch_start == batch_end:
 *                 break             # <<<<<<<<<<<<<<
 */
            goto __pyx_L7_break;

            /* "tabulationhashing/c_tabulationhashing.pyx":199
 *             # With this trick we have 1 branch check (aka if) per batch
 *             # (well technically more due the for loops)
 *             if batch_start == batch_end:             # <<<<<<<<<<<<<<
 *                 break
 */
          }
        }
        __pyx_L7_break:;
      }

      /* "tabulationhashing/c_tabulationhashing.pyx":130
 * 
 *     # Disable the GIL as this loop will not interact with the Python VM
 *     with nogil:             # <<<<<<<<<<<<<<
 *         # Perform 2 rounds:
 *         #   - the first round will process all the complete batches
 */
      /*finally:*/ {
        /*normal exit:*/{
          #ifdef WITH_THREAD
          __Pyx_FastGIL_Forget();
          Py_BLOCK_THREADS
          #endif
          goto __pyx_L5;
        }
        __pyx_L5:;
      }
  }

  /* "tabulationhashing/c_tabulationhashing.pyx":106
 * @cython.infer_types(True)
 * @cython.cdivision(True)
 * def hash_vec_batch(input_dtype[::1] xvec, hash_dtype[::1] table, hash_dtype[::1] out, uint32_t batch_len):             # <<<<<<<<<<<<<<
 *     cdef:
 *         hash_dtype hi
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  __PYX_XDEC_MEMVIEW(&__pyx_v_xvec, 1);
  __PYX_XDEC_MEMVIEW(&__pyx_v_table, 1);
  __PYX_XDEC_MEMVIEW(&__pyx_v_out, 1);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
PyObject *hash_vec_batch_32_64(CYTHON_UNUSED PyObject *__pyx_self, __Pyx_memviewslice __pyx_v_xvec, __Pyx_memviewslice __pyx_v_table, __Pyx_memviewslice __pyx_v_out, uint32_t __pyx_v_batch_len) {
  uint64_t __pyx_v_hi;
  uint32_t __pyx_v_x;
  uint32_t __pyx_v_xi;
  uint32_t __pyx_v_batch_start;
  uint32_t __pyx_v_batch_end;
  uint32_t __pyx_v_vec_size;
  uint32_t __pyx_v_row;
  uint32_t __pyx_v_shift;
  uint32_t __pyx_v_rebase;
  uint32_t __pyx_v_nrows;
  uint32_t __pyx_v_last_batch_end;
  uint32_t __pyx_v_i;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_t_1;
  uint32_t __pyx_t_2;
  uint32_t __pyx_t_3;
  uint32_t __pyx_t_4;
  size_t __pyx_t_5;
  uint32_t __pyx_t_6;
  uint32_t __pyx_t_7;
  uint32_t __pyx_t_8;
  __Pyx_RefNannySetupContext("__pyx_fuse_0_1hash_vec_batch", 0);

  /* "tabulationhashing/c_tabulationhashing.pyx":111
 *         input_dtype x, xi
 * 
 *         uint32_t batch_start = 0, batch_end = batch_len, vec_size = xvec.shape[0]             # <<<<<<<<<<<<<<
 *         uint32_t row, shift, rebase
 *         uint32_t nrows
 */
  __pyx_v_batch_start = 0;
  __pyx_v_batch_end = __pyx_v_batch_len;
  __pyx_v_vec_size = (__pyx_v_xvec.shape[0]);

  /* "tabulationhashing/c_tabulationhashing.pyx":119
 *     # by the C compiler
 *     if input_dtype is uint32_t:
 *         nrows = 4             # <<<<<<<<<<<<<<
 *     elif input_dtype is uint64_t:
 *         nrows = 8
 */
  __pyx_v_nrows = 4;

  /* "tabulationhashing/c_tabulationhashing.pyx":127
 *     # Calculate the position of the last "complete" batch
 *     # We'll handle the (possible) last incomplete batch later
 *     last_batch_end = vec_size - (vec_size % batch_len)             # <<<<<<<<<<<<<<
 * 
 *     # Disable the GIL as this loop will not interact with the Python VM
 */
  __pyx_v_last_batch_end = (__pyx_v_vec_size - (__pyx_v_vec_size % __pyx_v_batch_len));

  /* "tabulationhashing/c_tabulationhashing.pyx":130
 * 
 *     # Disable the GIL as this loop will not interact with the Python VM
 *     with nogil:             # <<<<<<<<<<<<<<
 *         # Perform 2 rounds:
 *         #   - the first round will process all the complete batches
 */
  {
      #ifdef WITH_THREAD
      PyThreadState *_save;
      Py_UNBLOCK_THREADS
      __Pyx_FastGIL_Remember();
      #endif
      /*try:*/ {

        /* "tabulationhashing/c_tabulationhashing.pyx":134
 *         #   - the first round will process all the complete batches
 *         #   - the second round will process the last incomplete batch, if any
 *         while (1):             # <<<<<<<<<<<<<<
 *             # Hash the input vector by batches.
 *             # The idea is that a batch of the input vector and output vector
 */
        while (1) {

          /* "tabulationhashing/c_tabulationhashing.pyx":151
 *             # Note: cython cannot handle range-loops with steps unknown in compile-time
 *             # See https://github.com/cython/cython/issues/1106
 *             while batch_start < last_batch_end:             # <<<<<<<<<<<<<<
 *                 # Process the batch with the first row (partial hash).
 *                 # This allows us to initialize the out vector
 */
          while (1) {
            __pyx_t_1 = ((__pyx_v_batch_start < __pyx_v_last_batch_end) != 0);
            if (!__pyx_t_1) break;

            /* "tabulationhashing/c_tabulationhashing.pyx":154
 *                 # Process the batch with the first row (partial hash).
 *                 # This allows us to initialize the out vector
 *                 for i in range(batch_start, batch_end):             # <<<<<<<<<<<<<<
 *                     x = xvec[i]
 * 
 */
            __pyx_t_2 = __pyx_v_batch_end;
            __pyx_t_3 = __pyx_t_2;
            for (__pyx_t_4 = __pyx_v_batch_start; __pyx_t_4 < __pyx_t_3; __pyx_t_4+=1) {
              __pyx_v_i = __pyx_t_4;

              /* "tabulationhashing/c_tabulationhashing.pyx":155
 *                 # This allows us to initialize the out vector
 *                 for i in range(batch_start, batch_end):
 *                     x = xvec[i]             # <<<<<<<<<<<<<<
 * 
 *                     xi = (x) & 0x000000ff
 */
              __pyx_t_5 = __pyx_v_i;
              __pyx_v_x = (*((uint32_t *) ( /* dim=0 */ ((char *) (((uint32_t *) __pyx_v_xvec.data) + __pyx_t_5)) )));

              /* "tabulationhashing/c_tabulationhashing.pyx":157
 *                     x = xvec[i]
 * 
 *                     xi = (x) & 0x000000ff             # <<<<<<<<<<<<<<
 *                     hi = table[xi]
 * 
 */
              __pyx_v_xi = (__pyx_v_x & 0x000000ff);

              /* "tabulationhashing/c_tabulationhashing.pyx":158
 * 
 *                     xi = (x) & 0x000000ff
 *                     hi = table[xi]             # <<<<<<<<<<<<<<
 * 
 *                     out[i] = hi
 */
              __pyx_t_5 = __pyx_v_xi;
              __pyx_v_hi = (*((uint64_t *) ( /* dim=0 */ ((char *) (((uint64_t *) __pyx_v_table.data) + __pyx_t_5)) )));

              /* "tabulationhashing/c_tabulationhashing.pyx":160
 *                     hi = table[xi]
 * 
 *                     out[i] = hi             # <<<<<<<<<<<<<<
 * 
 *                 # The C compiler should be smart enough to unroll this for loop
 */
              __pyx_t_5 = __pyx_v_i;
              *((uint64_t *) ( /* dim=0 */ ((char *) (((uint64_t *) __pyx_v_out.data) + __pyx_t_5)) )) = __pyx_v_hi;
            }

            /* "tabulationhashing/c_tabulationhashing.pyx":170
 *                 # If a single row fits in the cache, we will have a constant
 *                 # amount of misses.
 *                 for row in range(1, nrows):             # <<<<<<<<<<<<<<
 *                     shift = row * 8
 *                     rebase = row * 256
 */
            __pyx_t_2 = __pyx_v_nrows;
            __pyx_t_3 = __pyx_t_2;
            for (__pyx_t_4 = 1; __pyx_t_4 < __pyx_t_3; __pyx_t_4+=1) {
              __pyx_v_row = __pyx_t_4;

              /* "tabulationhashing/c_tabulationhashing.pyx":171
 *                 # amount of misses.
 *                 for row in range(1, nrows):
 *                     shift = row * 8             # <<<<<<<<<<<<<<
 *                     rebase = row * 256
 *                     for i in range(batch_start, batch_end):
 */
              __pyx_v_shift = (__pyx_v_row * 8);

              /* "tabulationhashing/c_tabulationhashing.pyx":172
 *                 for row in range(1, nrows):
 *                     shift = row * 8
 *                     rebase = row * 256             # <<<<<<<<<<<<<<
 *                     for i in range(batch_start, batch_end):
 *                         x = xvec[i]
 */
              __pyx_v_rebase = (__pyx_v_row * 0x100);

              /* "tabulationhashing/c_tabulationhashing.pyx":173
 *                     shift = row * 8
 *                     rebase = row * 256
 *                     for i in range(batch_start, batch_end):             # <<<<<<<<<<<<<<
 *                         x = xvec[i]
 * 
 */
              __pyx_t_6 = __pyx_v_batch_end;
              __pyx_t_7 = __pyx_t_6;
              for (__pyx_t_8 = __pyx_v_batch_start; __pyx_t_8 < __pyx_t_7; __pyx_t_8+=1) {
                __pyx_v_i = __pyx_t_8;

                /* "tabulationhashing/c_tabulationhashing.pyx":174
 *                     rebase = row * 256
 *                     for i in range(batch_start, batch_end):
 *                         x = xvec[i]             # <<<<<<<<<<<<<<
 * 
 *                         xi = (x >> shift) & 0x000000ff
 */
                __pyx_t_5 = __pyx_v_i;
                __pyx_v_x = (*((uint32_t *) ( /* dim=0 */ ((char *) (((uint32_t *) __pyx_v_xvec.data) + __pyx_t_5)) )));

                /* "tabulationhashing/c_tabulationhashing.pyx":176
 *                         x = xvec[i]
 * 
 *                         xi = (x >> shift) & 0x000000ff             # <<<<<<<<<<<<<<
 *                         hi = table[xi + rebase]
 * 
 */
                __pyx_v_xi = ((__pyx_v_x >> __pyx_v_shift) & 0x000000ff);

                /* "tabulationhashing/c_tabulationhashing.pyx":177
 * 
 *                         xi = (x >> shift) & 0x000000ff
 *                         hi = table[xi + rebase]             # <<<<<<<<<<<<<<
 * 
 *                         out[i] ^= hi
 */
                __pyx_t_5 = (__pyx_v_xi + __pyx_v_rebase);
                __pyx_v_hi = (*((uint64_t *) ( /* dim=0 */ ((char *) (((uint64_t *) __pyx_v_table.data) + __pyx_t_5)) )));

                /* "tabulationhashing/c_tabulationhashing.pyx":179
 *                         hi = table[xi + rebase]
 * 
 *                         out[i] ^= hi             # <<<<<<<<<<<<<<
 * 
 *                 batch_start = batch_end
 */
                __pyx_t_5 = __pyx_v_i;
                *((uint64_t *) ( /* dim=0 */ ((char *) (((uint64_t *) __pyx_v_out.data) + __pyx_t_5)) )) ^= __pyx_v_hi;
              }
            }

            /* "tabulationhashing/c_tabulationhashing.pyx":181
 *                         out[i] ^= hi
 * 
 *                 batch_start = batch_end             # <<<<<<<<<<<<<<
 *                 batch_end += batch_len
 * 
 */
            __pyx_v_batch_start = __pyx_v_batch_end;

            /* "tabulationhashing/c_tabulationhashing.pyx":182
 * 
 *                 batch_start = batch_end
 *                 batch_end += batch_len             # <<<<<<<<<<<<<<
 * 
 *             # Last, probably partial batch. This even handles the case that
 */
            __pyx_v_batch_end = (__pyx_v_batch_end + __pyx_v_batch_len);
          }

          /* "tabulationhashing/c_tabulationhashing.pyx":190
 *             # so if there is another partial batch to hash, update last_batch_end
 *             # and batch_end too
 *             batch_end = batch_start + (vec_size - batch_start)             # <<<<<<<<<<<<<<
 *             last_batch_end = batch_end
 * 
 */
          __pyx_v_batch_end = (__pyx_v_batch_start + (__pyx_v_vec_size - __pyx_v_batch_start));

          /* "tabulationhashing/c_tabulationhashing.pyx":191
 *             # and batch_end too
 *             batch_end = batch_start + (vec_size - batch_start)
 *             last_batch_end = batch_end             # <<<<<<<<<<<<<<
 * 
 *             # If the last batch is complete it means that it was already
 */
          __pyx_v_last_batch_end = __pyx_v_batch_end;

          /* "tabulationhashing/c_tabulationhashing.pyx":199
 *             # With this trick we have 1 branch check (aka if) per batch
 *             # (well technically more due the for loops)
 *             if batch_start == batch_end:             # <<<<<<<<<<<<<<
 *                 break
 */
          __pyx_t_1 = ((__pyx_v_batch_start == __pyx_v_batch_end) != 0);
          if (__pyx_t_1) {

            /* "tabulationhashing/c_tabulationhashing.pyx":200
 *             # (well technically more due the for loops)
 *             if batch_start == batch_end:
 *                 break             # <<<<<<<<<<<<<<
 */
            goto __pyx_L7_break;

            /* "tabulationhashing/c_tabulationhashing.pyx":199
 *             # With this trick we have 1 branch check (aka if) per batch
 *             # (well technically more due the for loops)
 *             if batch_start == batch_end:             # <<<<<<<<<<<<<<
 *                 break
 */
          }
        }
        __pyx_L7_break:;
      }

      /* "tabulationhashing/c_tabulationhashing.pyx":130
 * 
 *     # Disable the GIL as this loop will not interact with the Python VM
 *     with nogil:             # <<<<<<<<<<<<<<
 *         # Perform 2 rounds:
 *         #   - the first round will process all the complete batches
 */
      /*finally:*/ {
        /*normal exit:*/{
          #ifdef WITH_THREAD
          __Pyx_FastGIL_Forget();
          Py_BLOCK_THREADS
          #endif
          goto __pyx_L5;
        }
        __pyx_L5:;
      }
  }

  /* "tabulationhashing/c_tabulationhashing.pyx":106
 * @cython.infer_types(True)
 * @cython.cdivision(True)
 * def hash_vec_batch(input_dtype[::1] xvec, hash_dtype[::1] table, hash_dtype[::1] out, uint32_t batch_len):             # <<<<<<<<<<<<<<
 *     cdef:
 *         hash_dtype hi
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  __PYX_XDEC_MEMVIEW(&__pyx_v_xvec, 1);
  __PYX_XDEC_MEMVIEW(&__pyx_v_table, 1);
  __PYX_XDEC_MEMVIEW(&__pyx_v_out, 1);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
PyObject *hash_vec_batch_64_32(CYTHON_UNUSED PyObject *__pyx_self, __Pyx_memviewslice __pyx_v_xvec, __Pyx_memviewslice __pyx_v_table, __Pyx_memviewslice __pyx_v_out, uint32_t __pyx_v_batch_len) {
  uint32_t __pyx_v_hi;
  uint64_t __pyx_v_x;
  uint64_t __pyx_v_xi;
  uint32_t __pyx_v_batch_start;
  uint32_t __pyx_v_batch_end;
  uint32_t __pyx_v_vec_size;
  uint32_t __pyx_v_row;
  uint32_t __pyx_v_shift;
  uint32_t __pyx_v_rebase;
  uint32_t __pyx_v_nrows;
  uint32_t __pyx_v_last_batch_end;
  uint32_t __pyx_v_i;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_t_1;
  uint32_t __pyx_t_2;
  uint32_t __pyx_t_3;
  uint32_t __pyx_t_4;
  size_t __pyx_t_5;
  uint64_t __pyx_t_6;
  uint32_t __pyx_t_7;
  uint32_t __pyx_t_8;
  uint32_t __pyx_t_9;
  __Pyx_RefNannySetupContext("__pyx_fuse_1_0hash_vec_batch", 0);

  /* "tabulationhashing/c_tabulationhashing.pyx":111
 *         input_dtype x, xi
 * 
 *         uint32_t batch_start = 0, batch_end = batch_len, vec_size = xvec.shape[0]             # <<<<<<<<<<<<<<
 *         uint32_t row, shift, rebase
 *         uint32_t nrows
 */
  __pyx_v_batch_start = 0;
  __pyx_v_batch_end = __pyx_v_batch_len;
  __pyx_v_vec_size = (__pyx_v_xvec.shape[0]);

  /* "tabulationhashing/c_tabulationhashing.pyx":121
 *         nrows = 4
 *     elif input_dtype is uint64_t:
 *         nrows = 8             # <<<<<<<<<<<<<<
 *     else:
 *         assert False
 */
  __pyx_v_nrows = 8;

  /* "tabulationhashing/c_tabulationhashing.pyx":127
 *     # Calculate the position of the last "complete" batch
 *     # We'll handle the (possible) last incomplete batch later
 *     last_batch_end = vec_size - (vec_size % batch_len)             # <<<<<<<<<<<<<<
 * 
 *     # Disable the GIL as this loop will not interact with the Python VM
 */
  __pyx_v_last_batch_end = (__pyx_v_vec_size - (__pyx_v_vec_size % __pyx_v_batch_len));

  /* "tabulationhashing/c_tabulationhashing.pyx":130
 * 
 *     # Disable the GIL as this loop will not interact with the Python VM
 *     with nogil:             # <<<<<<<<<<<<<<
 *         # Perform 2 rounds:
 *         #   - the first round will process all the complete batches
 */
  {
      #ifdef WITH_THREAD
      PyThreadState *_save;
      Py_UNBLOCK_THREADS
      __Pyx_FastGIL_Remember();
      #endif
      /*try:*/ {

        /* "tabulationhashing/c_tabulationhashing.pyx":134
 *         #   - the first round will process all the complete batches
 *         #   - the second round will process the last incomplete batch, if any
 *         while (1):             # <<<<<<<<<<<<<<
 *             # Hash the input vector by batches.
 *             # The idea is that a batch of the input vector and output vector
 */
        while (1) {

          /* "tabulationhashing/c_tabulationhashing.pyx":151
 *             # Note: cython cannot handle range-loops with steps unknown in compile-time
 *             # See https://github.com/cython/cython/issues/1106
 *             while batch_start < last_batch_end:             # <<<<<<<<<<<<<<
 *                 # Process the batch with the first row (partial hash).
 *                 # This allows us to initialize the out vector
 */
          while (1) {
            __pyx_t_1 = ((__pyx_v_batch_start < __pyx_v_last_batch_end) != 0);
            if (!__pyx_t_1) break;

            /* "tabulationhashing/c_tabulationhashing.pyx":154
 *                 # Process the batch with the first row (partial hash).
 *                 # This allows us to initialize the out vector
 *                 for i in range(batch_start, batch_end):             # <<<<<<<<<<<<<<
 *                     x = xvec[i]
 * 
 */
            __pyx_t_2 = __pyx_v_batch_end;
            __pyx_t_3 = __pyx_t_2;
            for (__pyx_t_4 = __pyx_v_batch_start; __pyx_t_4 < __pyx_t_3; __pyx_t_4+=1) {
              __pyx_v_i = __pyx_t_4;

              /* "tabulationhashing/c_tabulationhashing.pyx":155
 *                 # This allows us to initialize the out vector
 *                 for i in range(batch_start, batch_end):
 *                     x = xvec[i]             # <<<<<<<<<<<<<<
 * 
 *                     xi = (x) & 0x000000ff
 */
              __pyx_t_5 = __pyx_v_i;
              __pyx_v_x = (*((uint64_t *) ( /* dim=0 */ ((char *) (((uint64_t *) __pyx_v_xvec.data) + __pyx_t_5)) )));

              /* "tabulationhashing/c_tabulationhashing.pyx":157
 *                     x = xvec[i]
 * 
 *                     xi = (x) & 0x000000ff             # <<<<<<<<<<<<<<
 *                     hi = table[xi]
 * 
 */
              __pyx_v_xi = (__pyx_v_x & 0x000000ff);

              /* "tabulationhashing/c_tabulationhashing.pyx":158
 * 
 *                     xi = (x) & 0x000000ff
 *                     hi = table[xi]             # <<<<<<<<<<<<<<
 * 
 *                     out[i] = hi
 */
              __pyx_t_6 = __pyx_v_xi;
              __pyx_v_hi = (*((uint32_t *) ( /* dim=0 */ ((char *) (((uint32_t *) __pyx_v_table.data) + __pyx_t_6)) )));

              /* "tabulationhashing/c_tabulationhashing.pyx":160
 *                     hi = table[xi]
 * 
 *                     out[i] = hi             # <<<<<<<<<<<<<<
 * 
 *                 # The C compiler should be smart enough to unroll this for loop
 */
              __pyx_t_5 = __pyx_v_i;
              *((uint32_t *) ( /* dim=0 */ ((char *) (((uint32_t *) __pyx_v_out.data) + __pyx_t_5)) )) = __pyx_v_hi;
            }

            /* "tabulationhashing/c_tabulationhashing.pyx":170
 *                 # If a single row fits in the cache, we will have a constant
 *                 # amount of misses.
 *                 for row in range(1, nrows):             # <<<<<<<<<<<<<<
 *                     shift = row * 8
 *                     rebase = row * 256
 */
            __pyx_t_2 = __pyx_v_nrows;
            __pyx_t_3 = __pyx_t_2;
            for (__pyx_t_4 = 1; __pyx_t_4 < __pyx_t_3; __pyx_t_4+=1) {
              __pyx_v_row = __pyx_t_4;

              /* "tabulationhashing/c_tabulationhashing.pyx":171
 *                 # amount of misses.
 *                 for row in range(1, nrows):
 *                     shift = row * 8             # <<<<<<<<<<<<<<
 *                     rebase = row * 256
 *                     for i in range(batch_start, batch_end):
 */
              __pyx_v_shift = (__pyx_v_row * 8);

              /* "tabulationhashing/c_tabulationhashing.pyx":172
 *                 for row in range(1, nrows):
 *                     shift = row * 8
 *                     rebase = row * 256             # <<<<<<<<<<<<<<
 *                     for i in range(batch_start, batch_end):
 *                         x = xvec[i]
 */
              __pyx_v_rebase = (__pyx_v_row * 0x100);

              /* "tabulationhashing/c_tabulationhashing.pyx":173
 *                     shift = row * 8
 *                     rebase = row * 256
 *                     for i in range(batch_start, batch_end):             # <<<<<<<<<<<<<<
 *                         x = xvec[i]
 * 
 */
              __pyx_t_7 = __pyx_v_batch_end;
              __pyx_t_8 = __pyx_t_7;
              for (__pyx_t_9 = __pyx_v_batch_start; __pyx_t_9 < __pyx_t_8; __pyx_t_9+=1) {
                __pyx_v_i = __pyx_t_9;

                /* "tabulationhashing/c_tabulationhashing.pyx":174
 *                     rebase = row * 256
 *                     for i in range(batch_start, batch_end):
 *                         x = xvec[i]             # <<<<<<<<<<<<<<
 * 
 *                         xi = (x >> shift) & 0x000000ff
 */
                __pyx_t_5 = __pyx_v_i;
                __pyx_v_x = (*((uint64_t *) ( /* dim=0 */ ((char *) (((uint64_t *) __pyx_v_xvec.data) + __pyx_t_5)) )));

                /* "tabulationhashing/c_tabulationhashing.pyx":176
 *                         x = xvec[i]
 * 
 *                         xi = (x >> shift) & 0x000000ff             # <<<<<<<<<<<<<<
 *                         hi = table[xi + rebase]
 * 
 */
                __pyx_v_xi = ((__pyx_v_x >> __pyx_v_shift) & 0x000000ff);

                /* "tabulationhashing/c_tabulationhashing.pyx":177
 * 
 *                         xi = (x >> shift) & 0x000000ff
 *                         hi = table[xi + rebase]             # <<<<<<<<<<<<<<
 * 
 *                         out[i] ^= hi
 */
                __pyx_t_6 = (__pyx_v_xi + __pyx_v_rebase);
                __pyx_v_hi = (*((uint32_t *) ( /* dim=0 */ ((char *) (((uint32_t *) __pyx_v_table.data) + __pyx_t_6)) )));

                /* "tabulationhashing/c_tabulationhashing.pyx":179
 *                         hi = table[xi + rebase]
 * 
 *                         out[i] ^= hi             # <<<<<<<<<<<<<<
 * 
 *                 batch_start = batch_end
 */
                __pyx_t_5 = __pyx_v_i;
                *((uint32_t *) ( /* dim=0 */ ((char *) (((uint32_t *) __pyx_v_out.data) + __pyx_t_5)) )) ^= __pyx_v_hi;
              }
            }

            /* "tabulationhashing/c_tabulationhashing.pyx":181
 *                         out[i] ^= hi
 * 
 *                 batch_start = batch_end             # <<<<<<<<<<<<<<
 *                 batch_end += batch_len
 * 
 */
            __pyx_v_batch_start = __pyx_v_batch_end;

            /* "tabulationhashing/c_tabulationhashing.pyx":182
 * 
 *                 batch_start = batch_end
 *                 batch_end += batch_len             # <<<<<<<<<<<<<<
 * 
 *             # Last, probably partial batch. This even handles the case that
 */
            __pyx_v_batch_end = (__pyx_v_batch_end + __pyx_v_batch_len);
          }

          /* "tabulationhashing/c_tabulationhashing.pyx":190
 *             # so if there is another partial batch to hash, update last_batch_end
 *             # and batch_end too
 *             batch_end = batch_start + (vec_size - batch_start)             # <<<<<<<<<<<<<<
 *             last_batch_end = batch_end
 * 
 */
          __pyx_v_batch_end = (__pyx_v_batch_start + (__pyx_v_vec_size - __pyx_v_batch_start));

          /* "tabulationhashing/c_tabulationhashing.pyx":191
 *             # and batch_end too
 *             batch_end = batch_start + (vec_size - batch_start)
 *             last_batch_end = batch_end             # <<<<<<<<<<<<<<
 * 
 *             # If the last batch is complete it means that it was already
 */
          __pyx_v_last_batch_end = __pyx_v_batch_end;

          /* "tabulationhashing/c_tabulationhashing.pyx":199
 *             # With this trick we have 1 branch check (aka if) per batch
 *             # (well technically more due the for loops)
 *             if batch_start == batch_end:             # <<<<<<<<<<<<<<
 *                 break
 */
          __pyx_t_1 = ((__pyx_v_batch_start == __pyx_v_batch_end) != 0);
          if (__pyx_t_1) {

            /* "tabulationhashing/c_tabulationhashing.pyx":200
 *             # (well technically more due the for loops)
 *             if batch_start == batch_end:
 *                 break             # <<<<<<<<<<<<<<
 */
            goto __pyx_L7_break;

            /* "tabulationhashing/c_tabulationhashing.pyx":199
 *             # With this trick we have 1 branch check (aka if) per batch
 *             # (well technically more due the for loops)
 *             if batch_start == batch_end:             # <<<<<<<<<<<<<<
 *                 break
 */
          }
        }
        __pyx_L7_break:;
      }

      /* "tabulationhashing/c_tabulationhashing.pyx":130
 * 
 *     # Disable the GIL as this loop will not interact with the Python VM
 *     with nogil:             # <<<<<<<<<<<<<<
 *         # Perform 2 rounds:
 *         #   - the first round will process all the complete batches
 */
      /*finally:*/ {
        /*normal exit:*/{
          #ifdef WITH_THREAD
          __Pyx_FastGIL_Forget();
          Py_BLOCK_THREADS
          #endif
          goto __pyx_L5;
        }
        __pyx_L5:;
      }
  }

  /* "tabulationhashing/c_tabulationhashing.pyx":106
 * @cython.infer_types(True)
 * @cython.cdivision(True)
 * def hash_vec_batch(input_dtype[::1] xvec, hash_dtype[::1] table, hash_dtype[::1] out, uint32_t batch_len):             # <<<<<<<<<<<<<<
 *     cdef:
 *         hash_dtype hi
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  __PYX_XDEC_MEMVIEW(&__pyx_v_xvec, 1);
  __PYX_XDEC_MEMVIEW(&__pyx_v_table, 1);
  __PYX_XDEC_MEMVIEW(&__pyx_v_out, 1);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
PyObject *hash_vec_batch_64_64(CYTHON_UNUSED PyObject *__pyx_self, __Pyx_memviewslice __pyx_v_xvec, __Pyx_memviewslice __pyx_v_table, __Pyx_memviewslice __pyx_v_out, uint32_t __pyx_v_batch_len) {
  uint64_t __pyx_v_hi;
  uint64_t __pyx_v_x;
  uint64_t __pyx_v_xi;
  uint32_t __pyx_v_batch_start;
  uint32_t __pyx_v_batch_end;
  uint32_t __pyx_v_vec_size;
  uint32_t __pyx_v_row;
  uint32_t __pyx_v_shift;
  uint32_t __pyx_v_rebase;
  uint32_t __pyx_v_nrows;
  uint32_t __pyx_v_last_batch_end;
  uint32_t __pyx_v_i;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_t_1;
  uint32_t __pyx_t_2;
  uint32_t __pyx_t_3;
  uint32_t __pyx_t_4;
  size_t __pyx_t_5;
  uint64_t __pyx_t_6;
  uint32_t __pyx_t_7;
  uint32_t __pyx_t_8;
  uint32_t __pyx_t_9;
  __Pyx_RefNannySetupContext("__pyx_fuse_1_1hash_vec_batch", 0);

  /* "tabulationhashing/c_tabulationhashing.pyx":111
 *         input_dtype x, xi
 * 
 *         uint32_t batch_start = 0, batch_end = batch_len, vec_size = xvec.shape[0]             # <<<<<<<<<<<<<<
 *         uint32_t row, shift, rebase
 *         uint32_t nrows
 */
  __pyx_v_batch_start = 0;
  __pyx_v_batch_end = __pyx_v_batch_len;
  __pyx_v_vec_size = (__pyx_v_xvec.shape[0]);

  /* "tabulationhashing/c_tabulationhashing.pyx":121
 *         nrows = 4
 *     elif input_dtype is uint64_t:
 *         nrows = 8             # <<<<<<<<<<<<<<
 *     else:
 *         assert False
 */
  __pyx_v_nrows = 8;

  /* "tabulationhashing/c_tabulationhashing.pyx":127
 *     # Calculate the position of the last "complete" batch
 *     # We'll handle the (possible) last incomplete batch later
 *     last_batch_end = vec_size - (vec_size % batch_len)             # <<<<<<<<<<<<<<
 * 
 *     # Disable the GIL as this loop will not interact with the Python VM
 */
  __pyx_v_last_batch_end = (__pyx_v_vec_size - (__pyx_v_vec_size % __pyx_v_batch_len));

  /* "tabulationhashing/c_tabulationhashing.pyx":130
 * 
 *     # Disable the GIL as this loop will not interact with the Python VM
 *     with nogil:             # <<<<<<<<<<<<<<
 *         # Perform 2 rounds:
 *         #   - the first round will process all the complete batches
 */
  {
      #ifdef WITH_THREAD
      PyThreadState *_save;
      Py_UNBLOCK_THREADS
      __Pyx_FastGIL_Remember();
      #endif
      /*try:*/ {

        /* "tabulationhashing/c_tabulationhashing.pyx":134
 *         #   - the first round will process all the complete batches
 *         #   - the second round will process the last incomplete batch, if any
 *         while (1):             # <<<<<<<<<<<<<<
 *             # Hash the input vector by batches.
 *             # The idea is that a batch of the input vector and output vector
 */
        while (1) {

          /* "tabulationhashing/c_tabulationhashing.pyx":151
 *             # Note: cython cannot handle range-loops with steps unknown in compile-time
 *             # See https://github.com/cython/cython/issues/1106
 *             while batch_start < last_batch_end:             # <<<<<<<<<<<<<<
 *                 # Process the batch with the first row (partial hash).
 *                 # This allows us to initialize the out vector
 */
          while (1) {
            __pyx_t_1 = ((__pyx_v_batch_start < __pyx_v_last_batch_end) != 0);
            if (!__pyx_t_1) break;

            /* "tabulationhashing/c_tabulationhashing.pyx":154
 *                 # Process the batch with the first row (partial hash).
 *                 # This allows us to initialize the out vector
 *                 for i in range(batch_start, batch_end):             # <<<<<<<<<<<<<<
 *                     x = xvec[i]
 * 
 */
            __pyx_t_2 = __pyx_v_batch_end;
            __pyx_t_3 = __pyx_t_2;
            for (__pyx_t_4 = __pyx_v_batch_start; __pyx_t_4 < __pyx_t_3; __pyx_t_4+=1) {
              __pyx_v_i = __pyx_t_4;

              /* "tabulationhashing/c_tabulationhashing.pyx":155
 *                 # This allows us to initialize the out vector
 *                 for i in range(batch_start, batch_end):
 *                     x = xvec[i]             # <<<<<<<<<<<<<<
 * 
 *                     xi = (x) & 0x000000ff
 */
              __pyx_t_5 = __pyx_v_i;
              __pyx_v_x = (*((uint64_t *) ( /* dim=0 */ ((char *) (((uint64_t *) __pyx_v_xvec.data) + __pyx_t_5)) )));

              /* "tabulationhashing/c_tabulationhashing.pyx":157
 *                     x = xvec[i]
 * 
 *                     xi = (x) & 0x000000ff             # <<<<<<<<<<<<<<
 *                     hi = table[xi]
 * 
 */
              __pyx_v_xi = (__pyx_v_x & 0x000000ff);

              /* "tabulationhashing/c_tabulationhashing.pyx":158
 * 
 *                     xi = (x) & 0x000000ff
 *                     hi = table[xi]             # <<<<<<<<<<<<<<
 * 
 *                     out[i] = hi
 */
              __pyx_t_6 = __pyx_v_xi;
              __pyx_v_hi = (*((uint64_t *) ( /* dim=0 */ ((char *) (((uint64_t *) __pyx_v_table.data) + __pyx_t_6)) )));

              /* "tabulationhashing/c_tabulationhashing.pyx":160
 *                     hi = table[xi]
 * 
 *                     out[i] = hi             # <<<<<<<<<<<<<<
 * 
 *                 # The C compiler should be smart enough to unroll this for loop
 */
              __pyx_t_5 = __pyx_v_i;
              *((uint64_t *) ( /* dim=0 */ ((char *) (((uint64_t *) __pyx_v_out.data) + __pyx_t_5)) )) = __pyx_v_hi;
            }

            /* "tabulationhashing/c_tabulationhashing.pyx":170
 *                 # If a single row fits in the cache, we will have a constant
 *                 # amount of misses.
 *                 for row in range(1, nrows):             # <<<<<<<<<<<<<<
 *                     shift = row * 8
 *                     rebase = row * 256
 */
            __pyx_t_2 = __pyx_v_nrows;
            __pyx_t_3 = __pyx_t_2;
            for (__pyx_t_4 = 1; __pyx_t_4 < __pyx_t_3; __pyx_t_4+=1) {
              __pyx_v_row = __pyx_t_4;

              /* "tabulationhashing/c_tabulationhashing.pyx":171
 *                 # amount of misses.
 *                 for row in range(1, nrows):
 *                     shift = row * 8             # <<<<<<<<<<<<<<
 *                     rebase = row * 256
 *                     for i in range(batch_start, batch_end):
 */
              __pyx_v_shift = (__pyx_v_row * 8);

              /* "tabulationhashing/c_tabulationhashing.pyx":172
 *                 for row in range(1, nrows):
 *                     shift = row * 8
 *                     rebase = row * 256             # <<<<<<<<<<<<<<
 *                     for i in range(batch_start, batch_end):
 *                         x = xvec[i]
 */
              __pyx_v_rebase = (__pyx_v_row * 0x100);

              /* "tabulationhashing/c_tabulationhashing.pyx":173
 *                     shift = row * 8
 *                     rebase = row * 256
 *                     for i in range(batch_start, batch_end):             # <<<<<<<<<<<<<<
 *                         x = xvec[i]
 * 
 */
              __pyx_t_7 = __pyx_v_batch_end;
              __pyx_t_8 = __pyx_t_7;
              for (__pyx_t_9 = __pyx_v_batch_start; __pyx_t_9 < __pyx_t_8; __pyx_t_9+=1) {
                __pyx_v_i = __pyx_t_9;

                /* "tabulationhashing/c_tabulationhashing.pyx":174
 *                     rebase = row * 256
 *                     for i in range(batch_start, batch_end):
 *                         x = xvec[i]             # <<<<<<<<<<<<<<
 * 
 *                         xi = (x >> shift) & 0x000000ff
 */
                __pyx_t_5 = __pyx_v_i;
                __pyx_v_x = (*((uint64_t *) ( /* dim=0 */ ((char *) (((uint64_t *) __pyx_v_xvec.data) + __pyx_t_5)) )));

                /* "tabulationhashing/c_tabulationhashing.pyx":176
 *                         x = xvec[i]
 * 
 *                         xi = (x >> shift) & 0x000000ff             # <<<<<<<<<<<<<<
 *                         hi = table[xi + rebase]
 * 
 */
                __pyx_v_xi = ((__pyx_v_x >> __pyx_v_shift) & 0x000000ff);

                /* "tabulationhashing/c_tabulationhashing.pyx":177
 * 
 *                         xi = (x >> shift) & 0x000000ff
 *                         hi = table[xi + rebase]             # <<<<<<<<<<<<<<
 * 
 *                         out[i] ^= hi
 */
                __pyx_t_6 = (__pyx_v_xi + __pyx_v_rebase);
                __pyx_v_hi = (*((uint64_t *) ( /* dim=0 */ ((char *) (((uint64_t *) __pyx_v_table.data) + __pyx_t_6)) )));

                /* "tabulationhashing/c_tabulationhashing.pyx":179
 *                         hi = table[xi + rebase]
 * 
 *                         out[i] ^= hi             # <<<<<<<<<<<<<<
 * 
 *                 batch_start = batch_end
 */
                __pyx_t_5 = __pyx_v_i;
                *((uint64_t *) ( /* dim=0 */ ((char *) (((uint64_t *) __pyx_v_out.data) + __pyx_t_5)) )) ^= __pyx_v_hi;
              }
            }

            /* "tabulationhashing/c_tabulationhashing.pyx":181
 *                         out[i] ^= hi
 * 
 *                 batch_start = batch_end             # <<<<<<<<<<<<<<
 *                 batch_end += batch_len
 * 
 */
            __pyx_v_batch_start = __pyx_v_batch_end;

            /* "tabulationhashing/c_tabulationhashing.pyx":182
 * 
 *                 batch_start = batch_end
 *                 batch_end += batch_len             # <<<<<<<<<<<<<<
 * 
 *             # Last, probably partial batch. This even handles the case that
 */
            __pyx_v_batch_end = (__pyx_v_batch_end + __pyx_v_batch_len);
          }

          /* "tabulationhashing/c_tabulationhashing.pyx":190
 *             # so if there is another partial batch to hash, update last_batch_end
 *             # and batch_end too
 *             batch_end = batch_start + (vec_size - batch_start)             # <<<<<<<<<<<<<<
 *             last_batch_end = batch_end
 * 
 */
          __pyx_v_batch_end = (__pyx_v_batch_start + (__pyx_v_vec_size - __pyx_v_batch_start));

          /* "tabulationhashing/c_tabulationhashing.pyx":191
 *             # and batch_end too
 *             batch_end = batch_start + (vec_size - batch_start)
 *             last_batch_end = batch_end             # <<<<<<<<<<<<<<
 * 
 *             # If the last batch is complete it means that it was already
 */
          __pyx_v_last_batch_end = __pyx_v_batch_end;

          /* "tabulationhashing/c_tabulationhashing.pyx":199
 *             # With this trick we have 1 branch check (aka if) per batch
 *             # (well technically more due the for loops)
 *             if batch_start == batch_end:             # <<<<<<<<<<<<<<
 *                 break
 */
          __pyx_t_1 = ((__pyx_v_batch_start == __pyx_v_batch_end) != 0);
          if (__pyx_t_1) {

            /* "tabulationhashing/c_tabulationhashing.pyx":200
 *             # (well technically more due the for loops)
 *             if batch_start == batch_end:
 *                 break             # <<<<<<<<<<<<<<
 */
            goto __pyx_L7_break;

            /* "tabulationhashing/c_tabulationhashing.pyx":199
 *             # With this trick we have 1 branch check (aka if) per batch
 *             # (well technically more due the for loops)
 *             if batch_start == batch_end:             # <<<<<<<<<<<<<<
 *                 break
 */
          }
        }
        __pyx_L7_break:;
      }

      /* "tabulationhashing/c_tabulationhashing.pyx":130
 * 
 *     # Disable the GIL as this loop will not interact with the Python VM
 *     with nogil:             # <<<<<<<<<<<<<<
 *         # Perform 2 rounds:
 *         #   - the first round will process all the complete batches
 */
      /*finally:*/ {
        /*normal exit:*/{
          #ifdef WITH_THREAD
          __Pyx_FastGIL_Forget();
          Py_BLOCK_THREADS
          #endif
          goto __pyx_L5;
        }
        __pyx_L5:;
      }
  }

  /* "tabulationhashing/c_tabulationhashing.pyx":106
 * @cython.infer_types(True)
 * @cython.cdivision(True)
 * def hash_vec_batch(input_dtype[::1] xvec, hash_dtype[::1] table, hash_dtype[::1] out, uint32_t batch_len):             # <<<<<<<<<<<<<<
 *     cdef:
 *         hash_dtype hi
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  __PYX_XDEC_MEMVIEW(&__pyx_v_xvec, 1);
  __PYX_XDEC_MEMVIEW(&__pyx_v_table, 1);
  __PYX_XDEC_MEMVIEW(&__pyx_v_out, 1);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}
