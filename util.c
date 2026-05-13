#include "header.h"
#include "settings.h"

int random_range(int min, int max) {
	return rand() % (max - min) + min;
}

void clear() {
	system("cls");
}

int isNotMove(int x, int y, struct flag* flags) {
	if (x == WIDTH - 1 || x == 0 || y == HEIGHT - 1 || y == 0) {
		return 1;
	}
	for (int i = 0; i < FLAG_COUNT; i++) {
		if (x == flags[i].x && y == flags[i].y) {
			return 1;
		}
	}
	return 0;
}