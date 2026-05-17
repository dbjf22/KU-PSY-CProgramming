#include "header.h"
#include "settings.h"

int main(void) {
	int isEasyCleared = 0, isNormalCleared = 0, isHardCleared = 0;
	srand((unsigned)time(NULL));

	// 게임 시작 여부 선택
	printBanner(0, 0);
	printBox(0, 7, "시작", 0);
	printBox(0, 10, "나가기", 0);

	struct coord coords[2] = {{3, 8}, {3, 11}};
	int select = selectValue(coords, 2);

	if (!select) {
		clear();

		// TODO: 스토리 확정나면 여기에 컷씬 넣어야함

		while (1) {
			if (isEasyCleared && isNormalCleared && isHardCleared) {
				break;
			}
			
			clear();

			// 난이도 선택
			printBanner(0, 0);
			printBox(0, 7, "쉬움", isEasyCleared);
			printBox(0, 10, "보통", isNormalCleared);
			printBox(0, 13, "어려움", isHardCleared);

			struct coord coords[3] = { {3, -1}, {3, -1}, {3, -1} };
			int length = 3;

			if (!isEasyCleared) {
				coords[0].x = 3;
				coords[0].y = 8;
			}

			if (!isNormalCleared) {
				coords[1].x = 3;
				coords[1].y = 11;
			}

			if (!isHardCleared) {
				coords[2].x = 3;
				coords[2].y = 14;
			}
			
			for (int i = 0; i < 3; i++) {
				if (coords[i].y >= 0) {
					goToXY(coords[i].x, coords[i].y);
					break;
				}
			}

			int select = selectValue(coords, length);

			switch (select) {
			case 0: {
				clear();
				int coin = 10;
				struct flag flags[FLAG_COUNT_EASY];
				int x = DEFAULT_PLAYER_X_EASY, y = DEFAULT_PLAYER_Y_EASY;
				struct coord playerPos = { x, y };
				initFlags(WIDTH_EASY, HEIGHT_EASY, flags, FLAG_COUNT_EASY, playerPos);
				placeStage(WIDTH_EASY, HEIGHT_EASY);
				placeFlag(flags, FLAG_COUNT_EASY);
				placePlayer(playerPos);
				while (1) {
					struct coord prevPos = playerPos;

					int game = movePlayer(&playerPos.x, &playerPos.y, flags, FLAG_COUNT_EASY, WIDTH_EASY, HEIGHT_EASY).item_id;

					if (game >= 0) {
						gameStarter(game);
						clear();
						placeStage(WIDTH_EASY, HEIGHT_EASY);
						placeFlag(flags, FLAG_COUNT_EASY);
						placePlayer(playerPos);
					}
					
				}
				isEasyCleared = 1;
				break;
			}
			case 1: {
				isNormalCleared = 1;
				break;
			}
			case 2: {
				isHardCleared = 1;
				break;
			}
			}
		}
		clear();

		// TODO: 여기에 끝 컷씬 넣어야 함.

	}

	clear();
	printBanner(0, 0);
	printf("\n\nGame Cleared!");

	return 0;
}
