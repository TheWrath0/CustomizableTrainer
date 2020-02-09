/*
* Customizable Trainer
* Copyright (C) 2020  Gu�mundur �li
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*/

#pragma once

#include "pch.h"
#include "MenuController.h"

class MenuController;

class Submenu {
public:
	Submenu(MenuController *menuController);

	virtual int OptionCount();

	bool IsOutOfBounds(int index);
	bool IsOptionSelected(int index);

	void Tick();

	void DeleteWhenPossible();

	int selection;
	int scrollPosition;
protected:
	virtual void Draw();

	void DrawTitle(string text);
	virtual void DrawMenuBase();
	void DrawOptionBase(string text, bool selected);
	void DrawLabel(string text);
	void DrawSub(string text, string subKey, bool isEnabled = true);
	void DrawAction(string text, std::function<void()> onPress);
	void DrawToggle(string text, bool isToggled, std::function<void()> onPress);
	void DrawNumber(string text, string numberToDisplay, std::function<void()> onPress, std::function<void(bool direction)> onAdjust);
	void DrawTextList(string text, string valueToDisplay, std::function<void(bool direction)> onAdjust);
	void DrawTextAction(string text, string value, std::function<void()> onPress);

	virtual void SubWillDraw();
	virtual void SubDidDraw();
	virtual void OptionDidDraw();
	virtual void SelectionDidChange(int to, int from);

	virtual void RespondToControls();

	string OptionTypeToString(MenuOptionType type);
	float CurrentOptionPosY();

	int drawIndex;
	int optionAddIndex;
	int autoOptionCount;
	int holdingAdjustUpTimer;
	int holdingAdjustUpTimerStart;
	bool isHoldingAdjustUp;
	bool isSubDeletionScheduled;
	int holdingAdjustDownTimer;
	int holdingAdjustDownTimerStart;
	bool isHoldingAdjustDown;
	MenuController* menuController;
};

