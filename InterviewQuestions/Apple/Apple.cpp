

#include "Apple.h"


typedef struct allocatorStruc{
	allocatorStruc * next;
	size_t length;
	size_t base;
}allocatorStruc;

#define BAD_ALLOCATION -1

typedef struct{
	vaddr_t base;
	size_t length;
	size_t granularity;
	allocatorStruc * pAllocatorStruc;
}rangeAllocatorStruc;




int main()
{
	
	return 0;
}

ralloc_t create_range_allocator(vaddr_t base, size_t length, size_t granularity)
{
	rangeAllocatorStruc * alloc = NULL;
	if (!base  && !length)
	{
		alloc = new rangeAllocatorStruc;
		alloc->length = length;
		alloc->granularity = granularity;
		alloc->base = base;
		alloc->pAllocatorStruc = NULL;
	}
	else
		//S("Input Error");

	return (ralloc_t)alloc;
}
	


vaddr_t any(ralloc_t ralloc, size_t length);
vaddr_t exact(ralloc_t ralloc, size_t length, vaddr_t addr);
vaddr_t above(ralloc_t ralloc, size_t length, vaddr_t addr);
vaddr_t below(ralloc_t ralloc, size_t length, vaddr_t addr);

vaddr_t allocate_range(ralloc_t ralloc, size_t length, allocation_flags flags, vaddr_t optional_hint)
{
	vaddr_t base = BAD_ALLOCATION;
	if (ralloc  && length  )
	{
		switch (flags){

		case ALLOCATE_ANY:
			base = any(ralloc, length);
			break;
		case ALLOCATE_EXACT:
			base = exact(ralloc, length, optional_hint);
			break;
		case ALLOCATE_ABOVE:
			base = above(ralloc, length, optional_hint);
			break;
		case ALLOCATE_BELOW:
			base = below(ralloc, length, optional_hint);
			break;

		default:
			//printf("Input Error");
			break;
		}
	}
	else
		//printf("Input Error");
	
	return base;

}

vaddr_t any(ralloc_t ralloc, size_t length)
{
	vaddr_t base = BAD_ALLOCATION;

	rangeAllocatorStruc * pRangeAlloc = (rangeAllocatorStruc*)ralloc;
	allocatorStruc * allocStruc = pRangeAlloc->pAllocatorStruc;

	size_t  newLength = length + pRangeAlloc->granularity - (length % pRangeAlloc->granularity);
	
	if (allocStruc == nullptr || (pRangeAlloc->base + newLength) <= allocStruc->base)
	{
		allocatorStruc * allocStrucNew = new allocatorStruc;
		allocStrucNew->next = allocStruc;
		pRangeAlloc->pAllocatorStruc = allocStrucNew;
		allocStrucNew->base = pRangeAlloc->base;
		base = allocStrucNew->base;
		allocStrucNew->length = newLength;
	}
	else
	{
		/* Locate the node before the point of insertion */
		//i look at the next data so it should not be null
		allocatorStruc * current = allocStruc;
		while (current->next != nullptr && ((current->next->base - (current->base + current->length) ) > newLength))
		{
			current = current->next;
		}
		
		//last struct 
		if (current->next = nullptr)
			if (((pRangeAlloc->base + pRangeAlloc->length) - (current->base + current->length)) <= newLength)
			{
				allocatorStruc * allocStrucNew = new allocatorStruc;
				current->next = allocStrucNew;
				allocStrucNew->base = current->base + current->length;
				base = allocStrucNew->base;
				allocStrucNew->length = newLength;
			}
			else
				base = BAD_ALLOCATION;

		else
		{
			allocatorStruc * allocStrucNew = new allocatorStruc;
			allocStrucNew->next = current->next;
			current->next = allocStrucNew;
			allocStrucNew->base = current->base + current->length;
			base = allocStrucNew->base;
			allocStrucNew->length = newLength;
		}
	}

	return base;
}



vaddr_t exact(ralloc_t ralloc, size_t length, vaddr_t addr)
{
	vaddr_t base = BAD_ALLOCATION;

	rangeAllocatorStruc * pRangeAlloc = (rangeAllocatorStruc*)ralloc;
	allocatorStruc * allocStruc = pRangeAlloc->pAllocatorStruc;

	size_t  newLength = length + pRangeAlloc->granularity - (length % pRangeAlloc->granularity);

	//boundries
	if (pRangeAlloc->base <= addr && addr < (pRangeAlloc->base + pRangeAlloc->length) && (addr + newLength) < (pRangeAlloc->base + pRangeAlloc->length))
	{
		if (allocStruc == nullptr || (addr < allocStruc->base && (addr + newLength) <= allocStruc->base))
		{
			allocatorStruc * allocStrucNew = new allocatorStruc;
			allocStrucNew->next = allocStruc;
			pRangeAlloc->pAllocatorStruc = allocStrucNew;
			allocStrucNew->base = addr;
			base = addr;
			allocStrucNew->length = newLength;
		}
		else
		{
			/* Locate the node before the point of insertion */
			//i look at the next data so it should not be null
			allocatorStruc * current = allocStruc;
			while (current->next != nullptr && addr > current->next->base )
			{
				current = current->next;
			}

			//last struct 
			if (current->next = nullptr)
			{
				allocatorStruc * allocStrucNew = new allocatorStruc;
				current->next = allocStrucNew;
				allocStrucNew->base = addr;
				base = addr;
				allocStrucNew->length = newLength;
			}
			else
			{
				if ((addr >= (current->base + current->length)) &&  ( addr + newLength) < current->next->base   )
				{
					allocatorStruc * allocStrucNew = new allocatorStruc;
					allocStrucNew->next = current->next;
					current->next = allocStrucNew;
					allocStrucNew->base = addr;
					base = addr;
					allocStrucNew->length = newLength;
				}
				else
					base = BAD_ALLOCATION;
			}
		}
	}
	return base;
}





