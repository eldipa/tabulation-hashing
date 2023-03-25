#include <stdint.h>


typedef struct _memviewslice {
    char *data;
    uint32_t shape[1];
} memviewslice;

#define __Pyx_memviewslice memviewslice
#define Py_ssize_t ssize_t
#define PyObject void
#define Py_None  NULL

#define __Pyx_RefNannyDeclarations
#define __Pyx_RefNannySetupContext(x,y)
#define __Pyx_RefNannyFinishContext()
#define __Pyx_INCREF(x)
#define __Pyx_XGIVEREF(x)
#define __PYX_XDEC_MEMVIEW(x,y)

#undef WITH_THREAD

#define CYTHON_INLINE inline
#define CYTHON_UNUSED __attribute__((unused))


PyObject *hash_vec_full_32_32(CYTHON_UNUSED PyObject *__pyx_self, __Pyx_memviewslice __pyx_v_xvec, __Pyx_memviewslice __pyx_v_table, __Pyx_memviewslice __pyx_v_out);
PyObject *hash_vec_full_32_64(CYTHON_UNUSED PyObject *__pyx_self, __Pyx_memviewslice __pyx_v_xvec, __Pyx_memviewslice __pyx_v_table, __Pyx_memviewslice __pyx_v_out);
PyObject *hash_vec_full_64_32(CYTHON_UNUSED PyObject *__pyx_self, __Pyx_memviewslice __pyx_v_xvec, __Pyx_memviewslice __pyx_v_table, __Pyx_memviewslice __pyx_v_out);
PyObject *hash_vec_full_64_64(CYTHON_UNUSED PyObject *__pyx_self, __Pyx_memviewslice __pyx_v_xvec, __Pyx_memviewslice __pyx_v_table, __Pyx_memviewslice __pyx_v_out);





PyObject *hash_vec_batch_32_32(CYTHON_UNUSED PyObject *__pyx_self, __Pyx_memviewslice __pyx_v_xvec, __Pyx_memviewslice __pyx_v_table, __Pyx_memviewslice __pyx_v_out, uint32_t __pyx_v_batch_len);
PyObject *hash_vec_batch_32_64(CYTHON_UNUSED PyObject *__pyx_self, __Pyx_memviewslice __pyx_v_xvec, __Pyx_memviewslice __pyx_v_table, __Pyx_memviewslice __pyx_v_out, uint32_t __pyx_v_batch_len);
PyObject *hash_vec_batch_64_32(CYTHON_UNUSED PyObject *__pyx_self, __Pyx_memviewslice __pyx_v_xvec, __Pyx_memviewslice __pyx_v_table, __Pyx_memviewslice __pyx_v_out, uint32_t __pyx_v_batch_len);
PyObject *hash_vec_batch_64_64(CYTHON_UNUSED PyObject *__pyx_self, __Pyx_memviewslice __pyx_v_xvec, __Pyx_memviewslice __pyx_v_table, __Pyx_memviewslice __pyx_v_out, uint32_t __pyx_v_batch_len);
