#pragma once
#include "Coin.h"
#include "config.h"
#include "Stage.h"
#include "Player.h"

Coin::Coin()
{
	//�R���X�g���N�^�[�ŊG�̃��[�h
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
		speed += 1.5;
		position.y -= speed;
		counter -= 1;
		if (counter == 0)
		{
			DestroyMe();
		}
		return;
	}

	//�����蔻��
	Player* p = FindGameObject<Player>();
	VECTOR2 playerPos = p->position;
	if (CircleHit(playerPos, position, 40))
	{
		got = true;
		counter = 10;
	}
}

void Coin::Draw()
{
	//�G�̕\��
	DrawRectGraph(position.x, position.y, 120, 0, 40, 40, hImage, TRUE);
}
