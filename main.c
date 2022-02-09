#include "main.h"

int main() {
	char input[81];
	char *cmd;
	
	while(1) {
		fgets(input, sizeof(input), stdin);
		cmd = strtok(input, " ");
		
		if (!strcmp(cmd, "bitmap_all")) {
		}
		else if (!strcmp(cmd, "bitmap_any")) {
        }
		else if (!strcmp(cmd, "bitmap_contains")) {
        }
		else if (!strcmp(cmd, "bitmap_count")) {
        }
		else if (!strcmp(cmd, "bitmap_dump")) {
        }
		else if (!strcmp(cmd, "bitmap_expand")) {
        }
		else if (!strcmp(cmd, "bitmap_flip")) {
        }
		else if (!strcmp(cmd, "bitmap_mark")) {
        }
		else if (!strcmp(cmd, "bitmap_none")) {
        }
		else if (!strcmp(cmd, "bitmap_reset")) {
        }
		else if (!strcmp(cmd, "bitmap_scan")) {
        }
		else if (!strcmp(cmd, "bitmap_scan_and_flip")) {
        }
		else if (!strcmp(cmd, "bitmap_set")) {
        }
		else if (!strcmp(cmd, "bitmap_set_all")) {
        }
		else if (!strcmp(cmd, "bitmap_set_multiple")) {
        }
		else if (!strcmp(cmd, "bitmap_size")) {
        }
		else if (!strcmp(cmd, "bitmap_test")) {
        }
		else if (!strcmp(cmd, "create")) {
        }
		else if (!strcmp(cmd, "delete")) {
        }
		else if (!strcmp(cmd, "dumpdata")) {
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
        }
	}
}

