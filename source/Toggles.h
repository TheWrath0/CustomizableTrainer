#pragma once
#include "pch.h"

namespace Toggles {
	// MARK: Toggles
	inline bool
		playerInvincible = false,
		playerVisible = true,
		playerSuperRun = false,
		playerSuperJump = false,
		playerUnlStamina = false,
		playerUnlSpecialAbility = false,
		playerNeverWanted = false,
		playerNoRagdoll = false,
		playerEveryoneIgnore = false,
		forceFirstPersonOnFoot = false,
		spawnedPedInvincible = false,
		spawnedPedBodyguard = false,
		allSpawnedPedsInvincible = false,
		allSpawnedPedsBodyguard = false,
		horseInvincible = false,
		horseVisible = true,
		horseSuperRun = false,
		horseSuperJump = false,
		horseUnlimitedStamina = false,
		horseFlyMode = false,
		horseEngineTest = false,
		horseNoRagdoll = false,
		forceFirstPersonOnHorse = false,
		spawnInsideVehicle = false,
		vehicleInvincible = false,
		vehicleVisible = true,
		vehicleCannons = false,
		vehicleBindBoost = false,
		boatFlyMode = false,
		forceFirstPersonInVehicle = false,
		pauseClock = false,
		systemClockSync = false,
		freezeWeather = false,
		weaponExtraDamage = false,
		weaponExplosiveAmmo = false,
		weaponLightningGun = false,
		weaponFireAmmo = false,
		playerExplosiveMelee = false,
		weaponInfiniteAmmo = false,
		weaponInfiniteAmmoInClip = false,
		disableInvisibleSniper = false,
		hideHud = false;

	// MARK: Toggle actions
	void OnPlayerInvincibleToggle(bool value);
	void OnPlayerVisibleToggle(bool value);
	void OnPlayerNeverWantedToggle(bool value);
	void OnPlayerNoRagdollToggle(bool value);
	void OnPlayerEveryoneIgnoreToggle(bool value);
	void OnHorseInvincibleToggle(bool value);
	void OnHorseVisibleToggle(bool value);
	void OnHorseNoRagdollToggle(bool value);
	void OnHorseSuperJumpToggle(bool value);
	void OnSpawnedPedInvincibleToggle(bool value);
	void OnSpanwedPedBodyguardToggle(bool value);
	void OnAllSpawnedPedsInvincibleToggle(bool value);
	void OnAllSpanwedPedsBodyguardToggle(bool value);
	void OnVehicleInvincibleToggle(bool value);
	void OnVehicleVisibleToggle(bool value);
	void OnBoatFlyModeToggle(bool value);
	void OnPauseClockToggle(bool value);
	void OnFreezeWeatherToggle(bool value);
	void OnWeaponExtraDamageToggle(bool value);
	void OnDisableInvisibleSniperToggle(bool value);
}