// exact code with  addr = addr + 1;
vaddr_t above(ralloc_t ralloc, size_t length, vaddr_t addr)
{
	vaddr_t base = BAD_ALLOCATION;

	addr = addr + 1;
	rangeAllocatorStruc * pRangeAlloc = (rangeAllocatorStruc*)ralloc;
	allocatorStruc * allocStruc = pRangeAlloc->pAllocatorStruc;

	size_t  newLength = length + pRangeAlloc->granularity - (length % pRangeAlloc->granularity);

	//boundries
	if (pRangeAlloc->base <= (addr)  && addr < (pRangeAlloc->base + pRangeAlloc->length) && (addr + newLength) < (pRangeAlloc->base + pRangeAlloc->length))
	{
		if (allocStruc == nullptr || (addr < allocStruc->base && (addr + newLength) <= allocStruc->base))
		{
			allocatorStruc * allocStrucNew = new allocatorStruc;
			allocStrucNew->next = allocStruc;
			pRangeAlloc->pAllocatorStruc = allocStrucNew;
			allocStrucNew->base = addr;
			base = addr;
			allocStrucNew->length = newLength;
		}
		else
		{
			/* Locate the node before the point of insertion */
			//i look at the next data so it should not be null
			allocatorStruc * current = allocStruc;
			//NOT
			while (current->next != nullptr &&  !(addr <= current->next->base && (addr + newLength) <= current->next->base))
			{
				current = current->next;
			}

			//last struct 
			if (current->next = nullptr )
			{
				if ((addr + newLength) <= (pRangeAlloc->base + pRangeAlloc->length))
				{
					allocatorStruc * allocStrucNew = new allocatorStruc;
					current->next = allocStrucNew;
					allocStrucNew->base = addr;
					base = addr;
					allocStrucNew->length = newLength;
				}
				else
					base = BAD_ALLOCATION;
			}
			else
			{
				allocatorStruc * allocStrucNew = new allocatorStruc;
				allocStrucNew->next = current->next;
				current->next = allocStrucNew;
				allocStrucNew->base = addr;
				base = addr;
				allocStrucNew->length = newLength;
			}
		}
	}
	return base;
}


//any code with  pRangeAlloc->length = addr
vaddr_t below(ralloc_t ralloc, size_t length, vaddr_t addr)
{
	vaddr_t base = BAD_ALLOCATION;

	rangeAllocatorStruc * pRangeAlloc = (rangeAllocatorStruc*)ralloc;
	allocatorStruc * allocStruc = pRangeAlloc->pAllocatorStruc;

	size_t  newLength = length + pRangeAlloc->granularity - (length % pRangeAlloc->granularity);

	if (allocStruc == nullptr || (pRangeAlloc->base + newLength) <= allocStruc->base)
	{
		allocatorStruc * allocStrucNew = new allocatorStruc;
		allocStrucNew->next = allocStruc;
		pRangeAlloc->pAllocatorStruc = allocStrucNew;
		allocStrucNew->base = pRangeAlloc->base;
		base = allocStrucNew->base;
		allocStrucNew->length = newLength;
	}
	else
	{
		/* Locate the node before the point of insertion */
		//i look at the next data so it should not be null
		//need to do 
		allocatorStruc * current = allocStruc;
		while (current->next != nullptr && ((current->next->base - (current->base + current->length)) > newLength)   )
		{
			current = current->next;
		}

		//last struct 
		if (current->next = nullptr)
			if (((pRangeAlloc->base + addr) - (current->base + current->length)) <= newLength)
			{
				allocatorStruc * allocStrucNew = new allocatorStruc;
				current->next = allocStrucNew;
				allocStrucNew->base = current->base + current->length;
				base = allocStrucNew->base;
				allocStrucNew->length = newLength;
			}
			else
				base = BAD_ALLOCATION;

		else
		{
			allocatorStruc * allocStrucNew = new allocatorStruc;
			allocStrucNew->next = current->next;
			current->next = allocStrucNew;
			allocStrucNew->base = current->base + current->length;
			base = allocStrucNew->base;
			allocStrucNew->length = newLength;
		}
	}

	return base;
}



void destroy_range_allocator(ralloc_t ralloc)
{
	if (ralloc == nullptr)
		return;

	rangeAllocatorStruc * pRangeAlloc = (rangeAllocatorStruc*)ralloc;
	allocatorStruc * allocStruc = pRangeAlloc->pAllocatorStruc;
	
	
	//we try to find the node 
	for (allocatorStruc * current = allocStruc; current != nullptr; )
	{
		allocatorStruc * temp = current;
		current = current->next;
		delete temp;
	}

	delete pRangeAlloc;

}


void free_range(ralloc_t ralloc, vaddr_t base, size_t length)
{
	if (ralloc && length)
	{ 
		rangeAllocatorStruc * pRangeAlloc = (rangeAllocatorStruc*)ralloc;
		allocatorStruc * allocStruc = pRangeAlloc->pAllocatorStruc;

		//we try to find the node 
		for (allocatorStruc * current = allocStruc; current != nullptr; current = current->next)
		{
			if (current->base <= base &&  base < (current->base + current->length))
				current->length = base - current->base;
			else if (current->base <= (base + length) && (base + length) < (current->base + current->length))
			{
				current->length = current->length - (base + length) - current->base;
				current->base = base + length;
			}
			// if length = 0 delte node

		}


	}



}