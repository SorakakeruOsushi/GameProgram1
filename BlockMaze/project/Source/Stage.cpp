#include "Stage.h"
#include "Player.h"
#include "Coin.h"

const int CHIP_SIZE = 40;

#include "Stage1.h"

Stage::Stage()
{
	hImage = LoadGraph("data/image/parts.png");
	for (int j = 0; j < HEIGHT; j++)//c
	{
		for (int i = 0; i < WIDTH; i++)//‰¡
		{
			if (map[j][i] == 9) {
				Player* p = Instantiate<Player>();
				p->position.x = i * CHIP_SIZE + 100;
				p->position.y = j * CHIP_SIZE + 100;
			}
	
			if (map[j][i] == 2) {
				Coin* c = Instantiate<Coin>();
				c->position.x = i * CHIP_SIZE + 100;
				c->position.y = j * CHIP_SIZE + 100;
			}
		}
	}
	scroll = 0;
}

Stage::~Stage()
{
}

void Stage::Draw()
{
	for (int j = 0; j < HEIGHT; j++)//c
	{
		int y = j * CHIP_SIZE + 100;
		for (int i = 0; i < WIDTH; i++)//‰¡
		{
			int x = i * CHIP_SIZE + 100;
			if (map[j][i] == 1) {
				DrawRectGraph(x-scroll, y, 0, 40, CHIP_SIZE, CHIP_SIZE, hImage, TRUE);
			}
			if (map[j][i] == 8) {
				DrawRectGraph(x-scroll, y, 160, 0, CHIP_SIZE, CHIP_SIZE, hImage, TRUE);
			}
		}
	}

	}

int Stage::IsWallRight(VECTOR2 pos)
{
	int i = (pos.x - 100) / CHIP_SIZE;
	int j = (pos.y - 100) / CHIP_SIZE;
	if (map[j][i]==1)
	{
		int push = ((int)pos.x - 100) % CHIP_SIZE + 1;
		return push;
	}
	return 0;
}

int Stage::IsWallDown(VECTOR2 pos)
{
	int i = (pos.x - 100) / CHIP_SIZE;
	int j = (pos.y - 100) / CHIP_SIZE;
	if (map[j][i] == 1)
	{
		int push = ((int)pos.y - 100) % CHIP_SIZE + 1;
		return push;
	}
	return 0;
}

int Stage::IsWallLeft(VECTOR2 pos)
{

	int i = (pos.x - 100) / CHIP_SIZE;
	int j = (pos.y - 100) / CHIP_SIZE;
	if (map[j][i] == 1)
	{
		int push = 40-((int)pos.x - 100) % CHIP_SIZE;
		return push;
	}
	return 0;
}

int Stage::IsWallUp(VECTOR2 pos)
{
	int i = (pos.x - 100) / CHIP_SIZE;
	int j = (pos.y - 100) / CHIP_SIZE;
	if (map[j][i] == 1)
	{
		int push = 40-((int)pos.y - 100) % CHIP_SIZE;
		return push;
	}
	return 0;
}

bool Stage::IsGoal(VECTOR2 pos)
{
	int i = (pos.x - 100) / CHIP_SIZE;
	int j = (pos.y - 100) / CHIP_SIZE;
	if (map[j][i] == 8) {
		return true;
	}
	return false;
}
	
