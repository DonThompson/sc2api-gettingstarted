#include "MyBot.h"
#include <sc2api\sc2_api.h>
#include <sc2lib\sc2_lib.h>

void *CreateNewAgent()
{
	return (void *)new MyBot();
}

const char *GetAgentName()
{
	return "MyBot";
}

int GetAgentRace()
{
	return static_cast<int>(sc2::Race::Zerg);
}


//Bot constructor
MyBot::MyBot()
{

}

void MyBot::OnStep()
{
	//https://github.com/Blizzard/s2client-api/blob/master/examples/bot_simple.cc
	uint32_t game_loop = Observation()->GetGameLoop();

	if (game_loop % 100 == 0) {
		sc2::Units units = Observation()->GetUnits(sc2::Unit::Alliance::Self);
		for (auto& it_unit : units) {
			sc2::Point2D target = sc2::FindRandomLocation(Observation()->GetGameInfo());
			Actions()->UnitCommand(it_unit, sc2::ABILITY_ID::SMART, target);
		}
	}
}
