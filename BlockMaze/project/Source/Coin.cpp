#pragma once
#include "Coin.h"
#include "config.h"
#include "Stage.h"
#include "Player.h"


Coin::Coin()
{
	//コンストラクターで絵のロード
	hImage = LoadGraph("data/Image/parts.png");
	got = false;
}

Coin::~Coin()
{

}

void Coin::Update()
{
	if (got)
	{
		position.y += v;
		v += 0.3f;
		counter -= 1;
		if (counter == 0)
		{
			DestroyMe();
		}
		return;
	}

	//当たり判定
	Player* p = FindGameObject<Player>();
	VECTOR2 playerPos = p->position;
	if (CircleHit(playerPos, position, 40))
	{
		got = true;
		counter = 50;
		v = -10.0f;
	}
}

void Coin::Draw()
{
	Stage* s = FindGameObject<Stage>();
	//絵の表示
	DrawRectGraph(position.x-s->scroll, position.y, 120, 0, 40, 40, hImage, TRUE);
}
