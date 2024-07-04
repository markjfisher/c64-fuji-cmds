#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "fujinet-fuji.h"

void via_cmdline(int argc, char *argv[]) {
	printf("via cmdline\n");
}

void via_prompt() {
	printf("via prompt\n");
}

void main(int argc, char *argv[]) {
	if (argc > 1) {
		via_cmdline(argc, argv);
	} else {
		via_prompt();
	}
}