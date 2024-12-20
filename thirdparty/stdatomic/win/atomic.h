

#ifndef COMPAT_ATOMICS_WIN32_STDATOMIC_H
#define COMPAT_ATOMICS_WIN32_STDATOMIC_H

#define WIN32_LEAN_AND_MEAN
#include <stddef.h>
#include <stdint.h>
#include <windows.h>

#ifdef __TINYC__
#endif

#define ATOMIC_FLAG_INIT 0

#define ATOMIC_VAR_INIT(value) (value)

#define atomic_init(obj, value) \
    do                          \
    {                           \
        *(obj) = (value);       \
    } while (0)

#define kill_dependency(y) ((void)0)

#define atomic_thread_fence(order) \
    MemoryBarrier();

#define atomic_signal_fence(order) \
    ((void)0)

#define atomic_is_lock_free(obj) 0

typedef intptr_t atomic_flag;
typedef intptr_t atomic_bool;
typedef intptr_t atomic_char;
typedef intptr_t atomic_schar;
typedef intptr_t atomic_uchar;
typedef intptr_t atomic_short;
typedef intptr_t atomic_ushort;
typedef intptr_t atomic_int;
typedef intptr_t atomic_uint;
typedef intptr_t atomic_long;
typedef intptr_t atomic_ulong;
typedef intptr_t atomic_llong;
typedef intptr_t atomic_ullong;
typedef intptr_t atomic_wchar_t;
typedef intptr_t atomic_int_least8_t;
typedef intptr_t atomic_uint_least8_t;
typedef intptr_t atomic_int_least16_t;
typedef intptr_t atomic_uint_least16_t;
typedef intptr_t atomic_int_least32_t;
typedef intptr_t atomic_uint_least32_t;
typedef intptr_t atomic_int_least64_t;
typedef intptr_t atomic_uint_least64_t;
typedef intptr_t atomic_int_fast8_t;
typedef intptr_t atomic_uint_fast8_t;
typedef intptr_t atomic_int_fast16_t;
typedef intptr_t atomic_uint_fast16_t;
typedef intptr_t atomic_int_fast32_t;
typedef intptr_t atomic_uint_fast32_t;
typedef intptr_t atomic_int_fast64_t;
typedef intptr_t atomic_uint_fast64_t;
typedef intptr_t atomic_intptr_t;
typedef intptr_t atomic_uintptr_t;
typedef intptr_t atomic_size_t;
typedef intptr_t atomic_ptrdiff_t;
typedef intptr_t atomic_intmax_t;
typedef intptr_t atomic_uintmax_t;

#ifdef __TINYC__

__CRT_INLINE LONGLONG _InterlockedExchangeAdd64(LONGLONG volatile *Addend, LONGLONG Value)
{
    LONGLONG Old;
    do
    {
        Old = *Addend;
    } while (InterlockedCompareExchange64(Addend, Old + Value, Old) != Old);
    return Old;
}

__CRT_INLINE LONG _InterlockedExchangeAdd(LONG volatile *Addend, LONG Value)
{
    LONG Old;
    do
    {
        Old = *Addend;
    } while (InterlockedCompareExchange(Addend, Old + Value, Old) != Old);
    return Old;
}

__CRT_INLINE SHORT _InterlockedExchangeAdd16(SHORT volatile *Addend, SHORT Value)
{
    SHORT Old;
    do
    {
        Old = *Addend;
    } while (InterlockedCompareExchange16(Addend, Old + Value, Old) != Old);
    return Old;
}

#define InterlockedIncrement64 _InterlockedExchangeAdd64

#endif

#define atomic_store(object, desired) \
    do                                \
    {                                 \
        *(object) = (desired);        \
        MemoryBarrier();              \
    } while (0)

#define atomic_store_explicit(object, desired, order) \
    atomic_store(object, desired)

#define atomic_load(object) \
    (MemoryBarrier(), *(object))

#define atomic_load_explicit(object, order) \
    atomic_load(object)

#define atomic_exchange(object, desired) \
    InterlockedExchangePointer(object, desired)

#define atomic_exchange_explicit(object, desired, order) \
    atomic_exchange(object, desired)

static inline int atomic_compare_exchange_strong(intptr_t *object, intptr_t *expected,
                                                 intptr_t desired)
{
    intptr_t old = *expected;
    *expected = (intptr_t)InterlockedCompareExchangePointer(
        (PVOID *)object, (PVOID)desired, (PVOID)old);
    return *expected == old;
}

#define atomic_compare_exchange_strong_explicit(object, expected, desired, success, failure) \
    atomic_compare_exchange_strong(object, expected, desired)

#define atomic_compare_exchange_weak(object, expected, desired) \
    atomic_compare_exchange_strong(object, expected, desired)

#define atomic_compare_exchange_weak_explicit(object, expected, desired, success, failure) \
    atomic_compare_exchange_weak(object, expected, desired)

#ifdef _WIN64

#define atomic_fetch_add(object, operand) \
    InterlockedExchangeAdd64(object, operand)

#define atomic_fetch_sub(object, operand) \
    InterlockedExchangeAdd64(object, -(operand))

#define atomic_fetch_or(object, operand) \
    InterlockedOr64(object, operand)

#define atomic_fetch_xor(object, operand) \
    InterlockedXor64(object, operand)

#define atomic_fetch_and(object, operand) \
    InterlockedAnd64(object, operand)
#else
#define atomic_fetch_add(object, operand) \
    InterlockedExchangeAdd(object, operand)

#define atomic_fetch_sub(object, operand) \
    InterlockedExchangeAdd(object, -(operand))

