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
#include "SpawnerManageEntity.h"
#include "WeaponSelection.h"

SpawnerManageEntity::SpawnerManageEntity(MenuController* menuController, EntityType type, std::shared_ptr<Spawner::DatabaseItem> dbItem)
	: Submenu(menuController), type(type), dbItem(dbItem), entity(dbItem->entityId)
{}

#pragma region Draw

void SpawnerManageEntity::Draw()
{
	Submenu::Draw();

	DrawTitle(dbItem->model);
	DrawToggle("Visible", dbItem->IsVisible(), [this] {
		bool toggledValue = !dbItem->IsVisible();
		dbItem->SetVisible(toggledValue);
	});
	DrawToggle("Invincible", dbItem->IsInvincible(), [this] {
		bool toggledValue = !dbItem->IsInvincible();
		dbItem->SetInvincible(toggledValue);
	});

	if (IsPed()) {
		auto pedDbItem = DbItemForPed();

		DrawToggle("Bodyguard", pedDbItem->IsBodyguard(), [this, pedDbItem] {
			bool toggledValue = !pedDbItem->IsBodyguard();
			pedDbItem->SetBodyguard(toggledValue);
		});

		DrawSubAction("Give weapon", [this, pedDbItem] {
			auto weaponSelection = new WeaponSelectionSub(menuController, pedDbItem->ped);
			menuController->AddSubmenuToStack(weaponSelection);
		});
	}

	DrawToggle("Frozen", dbItem->IsFrozen(), [this] {
		bool toggledValue = !dbItem->IsFrozen();
		dbItem->SetFrozen(toggledValue);
	});
	DrawToggle("Collision", dbItem->IsCollisionEnabled(), [this] {
		bool toggledValue = !dbItem->IsCollisionEnabled();
		dbItem->SetCollisionEnabled(toggledValue);
	});
	DrawToggle("Gravity", dbItem->IsGravityEnabled(), [this] {
		bool toggledValue = !dbItem->IsGravityEnabled();
		dbItem->SetGravityEnabled(toggledValue);
	});
	DrawAction("Delete", [this] {
		Spawner::Spawner::database.RemoveAndDelete(dbItem, type);
		menuController->GoToLastSub();
	});
}

#pragma endregion

#pragma region Booleans

bool SpawnerManageEntity::IsPed()
{
	return type == EntityType::Ped;
}

bool SpawnerManageEntity::IsVehicle()
{
	return type == EntityType::Vehicle;
}

bool SpawnerManageEntity::IsObject()
{
	return type == EntityType::Object;
}

#pragma endregion

#pragma region Getters

std::shared_ptr<Spawner::PedDatabaseItem> SpawnerManageEntity::DbItemForPed()
{
	return std::static_pointer_cast<Spawner::PedDatabaseItem>(dbItem);
}

std::shared_ptr<Spawner::VehicleDatabaseItem> SpawnerManageEntity::DbItemForVehicle()
{
	return std::static_pointer_cast<Spawner::VehicleDatabaseItem>(dbItem);
}

std::shared_ptr<Spawner::ObjectDatabaseItem> SpawnerManageEntity::DbItemForObject()
{
	return std::static_pointer_cast<Spawner::ObjectDatabaseItem>(dbItem);
}

#pragma endregion