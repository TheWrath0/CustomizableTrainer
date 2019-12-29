#include "pch.h"
#include "SettingsGeneralSub.h"
#include "MenuSettings.h"
#include "JsonDataManager.h"

SettingsGeneralSub::SettingsGeneralSub(MenuController* menuController) : FixedSubmenu(menuController)
{
}

// MARK: Draw

void SettingsGeneralSub::Draw()
{
	FixedSubmenu::Draw();

	DrawTitle("General");
	DrawToggle("UI sounds", MenuSettings::playUiSounds, [] {
		MenuSettings::playUiSounds = !MenuSettings::playUiSounds;
		JSONDataManager jsonDataManager;
		jsonDataManager.SaveMenuSettings(true);
	});
}
