#pragma once

struct PlayerComponent
{
	PlayerComponent() = default;
	PlayerComponent(const PlayerComponent&) = default;

private:
	void* a;
};