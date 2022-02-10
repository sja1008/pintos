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

#define MAX_BITMAP_CNT 20
#define MAX_BITMAP_NAME_SIZE 10

struct bitmap * look_for_bitmap(char * name);