#define atomic_fetch_or(object, operand) \
    InterlockedOr(object, operand)

#define atomic_fetch_xor(object, operand) \
    InterlockedXor(object, operand)

#define atomic_fetch_and(object, operand) \
    InterlockedAnd(object, operand)
#endif



#define atomic_load_ptr atomic_load
#define atomic_store_ptr atomic_store
#define atomic_compare_exchange_weak_ptr atomic_compare_exchange_weak
#define atomic_compare_exchange_strong_ptr atomic_compare_exchange_strong
#define atomic_exchange_ptr atomic_exchange
#define atomic_fetch_add_ptr atomic_fetch_add
#define atomic_fetch_sub_ptr atomic_fetch_sub
#define atomic_fetch_and_ptr atomic_fetch_and
#define atomic_fetch_or_ptr atomic_fetch_or
#define atomic_fetch_xor_ptr atomic_fetch_xor

static inline void atomic_store_u64(unsigned long long* object, unsigned long long desired) {
    do {
        *(object) = (desired);
        MemoryBarrier();
    } while (0);
}

static inline unsigned long long atomic_load_u64(unsigned long long* object) {
    return (MemoryBarrier(), *(object));
}

#define atomic_exchange_u64(object, desired) \
    InterlockedExchange64(object, desired)

static inline int atomic_compare_exchange_strong_u64(unsigned long long* object, unsigned long long* expected,
                                                 unsigned long long desired)
{
	unsigned long long old = *expected;
    *expected = InterlockedCompareExchange64(object, desired, old);
    return *expected == old;
}

#define atomic_compare_exchange_weak_u64(object, expected, desired) \
    atomic_compare_exchange_strong_u64(object, expected, desired)

#define atomic_fetch_add_u64(object, operand) \
    InterlockedExchangeAdd64(object, operand)

#define atomic_fetch_sub_u64(object, operand) \
    InterlockedExchangeAdd64(object, -(operand))

#define atomic_fetch_or_u64(object, operand) \
    InterlockedOr64(object, operand)

#define atomic_fetch_xor_u64(object, operand) \
    InterlockedXor64(object, operand)

#define atomic_fetch_and_u64(object, operand) \
    InterlockedAnd64(object, operand)



static inline void atomic_store_u32(unsigned* object, unsigned desired) {
    do {
        *(object) = (desired);
        MemoryBarrier();
    } while (0);
}

static inline unsigned atomic_load_u32(unsigned* object) {
    return (MemoryBarrier(), *(object));
}

#define atomic_exchange_u32(object, desired) \
    InterlockedExchange(object, desired)

static inline int atomic_compare_exchange_strong_u32(unsigned* object, unsigned* expected,
                                                 unsigned desired)
{
	unsigned old = *expected;
    *expected = InterlockedCompareExchange((void *)object, desired, old);
    return *expected == old;
}

#define atomic_compare_exchange_weak_u32(object, expected, desired) \
    atomic_compare_exchange_strong_u32(object, expected, desired)

#define atomic_fetch_add_u32(object, operand) \
    InterlockedExchangeAdd(object, operand)

#define atomic_fetch_sub_u32(object, operand) \
    InterlockedExchangeAdd(object, -(operand))

#define atomic_fetch_or_u32(object, operand) \
    InterlockedOr(object, operand)

#define atomic_fetch_xor_u32(object, operand) \
    InterlockedXor(object, operand)

#define atomic_fetch_and_u32(object, operand) \
    InterlockedAnd(object, operand)



static inline void atomic_store_u16(unsigned short* object, unsigned short desired) {
    do {
        *(object) = (desired);
        MemoryBarrier();
    } while (0);
}

static inline unsigned short atomic_load_u16(unsigned short* object) {
    return (MemoryBarrier(), *(object));
}

#define atomic_exchange_u16(object, desired) \
    InterlockedExchange16(object, desired)

static inline int atomic_compare_exchange_strong_u16(unsigned short* object, unsigned short* expected,
                                                 unsigned short desired)
{
	unsigned short old = *expected;
    *expected = InterlockedCompareExchange16(object, desired, old);
    return *expected == old;
}

#define atomic_compare_exchange_weak_u16(object, expected, desired) \
    atomic_compare_exchange_strong_u16((void*)object, expected, desired)

#define atomic_fetch_add_u16(object, operand) \
    InterlockedExchangeAdd16(object, operand)

#define atomic_fetch_sub_u16(object, operand) \
    InterlockedExchangeAdd16(object, -(operand))

#define atomic_fetch_or_u16(object, operand) \
    InterlockedOr16(object, operand)

#define atomic_fetch_xor_u16(object, operand) \
    InterlockedXor16(object, operand)

#define atomic_fetch_and_u16(object, operand) \
    InterlockedAnd16(object, operand)



#define atomic_fetch_add_explicit(object, operand, order) \
    atomic_fetch_add(object, operand)

#define atomic_fetch_sub_explicit(object, operand, order) \
    atomic_fetch_sub(object, operand)

#define atomic_fetch_or_explicit(object, operand, order) \
    atomic_fetch_or(object, operand)

#define atomic_fetch_xor_explicit(object, operand, order) \
    atomic_fetch_xor(object, operand)

#define atomic_fetch_and_explicit(object, operand, order) \
    atomic_fetch_and(object, operand)

#define atomic_flag_test_and_set(object) \
    atomic_exchange(object, 1)

#define atomic_flag_test_and_set_explicit(object, order) \
    atomic_flag_test_and_set(object)

#define atomic_flag_clear(object) \
    atomic_store(object, 0)

#define atomic_flag_clear_explicit(object, order) \
    atomic_flag_clear(object)

#endif
