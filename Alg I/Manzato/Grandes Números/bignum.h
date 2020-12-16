#ifndef bignum_h
#define bignum_h
typedef struct _bignum bignum;

bignum *bignum_create(const char *input);
int bignum_print(bignum *input);
bignum *bignum_sum(bignum *a, bignum *b);
void bignum_destroy(bignum **input);
int bignum_cmp(bignum *a, bignum *b, int absolute);
#endif
