#include <sc2api/sc2_api.h>
#include "MyBot.h"

#define DllImport   __declspec( dllimport )  
void DllImport *CreateNewAgent();
int DllImport GetAgentRace();

int main(int argc, char* argv[])
{
	sc2::Coordinator coordinator;
	if (!coordinator.LoadSettings(argc, argv)) {
		return 1;
	}

	// Add the custom bot, it will control the players.
	sc2::Agent* bot = static_cast<sc2::Agent*>(CreateNewAgent());
	sc2::Race race = static_cast<sc2::Race>(GetAgentRace());

	coordinator.SetParticipants({
		CreateParticipant(race, bot),
		CreateComputer(sc2::Race::Terran, sc2::Difficulty::VeryEasy)
	});

	// Start the game.
	coordinator.LaunchStarcraft();

	// Step forward the game simulation.

	//TODO:  Set this to the path of a map on your computer
	coordinator.StartGame("C:\\sc2api\\LadderServer\\Maps\\Ladder2017Season1\\BelShirVestigeLE.SC2Map");
	while (coordinator.Update()) {
		//game running
	}

	return 0;
}
