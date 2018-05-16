

#ifndef hwte__range_allocator__hh__
#define hwte__range_allocator__hh__


#include <stdint.h>
#include <stdlib.h>


typedef void *ralloc_t;

typedef enum
{
	ALLOCATE_ANY,
	ALLOCATE_EXACT,
	ALLOCATE_ABOVE,
	ALLOCATE_BELOW,
} allocation_flags;

typedef uintptr_t vaddr_t;

ralloc_t create_range_allocator(
	vaddr_t base, size_t length, size_t granularity);

void destroy_range_allocator(ralloc_t ralloc);

vaddr_t allocate_range(
	ralloc_t ralloc, size_t length,
	allocation_flags flags, vaddr_t optional_hint);

void free_range(
	ralloc_t ralloc, vaddr_t base, size_t length);

#endif


