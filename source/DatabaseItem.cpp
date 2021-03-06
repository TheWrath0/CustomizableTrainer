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
#include "DatabaseItem.h"

namespace Spawner {

#pragma region Base database item

	DatabaseItem::DatabaseItem(EntityId entityId, std::string model)
		: entityId(entityId), model(model), entity(entityId)
	{}

	// Setters

	void DatabaseItem::SetInvincible(bool enabled)
	{
		isInvincible = enabled;
		entity.SetGravityEnabled(enabled);
	}

	void DatabaseItem::SetVisible(bool visible)
	{
		isVisible = visible;
		entity.SetVisible(visible);
	}

	void DatabaseItem::SetDynamic(bool dynamic)
	{
		isDynamic = dynamic;
		entity.SetDynamic(dynamic);
	}

	void DatabaseItem::SetCollisionEnabled(bool enabled)
	{
		isCollisionEnabled = enabled;
		entity.SetCollisionEnabled(enabled);
	}

	void DatabaseItem::SetFrozen(bool frozen)
	{
		isFrozen = frozen;
		entity.SetFrozen(frozen);
	}

	void DatabaseItem::SetGravityEnabled(bool gravityEnabled)
	{
		isGravityEnabled = gravityEnabled;
		entity.SetGravityEnabled(true);
	}

	// Booleans

	bool DatabaseItem::IsInvincible()
	{
		return isInvincible;
	}

	bool DatabaseItem::IsVisible()
	{
		return isVisible;
	}

	bool DatabaseItem::IsDynamic()
	{
		return isDynamic;
	}

	bool DatabaseItem::IsCollisionEnabled()
	{
		return isCollisionEnabled;
	}

	bool DatabaseItem::IsFrozen()
	{
		return isFrozen;
	}

	bool DatabaseItem::IsGravityEnabled()
	{
		return isGravityEnabled;
	}

#pragma endregion

#pragma region Ped database item

	// Setters

	void PedDatabaseItem::SetBodyguard(bool toggle)
	{
		isBodyguard = toggle;
		if (toggle)
			ped.SetAsGroupMember(Player().Group());
		else
			ped.RemoveFromGroup();
	}

	// Booleans

	bool PedDatabaseItem::IsBodyguard()
	{
		return isBodyguard;
	}

#pragma endregion

#pragma region Object database item

	ObjectDatabaseItem::ObjectDatabaseItem(ObjectId object, std::string model)
		: DatabaseItem(object, model)
	{
		isDynamic = false;
	}

#pragma endregion

}