#include "Waitress.h"

bool Waitress::HandleMessage(const Telegram& msg)
{
	return m_pStateMachine->HandleMessage(msg);
}


void Waitress::Update()
{
	SetTextColor(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);

	m_pStateMachine->Update();
}



void Waitress::AddToGoldTips(int val)
{
	m_iGoldTips += val;

    if (m_iGoldTips < 0){
        m_iGoldTips = 0;
    }
}

bool Waitress::isSweaty()const
{
	if (m_iSweat >= SweatLevel) { return true; }

	return false;
}

bool Waitress::isBored()const
{
	if (m_iBoredom > BoredomLevel) { return true; }

	return false;
}
