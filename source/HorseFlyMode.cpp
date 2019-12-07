#include "pch.h"
#include "HorseFlyMode.h"
#include "ControlManager.h"
#include "Routine.h"

HorseFlyMode::HorseFlyMode()
{
	
	Routine::StartDrawBottomMessage("Horse fly mode activated");
}

void HorseFlyMode::Tick()
{
	horse = player.GetMount();
	HoverTest();
}

void HorseFlyMode::HoverTest()
{
	if (ControlManager::IsFunctionControlPressed(FunctionControl::HorseFlyUp)) {
		ENTITY::APPLY_FORCE_TO_ENTITY(horse.GetPedId(), 1, 0.0, 0.0, 1.0, /**/ -0.4, -0.8, 0.0, 1, 1, 1, 1, 0, 1);
		ENTITY::APPLY_FORCE_TO_ENTITY(horse.GetPedId(), 1, 0.0, 0.0, 1.0, /**/ 0.4, -0.8, 0.0, 1, 1, 1, 1, 0, 1);
		ENTITY::APPLY_FORCE_TO_ENTITY(horse.GetPedId(), 1, 0.0, 0.0, 1.0, /**/ -0.4, 0.8, 0.0, 1, 1, 1, 1, 0, 1);
		ENTITY::APPLY_FORCE_TO_ENTITY(horse.GetPedId(), 1, 0.0, 0.0, 1.0, /**/ 0.4, 0.8, 0.0, 1, 1, 1, 1, 0, 1);
	}
	if (ControlManager::IsFunctionControlPressed(FunctionControl::HorseFlyDown)) {
		ENTITY::APPLY_FORCE_TO_ENTITY(horse.GetPedId(), 1, 0.0, 0.0, 0.5, /**/ -0.4, -0.8, 0.0, 1, 1, 1, 1, 0, 1);
		ENTITY::APPLY_FORCE_TO_ENTITY(horse.GetPedId(), 1, 0.0, 0.0, 0.5, /**/ 0.4, -0.8, 0.0, 1, 1, 1, 1, 0, 1);
		ENTITY::APPLY_FORCE_TO_ENTITY(horse.GetPedId(), 1, 0.0, 0.0, 0.5, /**/ -0.4, 2.8, 0.0, 1, 1, 1, 1, 0, 1);
		ENTITY::APPLY_FORCE_TO_ENTITY(horse.GetPedId(), 1, 0.0, 0.0, 0.5, /**/ 0.4, 2.8, 0.0, 1, 1, 1, 1, 0, 1);
	}
	if (CONTROLS::IS_CONTROL_PRESSED(0, XboxControl::INPUT_FRONTEND_RB)) {
		ENTITY::SET_ENTITY_ROTATION(horse.GetPedId(), horse.GetHeading(), 0, 0, 0, 0);
		ENTITY::APPLY_FORCE_TO_ENTITY(horse.GetPedId(), 1, 0.0, 100.0f, 0.0, /**/ 0.0, 0.0, 0.0, 1, 1, 1, 1, 0, 1);
		// ENTITY::APPLY_FORCE_TO_ENTITY(horse.GetPedId(), 1, 0.0, 10.0, 0.0, /**/ 0.0, -0.8, 0.0, 1, 1, 1, 1, 0, 1);
	}
	player.SetCanRagdoll(false);
	horse.SetCanRagdoll(false);
}