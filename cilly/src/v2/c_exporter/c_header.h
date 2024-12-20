#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <mm_malloc.h>

#include <alloca.h>
/* Backup for targets that don't support i128 - TODO: replace this with software emulation!*/
#ifndef __SIZEOF_INT128__
#define __int128 long long
#endif
/* Allocator APIs*/
#define System_Runtime_InteropServices_Marshal_AllocHGlobali4is(size) malloc(size)
#define System_Runtime_InteropServices_Marshal_AllocHGlobalisis(size) malloc(size)
#define System_Runtime_InteropServices_Marshal_ReAllocHGlobalisisis(ptr, new_size) realloc(ptr, new_size)
#define System_Runtime_InteropServices_Marshal_FreeHGlobalisv(ptr) free(ptr)
#define System_Runtime_InteropServices_NativeMemory_AlignedAllocususpv(size, align) aligned_alloc(align, size)
#define System_Runtime_InteropServices_NativeMemory_AlignedFreepvv free
static inline void *System_Runtime_InteropServices_NativeMemory_AlignedReallocpvususpv(void *ptr, uintptr_t size, uintptr_t align)
{
    void *new_buff = aligned_alloc(align, size);
    memcpy(new_buff, ptr, size);
    free(ptr);
    return new_buff;
}
/*Utility macros*/
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define BUILTIN_UNSUPORTED(NAME,OUTPUT, ARGLIST) static inline OUTPUT NAME ARGLIST { eprintf("Function " #NAME "is not yet supported!"); abort();}
/*Wrappers for certain 128 bit ops: TODO: remove this once all ops are ported to new cilly builtins*/
#define System_UInt128_op_Additionu16u16u16(lhs, rhs) (lhs + rhs)
#define System_Int128_op_Additioni16i16i16(lhs, rhs) (__int128)((unsigned __int128)lhs + (unsigned __int128)rhs)

#define System_UInt128_op_Subtractionu16u16u16(lhs, rhs) (lhs - rhs)
#define System_Int128_op_Subtractioni16i16i16(lhs, rhs) (__int128)((unsigned __int128)lhs - (unsigned __int128)rhs)

#define System_Int128_op_LessThani16i16b(lhs, rhs) (lhs < rhs)
#define System_UInt128_op_LessThanu16u16b(lhs, rhs) (lhs < rhs)

#define System_Int128_op_GreaterThani16i16b(lhs, rhs) (lhs > rhs)
#define System_UInt128_op_GreaterThanu16u16b(lhs, rhs) (lhs > rhs)

#define System_UInt128_op_Multiplyu16u16u16(lhs, rhs) (lhs * rhs)
#define System_Int128_op_Multiplyi16i16i16(lhs, rhs) ((unsigned __int128)lhs * (unsigned __int128)rhs)

#define System_UInt128_op_Divisionu16u16u16(lhs, rhs) (lhs / rhs)
#define System_UInt128_op_RightShiftu16i4u16(val, ammount) val >> ammount
#define System_Int128_op_RightShifti16i4i16(val, ammount) val >> ammount

#define System_Int128_op_LeftShifti16i4i16(val, ammount) val << ammount
#define System_UInt128_op_LeftShiftu16i4u16(val, ammount) val << ammount

#define System_Int128_op_BitwiseOri16i16i16(lhs, rhs) (lhs | rhs)
#define System_UInt128_op_BitwiseOru16u16u16(lhs, rhs) (lhs | rhs)

#define System_Int128_op_ExclusiveOri16i16i16(lhs, rhs) (lhs ^ rhs)
#define System_UInt128_op_ExclusiveOru16u16u16(lhs, rhs) (lhs ^ rhs)

#define System_Int128_op_BitwiseAndi16i16i16(lhs, rhs) (lhs & rhs)
#define System_UInt128_op_BitwiseAndu16u16u16(lhs, rhs) (lhs & rhs)

#define System_Int128_op_UnaryNegationi16i16(val) (__int128_t)(0 - ((__uint128_t)(val)))

#define System_UInt128_op_Explicitu16u8(val) (uint64_t)(val)
#define System_UInt128_op_Explicitu16u4(val) (uint32_t)(val)
#define System_UInt128_op_Explicitu16u2(val) (uint16_t)(val)
#define System_UInt128_op_Explicitu16u1(val) (uint8_t)(val)
#define System_UInt128_op_Explicitu16us(val) (uintptr_t) val
#define System_UInt128_op_Explicitu16i8(val) (int64_t)(val)
#define System_UInt128_op_Explicitu16i4(val) (int32_t)(val)
#define System_UInt128_op_Explicitu16i2(val) (int16_t)(val)
#define System_UInt128_op_Explicitu16i1(val) (int8_t)(val)
#define System_UInt128_op_Explicitu16is(val) (intptr_t) val

#define System_UInt128_op_Explicitu16f4(val) (float)(val)
#define System_UInt128_op_Explicitu16f8(val) (double)(val)

#define System_Int128_op_Expliciti16f4(val) (float)(val)
#define System_Int128_op_Expliciti16f8(val) (double)(val)

#define System_Int128_op_Expliciti16i1(val) (int8_t)(val)
#define System_Int128_op_Expliciti16i2(val) (int16_t)(val)
#define System_Int128_op_Expliciti16i4(val) (int32_t)(val)
#define System_Int128_op_Expliciti16i8(val) (int64_t)(val)
#define System_Int128_op_Expliciti16is(val) (intptr_t) val
#define System_Int128_op_Expliciti16u1(val) (uint8_t)(val)
#define System_Int128_op_Expliciti16u2(val) (uint16_t)(val)
#define System_Int128_op_Expliciti16u4(val) (uint32_t)(val)
#define System_Int128_op_Expliciti16u8(val) (uint64_t)(val)
#define System_Int128_op_Expliciti16us(val) (uintptr_t) val

#define System_UInt128_op_Explicitu16i16(val) (__int128_t)(val)

#define System_UInt128_op_Expliciti1u16(val) (__uint128_t)(val)
#define System_UInt128_op_Expliciti2u16(val) (__uint128_t)(val)
#define System_UInt128_op_Expliciti4u16(val) (__uint128_t)(val)
#define System_UInt128_op_Expliciti8u16(val) (__uint128_t)(val)
#define System_Int128_op_Expliciti16u16(val) (__uint128_t)(val)

#define System_UInt128_op_Explicitf4u16(val) (__uint128_t)(val)
#define System_UInt128_op_Explicitf8u16(val) (__uint128_t)(val)
#define System_UInt128_op_Implicitusu16(val) (__uint128_t)(val)

#define System_Int128_op_Explicitf8i16(val) (__int128_t)(val)
#define System_Int128_op_Explicitf4i16(val) (__int128_t)(val)

#define System_Int128_op_Impliciti1i16(val) (__int128_t)(val)
#define System_Int128_op_Implicitu1i16(val) (__int128_t)(val)
#define System_Int128_op_Impliciti2i16(val) (__int128_t)(val)
#define System_Int128_op_Implicitu2i16(val) (__int128_t)(val)
#define System_Int128_op_Impliciti4i16(val) (__int128_t)(val)
#define System_Int128_op_Implicitu4i16(val) (__int128_t)(val)
#define System_Int128_op_Impliciti8i16(val) (__int128_t)(val)
#define System_Int128_op_Implicitu8i16(val) (__int128_t)(val)
#define System_Int128_op_Implicitisi16(val) (__int128_t)(val)
#define System_Int128_op_Implicitusi16(val) (__int128_t)(val)

#define System_UInt128_op_Implicitu1u16(val) (__uint128_t)(val)
#define System_UInt128_op_Implicitu2u16(val) (__uint128_t)(val)
#define System_UInt128_op_Implicitu4u16(val) (__uint128_t)(val)
#define System_UInt128_op_Implicitu8u16(val) (__uint128_t)(val)
#define System_UInt128_op_Implicitusu16(val) (__uint128_t)(val)

#define System_Int128_op_OnesComplementi16i16(val) ~val
#define System_UInt128_op_OnesComplementu16u16(val) ~val

#define System_Buffers_Binary_BinaryPrimitives_ReverseEndiannessi16i16(val) (__int128_t) __builtin_bswap128((__uint128_t)val)
#define System_Buffers_Binary_BinaryPrimitives_ReverseEndiannessu16u16 __builtin_bswap128
#define System_Buffers_Binary_BinaryPrimitives_ReverseEndiannessi1i1(val) val

#define System_Buffers_Binary_BinaryPrimitives_ReverseEndiannessu8u8 __builtin_bswap64
#define System_Buffers_Binary_BinaryPrimitives_ReverseEndiannessi8i8(val) (int64_t) __builtin_bswap64((uint64_t)val)
#define System_Buffers_Binary_BinaryPrimitives_ReverseEndiannessu4u4 __builtin_bswap32
#define System_Buffers_Binary_BinaryPrimitives_ReverseEndiannessi4i4(val) (int32_t) __builtin_bswap32((uint32_t)val)
#define System_Buffers_Binary_BinaryPrimitives_ReverseEndiannessu2u2 __builtin_bswap16
#define System_Buffers_Binary_BinaryPrimitives_ReverseEndiannessi2i2(val) (int16_t) __builtin_bswap16((uint16_t)val)
/*Assumes a 64 bit OS.*/
#define System_Buffers_Binary_BinaryPrimitives_ReverseEndiannessisis(val) (intptr_t) __builtin_bswap64((uint64_t)val)
#define System_Buffers_Binary_BinaryPrimitives_ReverseEndiannessusus __builtin_bswap64

#define System_Numerics_BitOperations_TrailingZeroCountusi4(val) (int32_t) __builtin_ctzl((uint64_t)val)
#define System_Numerics_BitOperations_TrailingZeroCountu4i4(val) (int32_t) __builtin_ctzl((uint64_t)val)
#define System_Numerics_BitOperations_TrailingZeroCountu8i4(val) (int32_t) __builtin_ctzl((uint64_t)val)
static inline int32_t System_Numerics_BitOperations_LeadingZeroCountu8i4(uint64_t val) { return __builtin_clzl(val); }
static inline int32_t System_Numerics_BitOperations_LeadingZeroCountusi4(uintptr_t val) { return __builtin_clzl((uint64_t)val); }
__uint128_t __builtin_bswap128(__uint128_t val);

#define System_Numerics_BitOperations_PopCountusi4(val) __builtin_popcountl((uint64_t)val)
#define System_Numerics_BitOperations_PopCountu4i4(val) __builtin_popcountl((uint32_t)val)
#define System_Numerics_BitOperations_PopCountu8i4(val) __builtin_popcountl((uint64_t)val)

#define System_Console_WriteLinestv(msg) printf("%s", msg)
#define System_String_Concatststst(a, b) a b
#define System_String_Concatstststst(a, b, c) a b c
#define System_String_Concatststststst(a, b, c, d) a b c d
static inline void System_Console_WriteLineu8v(uint64_t arg)
{
    printf("%lu\n", arg);
}
static inline void System_Console_WriteLinei8v(int64_t arg)
{
    printf("%ld\n", arg);
}
#define System_Console_WriteLineu4v(arg) printf("%u\n", arg)
static inline void System_Console_WriteLinei4v(int32_t arg)
{
    printf("%u\n", arg);
}
int execvp(void *file, void *argv);

#define System_UIntPtr_get_MaxValueus() UINTPTR_MAX
#define System_UIntPtr_get_MinValueus() ((uintptr_t)0)

#define System_IntPtr_get_MaxValueis() INTPTR_MAX
#define System_IntPtr_get_MinValueis() INTPTR_MIN

#define System_Exception__ctor14System_Runtime16System_Exceptionsv
#define System_Exception__ctorp14System_Runtime16System_Exceptionsv
#define System_Exception__ctorp14System_Runtime16System_Exceptionstv
static inline float System_Single_Clampf4f4f4f4(float d, float min, float max)
{
    const float t = d < min ? min : d;
    return t > max ? max : t;
}
static inline double System_Double_Clampf8f8f8f8(double d, double min, double max)
{
    const double t = d < min ? min : d;
    return t > max ? max : t;
}
static inline double System_Double_FusedMultiplyAddf8f8f8f8(double left, double right, double addend)
{
    return left * right + addend;
}
#define System_Type_GetTypeFromHandle14System_Runtime24System_RuntimeTypeHandle14System_Runtime11System_Type
#define System_Type_GetTypeFromHandlep14System_Runtime24System_RuntimeTypeHandle14System_Runtime11System_Type
#define System_Object_GetHashCode14System_Runtime11System_Typei4
#define System_Object_GetHashCodep14System_Runtime11System_Typei4
static inline float System_Single_MaxNumberf4f4f4(float a, float b)
{
    if (a > b)
        return a;
    else
        return b;
}
static inline double System_Double_MaxNumberf8f8f8(double a, double b)
{
    if (a > b)
        return a;
    else
        return b;
}
static inline float System_Single_MinNumberf4f4f4(float a, float b)
{
    if (a < b)
        return a;
    else
        return b;
}
static inline double System_Double_MinNumberf8f8f8(double a, double b)
{
    if (a < b)
        return a;
    else
        return b;
}
static inline float System_Single_FusedMultiplyAddf4f4f4f4(float left, float right, float addend)
{
    return left * right + addend;
}
static inline float System_Single_CopySignf4f4f4(float mag, float sign)
{
    if (sign > 0)
    {
        if (mag > 0)
            return mag;
        else
            return -mag;
    }
    else
    {
        if (mag > 0)
            return -mag;
        else
            return mag;
    }
}
static inline double System_Double_CopySignf8f8f8(double mag, double sign)
{
    if (sign > 0)
    {
        if (mag > 0)
            return mag;
        else
            return -mag;
    }
    else
    {
        if (mag > 0)
            return -mag;
        else
            return mag;
    }
}
BUILTIN_UNSUPORTED(System_MathF_Truncatef4f4,float,(float val))

double fabsf64(double val);
#define System_Single_Cosf4f4(x) ((float)cos(x))
#define System_Double_Cosf8f8 cos
#define System_Single_Sinf4f4(x) ((float)sin(x))
#define System_Double_Sinf8f8 sin
#define System_Double_Absf8f8 fabsf64
#define System_Single_Absf4f4 fabsf32
#define System_MathF_Sqrtf4f4(x) (float)sqrt((double)x)
#define System_MathF_Sqrtf8f8 sqrt
#define System_MathF_Roundf4f4(x) (float)round((double)x)
#define System_Single_Powf4f4f4(a, b) (float)pow(a, b)
#define System_Single_Powf8f8f8 pow
#define System_Double_Powf8f8f8 pow
#define System_Int128_get_Zeroi16(v) ((__int128_t)0)
#define System_Math_Minisisis(x, y) (((x) < (y)) ? (x) : (y))
#define System_Math_Maxisisis(x, y) (((x) > (y)) ? (x) : (y))
#define System_Math_Minususus(x, y) (((x) < (y)) ? (x) : (y))
#define System_Math_Maxususus(x, y) (((x) > (y)) ? (x) : (y))

typedef struct TSWData
{
    void *start_routine;
    void *arg;
} TSWData;
void _tcctor();
static inline void *thread_start_wrapper(TSWData *data)
{
    _tcctor();
    void *(*start_routine)(void *) = (void *)data->start_routine;
    void *arg = data->arg;
    free(data);
    return start_routine(arg);
}
int32_t pthread_create(void *thread,
                       void *attr,
                       void *(*start_routine)(void *),
                       void *threadarg);
static inline int32_t pthread_create_wrapper(void *thread,
                               void *attr,
                               void *start_routine,
                               void *arg)
{
    TSWData *data = malloc(sizeof(TSWData));
    data->start_routine = start_routine;
    data->arg = arg;

    return pthread_create(thread, attr, (void *)thread_start_wrapper, data);
}
#define pthread_create pthread_create_alias
BUILTIN_UNSUPORTED(System_Single_Exp2f4f4,float,(float input));
BUILTIN_UNSUPORTED(System_Double_Log10f8f8,double,(double input));
BUILTIN_UNSUPORTED(System_Single_Expf4f4,float,(float input));
BUILTIN_UNSUPORTED(System_Double_Expf8f8,double,(double input));
BUILTIN_UNSUPORTED(System_Single_Logf4f4,float,(float input));
BUILTIN_UNSUPORTED(System_Single_Log2f4f4,float,(float input));
BUILTIN_UNSUPORTED(System_Single_Log10f4f4,float,(float input));
BUILTIN_UNSUPORTED(System_Double_Logf8f8,double,(double input));
BUILTIN_UNSUPORTED(System_Double_Log2f8f8,double,(double input));
#define System_Math_Roundf8f8(input) round(input)
#define System_Math_Floorf8f8(input) floor(input)
#define System_Math_Sqrtf8f8(input) sqrt(input)
#define System_Math_Ceilingf8f8(input) ceil(input)
#define System_MathF_Ceilingf4f4(input) (float)ceil((double)input)
#define System_Math_Floorf8f8(input) floor(input)
#define System_MathF_Floorf4f4(input) (float)floor((double)input)
#define System_Math_Truncatef8f8(input) trunc(input)
BUILTIN_UNSUPORTED(System_UInt32_RotateRightu4i4u4,uint32_t,(uint32_t val, int32_t ammount))
BUILTIN_UNSUPORTED(System_UIntPtr_RotateRightusi4us,uintptr_t,(uintptr_t val, uintptr_t ammount))
BUILTIN_UNSUPORTED(System_Byte_RotateRightu1i4u1,uint8_t,(uint8_t val, int32_t ammount))


static inline uint32_t System_Threading_Interlocked_CompareExchangeru4u4u4u4(uint32_t *addr, uint32_t value, uint32_t comparand)
{
    uint32_t res = 0;
    if (__atomic_compare_exchange_n(addr, &comparand, value, true, 5, 5))
    {
        return comparand;
    }
    else
    {
        /* On failure, value is written to comparand. */
        return comparand;
    }
}
static inline uint64_t System_Threading_Interlocked_CompareExchangeru8u8u8u8(uint64_t *addr, uint64_t value, uint64_t comparand)
{
    uint64_t res = 0;
    if (__atomic_compare_exchange_n(addr, &comparand, value, true, 5, 5))
    {
        return comparand;
    }
    else
    {
        /* On failure, value is written to comparand. */
        return comparand;
    }
}
static inline uintptr_t System_Threading_Interlocked_CompareExchangerusususus(uintptr_t *addr, uintptr_t value, uintptr_t comparand)
{
    uintptr_t res = 0;
    if (__atomic_compare_exchange_n(addr, &comparand, value, true, 5, 5))
    {
        return comparand;
    }
    else
    {
        /* On failure, value is written to comparand. */
        return comparand;
    }
}
static inline intptr_t System_Threading_Interlocked_CompareExchangerisisisis(intptr_t *addr, intptr_t value, intptr_t comparand)
{
    intptr_t res = 0;
    if (__atomic_compare_exchange_n(addr, &comparand, value, true, 5, 5))
    {
        return comparand;
    }
    else
    {
        /* On failure, value is written to comparand. */
        return comparand;
    }
}

static inline uint32_t System_Threading_Interlocked_Exchangeru4u4u4(uint32_t *addr, uint32_t val)
{
    uint32_t ret;
    __atomic_exchange(addr, &val, &ret, 5);
    return ret;
}
static inline uintptr_t System_Threading_Interlocked_Exchangerususus(uintptr_t *addr, uintptr_t val)
{
    uintptr_t ret;
    __atomic_exchange(addr, &val, &ret, 5);
    return ret;
}
static inline uint32_t System_Threading_Interlocked_Addru4u4u4(uint32_t *addr, uint32_t addend)
{
    fprintf(stderr, "Can't System_Threading_Interlocked_Addru4u4u4 yet.\n");
    abort();
}
static inline uint32_t System_UInt32_RotateLeftu4i4u4(uint32_t val, int32_t ammount)
{
    fprintf(stderr, "Can't System_UInt32_RotateLeftu4i4u4 yet.\n");
    abort();
}
static inline uintptr_t System_UIntPtr_RotateLeftusi4us(uintptr_t val, uintptr_t ammount)
{
    fprintf(stderr, "Can't System_UIntPtr_RotateLeftusi4us yet.\n");
    abort();
}

static inline uint16_t System_UInt16_RotateRightu2i4u2(uint16_t val, int32_t ammount)
{
    fprintf(stderr, "Can't System_UInt16_RotateRightu2i4u2 yet.\n");
    abort();
}
static inline uint16_t System_UInt16_RotateLeftu2i4u2(uint16_t val, int32_t ammount)
{
    fprintf(stderr, "Can't System_UInt16_RotateLeftu2i4u2 yet.\n");
    abort();
}

static inline uint64_t System_UInt64_RotateRightu8i4u8(uint64_t val, int32_t ammount)
{
    fprintf(stderr, "Can't System_UInt64_RotateRightu8i4u8 yet.\n");
    abort();
}
static inline uint16_t System_UInt128_RotateLeftu16i4u16(uint16_t val, int32_t ammount)
{
    fprintf(stderr, "Can't System_UInt128_RotateLeftu16i4u16 yet.\n");
    abort();
}
static inline uint64_t System_UInt64_RotateLeftu8i4u8(uint64_t val, int32_t ammount)
{
    ammount = ammount % 64;
    return (val << ammount) | (val >> (64 - ammount));
}
static inline unsigned __int128 System_UInt128_RotateRightu16i4u16(unsigned __int128 val, int32_t amount)
{
    fprintf(stderr, "Can't System_UInt128_RotateRightu16i4u16 yet.\n");
    abort();
}
static inline uint8_t System_Byte_RotateLeftu1i4u1(uint8_t val, int32_t ammount)
{
    fprintf(stderr, "Can't System_Byte_RotateLeftu1i4u1 yet.\n");
    abort();
}
static inline unsigned __int128 System_UInt128_LeadingZeroCountu16u16(unsigned __int128 val)
{
    fprintf(stderr, "Can't System_UInt128_LeadingZeroCountu16u16 yet.\n");
    abort();
}
static inline unsigned __int128 System_UInt128_PopCountu16u16(unsigned __int128 val)
{
    fprintf(stderr, "Can't System_UInt128_PopCountu16u16 yet.\n");
    abort();
}
static inline unsigned __int128 System_UInt128_TrailingZeroCountu16u16(unsigned __int128 val)
{
    fprintf(stderr, "Can't System_UInt128_TrailingZeroCountu16u16 yet.\n");
    abort();
}
static inline uint32_t System_Math_Minu4u4u4(uint32_t lhs, uint32_t rhs)
{
    if (lhs > rhs)
    {
        return rhs;
    }
    else
    {
        return lhs;
    }
}
static inline int32_t System_Math_Clampi4i4i4i4(int32_t val, int32_t min, int32_t max)
{
    if (val > max)
    {
        return max;
    }
    else if (val < min)
    {
        return min;
    }
    else
    {
        return val;
    }
}
static inline int64_t System_Math_Clampi8i8i8i8(int64_t val, int64_t min, int64_t max)
{
    if (val > max)
    {
        return max;
    }
    else if (val < min)
    {
        return min;
    }
    else
    {
        return val;
    }
}

static inline __int128 System_Int128_Clampi16i16i16i16(__int128 val, __int128 min, __int128 max)
{
    if (val > max)
    {
        return max;
    }
    else if (val < min)
    {
        return min;
    }
    else
    {
        return val;
    }
}
static inline __int128 System_Int128_get_MinValuei16()
{
    fprintf(stderr, "Can't System_Int128_get_MinValuei16 yet.\n");
    abort();
}
static inline __int128 System_Int128_get_MaxValuei16()
{
    fprintf(stderr, "Can't System_Int128_get_MinValuei16 yet.\n");
    abort();
}

static inline double System_Double_Exp2f8f8(double val)
{
    fprintf(stderr, "Can't System_Double_Exp2f8f8 yet.\n");
    abort();
}
static inline void System_Threading_Thread_MemoryBarrierv() {}
static int argc;
static char **argv;
static inline char **System_Environment_GetCommandLineArgsa1st() { return argv; }
static inline uintptr_t ld_len(void *arr)
{
    void **elem = (void **)arr;
    uintptr_t len = 0;
    while (*elem != 0)
    {
        len += 1;
        elem += 1;
    }
    return len;
}
static inline intptr_t System_Runtime_InteropServices_Marshal_StringToCoTaskMemUTF8stis(char *str)
{
    uintptr_t len = strlen(str);
    char *ptr = (char *)malloc(len + 1);
    memcpy(ptr, str, len + 1);
    return len;
}
float fabsf32(float input);
#define System_Half_op_Explicitf4f2(f)(_Float16)(f)
#define TYPEDEF_SIMDVEC(TYPE, MANGLED, SIZE) \
    typedef struct __simdvec##MANGLED##SIZE  \
    {                                        \
        TYPE arr[SIZE];                      \
    } __simdvec##MANGLED##SIZE;
#define TYPEDEF_SIMDVECS_TYPE(TYPE, MANGLED) TYPEDEF_SIMDVEC(TYPE, MANGLED, 2) TYPEDEF_SIMDVEC(TYPE, MANGLED, 4) TYPEDEF_SIMDVEC(TYPE, MANGLED, 8) TYPEDEF_SIMDVEC(TYPE, MANGLED, 16) TYPEDEF_SIMDVEC(TYPE, MANGLED, 32) TYPEDEF_SIMDVEC(TYPE, MANGLED, 64)
TYPEDEF_SIMDVECS_TYPE(int8_t, i1)
TYPEDEF_SIMDVECS_TYPE(int16_t, i2)
TYPEDEF_SIMDVECS_TYPE(int32_t, i4)
TYPEDEF_SIMDVECS_TYPE(int64_t, i8)
TYPEDEF_SIMDVECS_TYPE(uint8_t, u1)
TYPEDEF_SIMDVECS_TYPE(uint16_t, u2)
TYPEDEF_SIMDVECS_TYPE(uint32_t, u4)
TYPEDEF_SIMDVECS_TYPE(uint64_t, u8)
TYPEDEF_SIMDVECS_TYPE(float, f4)
TYPEDEF_SIMDVECS_TYPE(double, f8)

static const float inff = 1.0 / 0.0;
static const double inf = 1.0 / 0.0;
int fcntl(int fd, int op, ...);
long syscall(long number, ...);
static inline uint8_t **get_environ()
{
    extern char **environ;
    return (uint8_t **)environ;
}
union System_MidpointRounding{int32_t inner;};
static inline double System_Math_Roundf814System_Runtime23System_MidpointRoundingf8(double val,union System_MidpointRounding rounding){
	return round(val);
}
static inline float System_MathF_Roundf414System_Runtime23System_MidpointRoundingf4(float val,union System_MidpointRounding rounding){
	return roundf(val);
}

int ioctl(int fd, unsigned long op, ...);
int pthread_attr_init(void* attr);
int pthread_attr_destroy(void* attr);
int poll(void *fds, uint64_t nfds, int timeout);
int pthread_getattr_np(uint64_t thread, void *attr);
int pthread_attr_getstack(void *attr,
                          void *stackaddr, size_t *stacksize);
int sched_getaffinity(int32_t pid, size_t cpusetsize,
                      void *mask);
