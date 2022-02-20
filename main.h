#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bitmap.h"
#include "debug.h"
#include "hash.h"
#include "hex_dump.h"
#include "limits.h"
#include "list.h"
#include "round.h"

#define MAX_BITMAP_CNT 10
#define MAX_BITMAP_NAME_SIZE 10
#define MAX_HASH_CNT 10
#define MAX_HASH_NAME_SIZE 10
#define MAX_LIST_CNT 10
#define MAX_LIST_NAME_SIZE 10

struct bitmap * look_for_bitmap(char * name);
struct hash * look_for_hash(char * name);
struct list * look_for_list(char * name);
void destructor(struct hash_elem * ptr, void * aux);
unsigned hash_hash (const struct hash_elem *e, void *aux);
bool hash_less (const struct hash_elem *a, const struct hash_elem *b, void *aux);
void hash_square (struct hash_elem *e, void *aux);
void hash_triple (struct hash_elem *e, void *aux);
