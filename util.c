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

int selectValue(struct coord* coords, int length) {
	int select = 0;
	while (1) {
		goToXY(coords[select].x, coords[select].y);
		printf("x\b");
		int ch = _getch();
		if (ch == 13) {
			goToXY(0, coords[length - 1].y + 2);
			return select;
		}
		if (ch == 224) {
			ch = _getch();
			switch (ch) {
			case 72:
				if (select > 0) {
					printf(" ");
					select--;
				}
				break;

			case 80:
				if (select < length - 1) {
					printf(" ");
					select++;
				}
				break;
			}
		}
	}
}