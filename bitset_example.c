#include "bitset.c"
#include <stdio.h>

void print_bitset(Bitset b) {
	for (int i = b.size - 1; i >= 0; i--)
		printf("%d", bitset_get(b, i));
	printf("\n");
}

int main() {
	Bitset b = bitset_create(5);
	
	bitset_set(&b, 2);
	printf("%d\n", bitset_get(b, 2));
	bitset_unset(&b, 2);
	
	Bitset b2 =  bitset_create_mask(5, 3);
	
	print_bitset(bitset_union(b, b2));
	print_bitset(bitset_difference(b, b2));
	print_bitset(bitset_intersection(b, b2));
}
