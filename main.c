#include "main.h"

char input[81];
char *cmd, *arg[7];

struct bitmap * bitmap_pointers[MAX_BITMAP_CNT];
char bitmap_names[MAX_BITMAP_CNT][MAX_BITMAP_NAME_SIZE];
int bitmap_current = -1;

struct hash * hash_pointers[MAX_HASH_CNT];
char hash_names[MAX_HASH_CNT][MAX_HASH_NAME_SIZE];
int hash_current = -1;

struct hash_action_func * hash_action_func_pointers[MAX_HASH_CNT];
char hash_action_func_names[MAX_HASH_CNT][MAX_HASH_NAME_SIZE];
int hash_action_func_current = -1;

struct bitmap * look_for_bitmap(char * name) {
	for (int i = 0; i <= bitmap_current; i++) {
		if (!strcmp(name, bitmap_names[i]))
			return bitmap_pointers[i];
	}
	return NULL;
}

struct hash * look_for_hash(char * name) {
    for (int i = 0; i <= hash_current; i++) {
        if (!strcmp(name, hash_names[i]))
            return hash_pointers[i];
    }
    return NULL;
}

hash_action_func * look_for_hash_action_func(char * name) {
	for (int i = 0; i <= hash_action_func_current; i++) {
        if (!strcmp(name, hash_action_func_names[i]))
            return hash_action_func_pointers[i];
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
			printf("%s\n", bitmap_contains(look_for_bitmap(arg[0]), atoi(arg[1]), atoi(arg[2]), arg[3][0] == 't') ? "true" : "false");
        }
		else if (!strcmp(cmd, "bitmap_count")) {
			printf("%zu\n", bitmap_count(look_for_bitmap(arg[0]), atoi(arg[1]), atoi(arg[2]), arg[3][0] == 't'));
        }
		else if (!strcmp(cmd, "bitmap_dump")) {
			bitmap_dump(look_for_bitmap(arg[0]));
		}
		else if (!strcmp(cmd, "bitmap_expand")) {
			bitmap_expand(look_for_bitmap(arg[0]), atoi(arg[1]));
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
			printf("%zu\n", bitmap_scan(look_for_bitmap(arg[0]), atoi(arg[1]), atoi(arg[2]), arg[3][0] == 't'));
        }
		else if (!strcmp(cmd, "bitmap_scan_and_flip")) {
			printf("%zu\n", bitmap_scan_and_flip(look_for_bitmap(arg[0]), atoi(arg[1]), atoi(arg[2]), arg[3][0] == 't'));
		}
		else if (!strcmp(cmd, "bitmap_set")) {
			bitmap_set(look_for_bitmap(arg[0]), atoi(arg[1]), arg[2][0] == 't');
        }
		else if (!strcmp(cmd, "bitmap_set_all")) {
			bitmap_set_all(look_for_bitmap(arg[0]), arg[1][0] == 't');
        }
		else if (!strcmp(cmd, "bitmap_set_multiple")) {
			bitmap_set_multiple(look_for_bitmap(arg[0]), atoi(arg[1]), atoi(arg[2]), arg[3][0] == 't');
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
			/*else if (!strcmp(arg[0], "hash")) {
				strcpy(hash_names[++hash_current], arg[1]);
				hash_pointers[hash_current] = hash_create(atoi(arg[2]));
			}
			else if (!strcmp(arg[0], "list")) {
				strcpy(list_names[++list_current], arg[1]);
				list_pointers[list_current] = list_create(atoi(arg[2]));
			}*/
        }
		
		else if (!strcmp(cmd, "delete")) {
			//TODO
		}
		else if (!strcmp(cmd, "dumpdata")) {
			//TODO
			struct bitmap * b = look_for_bitmap(arg[0]);
			if (b) {
				for (size_t i = 0; i < bitmap_size(b); i++)
					printf("%d", bitmap_test(b, i));
				printf("\n");
			}
		}
		/*
		else if (!strcmp(cmd, "hash_apply")) {
			hash_apply(look_for_hash(arg[0]), look_for_hash_action_func(arg[1]));
		}
		else if (!strcmp(cmd, "hash_clear")) {
			hash_clear(look_for_hash(arg[0]), look_for_hash_action_func(arg[1]));
        }
		else if (!strcmp(cmd, "hash_delete")) {
			struct hash_item * i = (struct hash_item *)malloc(sizeof(struct hash_item));
            i->data = arg[1];
			hash_delete(look_for_hash(arg[0]), &(i->elem));
		}
		else if (!strcmp(cmd, "hash_empty")) {
			printf("%s\n", hash_empty(look_for_hash(arg[0])) ? "true" : "false");
        }
		else if (!strcmp(cmd, "hash_find")) {
			struct hash_item * i = (struct hash_item *)malloc(sizeof(struct hash_item));
            i->data = arg[1];
			hash_find(look_for_hash(arg[0]), &(i->elem));
        }
		else if (!strcmp(cmd, "hash_insert")) {
			struct hash_item * i = (struct hash_item *)malloc(sizeof(struct hash_item));
            i->data = arg[1];
			hash_insert(look_for_hash(arg[0]), &(i->elem));
		}
		else if (!strcmp(cmd, "hash_replace")) {
			struct hash_item * i = (struct hash_item *)malloc(sizeof(struct hash_item));
			i->data = arg[1];
			hash_replace(look_for_hash(arg[0]), &(i->elem));
        }
		else if (!strcmp(cmd, "hash_size")) {
			printf("%zu\n", hash_size(look_for_hash(arg[0])));
        }
		else if (!strcmp(cmd, "list_back")) {
			printf("%d\n", list_entry(list_back(look_for_list(arg[0])), struct list_item, elem)->data);
        }
		else if (!strcmp(cmd, "list_empty")) {
			printf("%s\n", list_empty(look_for_hash(arg[0])) ? "true" : "false");
        }
		else if (!strcmp(cmd, "list_front")) {
			printf("%d\n", list_entry(list_front(look_for_list(arg[0])), struct list_item, elem)->data);
		}
		else if (!strcmp(cmd, "list_insert")) {
			struct list_elem * e = list_begin(look_for_list(arg[0]));
			for (int i = 0; i < atoi(arg[1]); i++) e = list_next(e);
			struct list_item * i = (struct list_item *)malloc(sizeof(struct list_item));
			i->data = atoi(arg[2]);
			list_insert(e, &(i->elem));
        }
		else if (!strcmp(cmd, "list_insert_ordered")) {
			struct list_item * i = (struct list_item *)malloc(sizeof(struct list_item));
            i->data = atoi(arg[1]);
			list_insert_ordered(look_for_list(arg[0]), &(i->elem), list_less, NULL); //TODO
		}
		else if (!strcmp(cmd, "list_max")) {
			printf("%d\n", list_entry(list_max(look_for_list(arg[0]), list_less, NULL), struct list_item, elem)->data);
        }
		else if (!strcmp(cmd, "list_min")) {
			printf("%d\n", list_entry(list_min(look_for_list(arg[0]), list_less, NULL), struct list_item, elem)->da    ta);
        }
		else if (!strcmp(cmd, "list_pop_back")) {
			list_pop_back(look_for_list(arg[0]));
		}
		else if (!strcmp(cmd, "list_pop_front")) {
			list_pop_front(look_for_list(arg[0]));
		}
		else if (!strcmp(cmd, "list_push_back")) {
			struct list_item * i = (struct list_item *)malloc(sizeof(struct list_item));
            i->data = atoi(arg[1]);
			list_push_back(look_for_list(arg[0]), &(i->elem));
        }
		else if (!strcmp(cmd, "list_push_front")) {
			struct list_item * i = (struct list_item *)malloc(sizeof(struct list_item));	
			i->data = atoi(arg[1]);
			list_push_front(look_for_list(arg[0]), &(i->elem));
		}
		else if (!strcmp(cmd, "list_remove")) {
			struct list_elem e = list_begin(look_for_list(arg[0]));
			for (int i = 0; i < atoi(arg[1]); i++) e = list_next(e);
			list_remove(e);
		}
		else if (!strcmp(cmd, "list_reverse")) {
			list_reverse(look_for_list(arg[0]));
        }
		else if (!strcmp(cmd, "list_shuffle")) {
			//TODO
        }
		else if (!strcmp(cmd, "list_size")) {
			printf("%zu\n", list_size(look_for_list(arg[0])));	
		}
		else if (!strcmp(cmd, "list_sort")) {
			list_sort(look_for_list(arg[0]), list_less, NULL);
        }
		else if (!strcmp(cmd, "list_splice")) {
			struct list_elem before = list_begin(look_for_list(arg[0]));
			struct list_elem first = list_begin(look_for_list(arg[2]));
			struct list_elem last = list_begin(look_for_list(arg[2]));
            for (int i = 0; i < atoi(arg[1]); i++) before = list_next(before);
			for (int i = 0; i < atoi(arg[3]); i++) first = list_next(first);
			for (int i = 0; i < atoi(arg[4]); i++) last = list_next(last);
			list_splice(before, first, last);
        }
		else if (!strcmp(cmd, "list_swap")) {
			//TODO
        }
		else if (!strcmp(cmd, "list_unique")) {
			list_unique(look_for_list(arg[0]), look_for_list(arg[1]), list_less, NULL);
		}*/
		else if (!strcmp(cmd, "quit")) {
			break;
		}
		else continue;
	}
}

