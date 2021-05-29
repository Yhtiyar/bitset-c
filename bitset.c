/**
 * Bitset is the representation of set in bits, 0 means not included, 1 means included.
 * Elements count should begin with 0. Indexing in binary begins with 0, from right side.
 * Example : If there is 5 elements and X = {0, 2, 3} we can represent X as 01101. 
 * 
 * Mask stands for bit representation
 **/

typedef struct {
	int size;
	unsigned long long mask;
} Bitset;

/**
 * Bitset initialization with empty mask
 **/
Bitset bitset_create(int size) {
	Bitset b;
	b.size = size;
	return b;
}

/**
 * Bitset initialization with given mask
 **/
Bitset bitset_create_mask(int size, int mask) {
	Bitset b;
	b.size = size;
	b.mask = mask;
	return b;
}

/**
 * Setting bit at index to 1
 **/
void bitset_set(Bitset *b, int index) {
	b->mask |= (1 << index);
}

/**
 * Setting bit at index to 0
 **/
void bitset_unset(Bitset *b, int index) {
	b->mask &= b->mask ^ (1 << index);
}
/**
 * Returns 1 if bit at index is 1
 **/
int bitset_get(Bitset b, int index) {
	return (b.mask & (1 << index)) != 0;
}

/**
 * Count of ones. Also stands for set size
 **/
int bitset_count(Bitset b) {
	int ans = 0;
	for (int index = 0; index < b.size; index++) {
		ans += bitset_get(b, index);
	}
	return ans;
}
/**
 * Leftest bit that is equal to 1. Also stands for biggest element in a set
 **/
int bitset_leftest(Bitset b) {
	for (int index = b.size - 1; index >= 0; index--) {
		if (bitset_get(b, index))
			return index;
	}
	return -1;
}
/**
 * Rightest bit that is equal to 0. Also stands for smallest element in a set
 **/
int bitset_rightest(Bitset b) {
	for (int  index = 0; index < b.size; index++) {
		if (bitset_get(b, index))
			return index;
	}
	return -1;
}

/**
 * Returns new set that stands for union of l and r
 **/
Bitset bitset_union(Bitset l, Bitset r) {
	return bitset_create_mask(l.size, l.mask | r.mask);
}
/**
 * Returns new set that stands for intersection of l and r
 **/
Bitset bitset_intersection(Bitset l, Bitset r) {
	return bitset_create_mask(l.size, l.mask & r.mask);
}
/**
 * Returns new set that stands for difference of l and r
 **/
Bitset bitset_difference(Bitset l, Bitset r) {
	return bitset_create_mask(l.size, l.mask ^ r.mask);
}

/**
 * Returns new set that stands for set that consist of all elements not contained in b
 **/
Bitset bitset_reverse(Bitset b) {
	return bitset_create_mask(b.size, ~b.mask);
}
/**
 * If r is subset of l
 **/
int bitset_is_subset(Bitset l, Bitset r) {
	return (l.mask | r.mask) == l.mask;
}

/**
 * Returns next subset. NOT includes itself
 **/
Bitset bitset_next_subset(Bitset b) {
	if (b.mask == 0)
		return bitset_create(b.size);
	return bitset_create_mask(b.size, b.mask & (b.mask - 1));
}
