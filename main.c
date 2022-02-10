#include "main.h"

char input[81];
char *cmd, *arg[7];
struct bitmap * bitmap_pointers[MAX_BITMAP_CNT];
char bitmap_names[MAX_BITMAP_CNT][MAX_BITMAP_NAME_SIZE];
int bitmap_current = -1;

struct bitmap * look_for_bitmap(char * name) {
	for (int i = 0; i <= bitmap_current; i++) {
		if (!strcmp(name, bitmap_names[i]))
			return bitmap_pointers[i];
	}
	return NULL;
}

int main() {
	while(1) {
		fgets(input, sizeof(input), stdin);
		input[strlen(input) - 1] = '\0';
		cmd = strtok(input, " ");
		for (int i = 0; i < 7 && (arg[i] = strtok(NULL, " ")); i++);
		
		if (!strcmp(cmd, "bitmap_all")) {
			printf("%s\n", bitmap_all(look_for_bitmap(arg[0]), atoi(arg[1]), atoi(arg[2])) ? "true" : "false");
		}
		else if (!strcmp(cmd, "bitmap_any")) {
			printf("%s\n", bitmap_any(look_for_bitmap(arg[0]), atoi(arg[1]), atoi(arg[2])) ? "true" : "false");
        }
		else if (!strcmp(cmd, "bitmap_contains")) {
			printf("%s\n", bitmap_contains(look_for_bitmap(arg[0]), atoi(arg[1]), atoi(arg[2]), atoi(arg[3])) ? "true" : "false");
        }
		else if (!strcmp(cmd, "bitmap_count")) {
			printf("%zu\n", bitmap_count(look_for_bitmap(arg[0]), atoi(arg[1]), atoi(arg[2]), atoi(arg[3])));
        }
		else if (!strcmp(cmd, "bitmap_dump")) {
			bitmap_dump(look_for_bitmap(arg[0]));
		}
		else if (!strcmp(cmd, "bitmap_expand")) {
		//TODO
        }
		else if (!strcmp(cmd, "bitmap_flip")) {
			bitmap_flip(look_for_bitmap(arg[0]), atoi(arg[1]));
		}
		else if (!strcmp(cmd, "bitmap_mark")) {
			bitmap_mark(look_for_bitmap(arg[0]), atoi(arg[1]));
        }
		else if (!strcmp(cmd, "bitmap_none")) {
			printf("%s\n", bitmap_none(look_for_bitmap(arg[0]), atoi(arg[1]), atoi(arg[2])) ? "true" : "false");
        }
		else if (!strcmp(cmd, "bitmap_reset")) {
			bitmap_reset(look_for_bitmap(arg[0]), atoi(arg[1]));
        }
		else if (!strcmp(cmd, "bitmap_scan")) {
			printf("%zu\n", bitmap_scan(look_for_bitmap(arg[0]), atoi(arg[1]), atoi(arg[2]), atoi(arg[3])));
        }
		else if (!strcmp(cmd, "bitmap_scan_and_flip")) {
			printf("%zu\n", bitmap_scan_and_flip(look_for_bitmap(arg[0]), atoi(arg[1]), atoi(arg[2]), atoi(arg[3])));
		}
		else if (!strcmp(cmd, "bitmap_set")) {
			bitmap_set(look_for_bitmap(arg[0]), atoi(arg[1]), atoi(arg[2]));
        }
		else if (!strcmp(cmd, "bitmap_set_all")) {
			bitmap_set_all(look_for_bitmap(arg[0]), atoi(arg[1]));
        }
		else if (!strcmp(cmd, "bitmap_set_multiple")) {
			bitmap_set_multiple(look_for_bitmap(arg[0]), atoi(arg[1]), atoi(arg[2]), atoi(arg[3]));
        }
		else if (!strcmp(cmd, "bitmap_size")) {
			printf("%zu\n", bitmap_size(look_for_bitmap(arg[0])));
		}
		else if (!strcmp(cmd, "bitmap_test")) {
			printf("%s\n", bitmap_test(look_for_bitmap(arg[0]), atoi(arg[1])) ? "true" : "false");
		}
		else if (!strcmp(cmd, "create")) {
			if (!strcmp(arg[0], "bitmap")) {
				strcpy(bitmap_names[++bitmap_current], arg[1]);
				bitmap_pointers[bitmap_current] = bitmap_create(atoi(arg[2]));
			}
        }
		else if (!strcmp(cmd, "delete")) {
        }
		else if (!strcmp(cmd, "dumpdata")) {
			//TODO
			bitmap_dump(look_for_bitmap(arg[0]));
		}
		else if (!strcmp(cmd, "hash_apply")) {
        }
		else if (!strcmp(cmd, "hash_clear")) {
        }
		else if (!strcmp(cmd, "hash_delete")) {
        }
		else if (!strcmp(cmd, "hash_empty")) {
        }
		else if (!strcmp(cmd, "hash_find")) {
        }
		else if (!strcmp(cmd, "hash_insert")) {
        }
		else if (!strcmp(cmd, "hash_replace")) {
        }
		else if (!strcmp(cmd, "hash_size")) {
        }
		else if (!strcmp(cmd, "list_back")) {
        }
		else if (!strcmp(cmd, "list_empty")) {
        }
		else if (!strcmp(cmd, "list_front")) {
        }
		else if (!strcmp(cmd, "list_insert")) {
        }
		else if (!strcmp(cmd, "list_insert_ordered")) {
        }
		else if (!strcmp(cmd, "list_max")) {
        }
		else if (!strcmp(cmd, "list_min")) {
        }
		else if (!strcmp(cmd, "list_pop_back")) {
        }
		else if (!strcmp(cmd, "list_pop_front")) {
        }
		else if (!strcmp(cmd, "list_push_back")) {
        }
		else if (!strcmp(cmd, "list_push_front")) {
        }
		else if (!strcmp(cmd, "list_remove")) {
        }
		else if (!strcmp(cmd, "list_reverse")) {
        }
		else if (!strcmp(cmd, "list_shuffle")) {
        }
		else if (!strcmp(cmd, "list_size")) {
        }
		else if (!strcmp(cmd, "list_sort")) {
        }
		else if (!strcmp(cmd, "list_splice")) {
        }
		else if (!strcmp(cmd, "list_swap")) {
        }
		else if (!strcmp(cmd, "list_unique")) {
        }
		else if (!strcmp(cmd, "quit")) {
			break;
		}
	}
}

