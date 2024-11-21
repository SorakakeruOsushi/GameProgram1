#include "GoalText.h"
#include "../Library/time.h"


GoalText::GoalText()
{
	score = 0;

	timer = 0.0f;
}

GoalText::~GoalText()
{
}


void GoalText::Update()
{
	score = 100;
	timer += Time::DeltaTime();

	if (timer>=2.0f)
	{
		if (CheckHitKey(KEY_INPUT_SPACE)) {
			SceneManager::ChangeScene("TitleScene");
		}
	}
	
}

void GoalText::Draw()
{
	int size = GetFontSize();

	SetFontSize(50);
	DrawString(200, 200, "GOAL", GetColor(170, 255, 0));
	
	if (timer >= 1.0f)
	{
		SetFontSize(30);
		DrawFormatString(200, 300, GetColor(170, 255, 0), "SCORE...%5d", score);
	}

	if (timer >= 2.0f)
	{
		SetFontSize(30);
		DrawString(200, 500, "PUSH SPACE KEY", GetColor(170, 255, 0));
	}
	
	SetFontSize(size);
}
