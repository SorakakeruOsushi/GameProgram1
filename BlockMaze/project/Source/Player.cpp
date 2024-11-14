#include "Player.h"
#include "config.h"
#include "Stage.h"

const float Gravity = 0.3f;
const float JumpHeight = 40 * 2;
const float V0 = -sqrtf(2.0f * Gravity * JumpHeight);

Player::Player()
{
	hImage = LoadGraph("data/image/chara.png");
	position.x = 0;
	position.y = 0;
	speed.x = 0.0;
	speed.y = 0.0;
	goaled = false;
}

Player::~Player()
{
}

void Player::Update()
{
	Stage* s = FindGameObject<Stage>();


	if (goaled) {
		return;
	}
	if (CheckHitKey(KEY_INPUT_D)) {
		position.x += 2.0;
		//‰E‚É•Ç‚ª‚ ‚é‚©’²‚×‚é
		int push = s->IsWallRight(position + VECTOR2(39, 0));
		position.x -= push;
		push = s->IsWallRight(position + VECTOR2(39, 39));
		position.x -= push;
	}
	else if (CheckHitKey(KEY_INPUT_A)) {
		position.x -= 2.0;
		//¶‚É•Ç‚ª‚ ‚é‚©’²‚×‚é
		int push = s->IsWallLeft(position + VECTOR2(0, 0));
		position.x += push;
		push = s->IsWallLeft(position + VECTOR2(0, 39));
		position.x += push;
	}
	else {
		speed.x = 0.0f;
	}
	position.x += speed.x;
	if (position.x < 0) {
		position.x = 0;
	}


	if (CheckHitKey(KEY_INPUT_W)) {
		position.y -= 2.0;
		//ã‚É•Ç‚ª‚ ‚é‚©’²‚×‚é
		int push = s->IsWallUp(position + VECTOR2(0, 0));
		position.y += push;
		push = s->IsWallUp(position + VECTOR2(39, 0));
		position.y += push;
	}
	else if (CheckHitKey(KEY_INPUT_S)) {
		position.y += 2.0;
		//‰º‚É•Ç‚ª‚ ‚é‚©’²‚×‚é
		int push = s->IsWallDown(position + VECTOR2(0, 39));
		position.y -= push;
		push = s->IsWallDown(position + VECTOR2(39, 39));
		position.y -= push;

	}
	else {
		speed.y = 0.0f;
	}
	position.y += speed.y;
	if (position.y < 0) {
		position.y = 0;
	}
	if (position.y > SCREEN_HEIGHT - 64) {
		position.y = SCREEN_HEIGHT - 64;
	}


	if (CheckHitKey(KEY_INPUT_SPACE)) {
		if (prevJumpKey == false)
		{
			if (onGround == true)
			{
				//ƒWƒƒƒ“ƒv‚·‚é
				velocity = V0;
			}
			prevJumpKey = true;
		}
	}
	else
	{
		prevJumpKey = false;
	}

	position.y += velocity;
	velocity += Gravity;
	onGround = false;

	//‰º‚É•Ç‚ª‚ ‚é‚©’²‚×‚é
	int push = s->IsWallDown(position + VECTOR2(0, 40));
	if (push > 0)
	{
		velocity = 0.0f;
		position.y -= push - 1;
		onGround = true;
	}

	push = s->IsWallDown(position + VECTOR2(39, 40));
	if (push > 0)
	{
		velocity = 0.0f;
		position.y -= push - 1;
		onGround = true;
	}
	else
	{
		int push = s->IsWallUp(position + VECTOR2(0, 0));
		if (push > 0)
		{
			velocity = 0.0f;
			position.x -= push;
		}
		push = s->IsWallUp(position + VECTOR2(39, 0));
		if (push > 0)
		{
			velocity = 0.0f;
			position.x -= push;
		}
	}
	if (position.x - s->scroll > 400)
	{
		s->scroll = position.x - 400;
	}

	if (position.x - s->scroll < 0)
	{
		s->scroll = position.x + 0;
	}


	if (s->IsGoal(position + VECTOR2(20,20)))
	{
		goaled = true;
	}

}

void Player::Draw()
{
	Stage* s = FindGameObject<Stage>();

	DrawRectGraph(position.x - s->scroll, position.y, 0, 0, 40, 40, hImage, TRUE);
}
