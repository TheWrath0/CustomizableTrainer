/*
* Customizable Trainer
* Copyright (C) 2020  Gu�mundur �li
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*/

#include "pch.h"
#include "SettingsOptionsToSaveSub.h"
#include "SettingsAddOptionToSaveSub.h"
#include "MenuSettings.h"
#include "Controls.h"
#include "JsonData.h"

SettingsOptionsToSaveSub::SettingsOptionsToSaveSub(MenuController* menuController) : Submenu(menuController)
{
}

#pragma region Draw

void SettingsOptionsToSaveSub::Draw()
{
	Submenu::Draw();

	DrawTitle("Options to save");
	DrawAction("Add >", [this] {
		auto addOptionToSaveSub = new SettingsAddOptionToSaveSub(menuController);
		menuController->AddSubmenuToStack(addOptionToSaveSub);
	});

	for (int i = 0; i < Settings::General::optionsToSave.size(); i++) {
		auto optionToSave = Settings::General::optionsToSave[i];
		DrawAction(optionToSave.key + " >", [this, i] {
			auto addOptionToSaveSub = new SettingsAddOptionToSaveSub(menuController, i);
			menuController->AddSubmenuToStack(addOptionToSaveSub);
		});
	}
}

#pragma endregion

#pragma region Controls

void SettingsOptionsToSaveSub::RespondToControls()
{
	Submenu::RespondToControls();

	if (Controls::IsMenuControlPressed(MenuControl::MenuEditModeDeleteOption)) {
		if (selection == 0) return;
		if (Settings::General::playUiSounds) Game::PlaySoundFrontend("HUD_PLAYER_MENU", "SELECT");
		
		Settings::General::optionsToSave.erase(Settings::General::optionsToSave.begin() + (selection - 1));
		JSONData::SaveOptionStates();

		if (selection == OptionCount() - 1) selection -= 1;
	}
}

#pragma endregion
