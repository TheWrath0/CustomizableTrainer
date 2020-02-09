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

class Vehicle
{
public:
	Vehicle(VehicleId vehicleId);

#pragma region Booleans

	bool Exists();
	bool IsBoat();

#pragma endregion

#pragma region Getters

	VehicleId Id();
	Vector3 GetOffsetInWorldCoords(Vector3 offset);
	Hash Model();
	float Speed();
	void Dimensions(Vector3* dim1, Vector3* dim2);

#pragma endregion

#pragma region Setters

	void SetVehicleEngineOn(bool on);
	void SetEnginePowerMultiplier(float value);
	void SetForwardSpeed(float speed);
	void SetCoords(Vector3 coords);
	void SetCoordsNoOffset(Vector3 coords, bool xAxis = false, bool yAxis = false, bool zAxis = true);
	void SetVisible(bool value);
	void SetInvincible(bool value);

#pragma endregion

#pragma region Actions

	void SetAsMissionEntity();
	void ApplyForceRelative(Vector3 direction, Vector3 offset);
	void Repair();
	void Delete();

#pragma endregion

#pragma region Static methods

	static Vehicle Closest(Vector3 position, float radius = 100.0);
	static Vehicle Spawn(Hash model, Vector3 postion, float heading = 0.0f);

#pragma endregion

private:
	int vehicleId;
};

