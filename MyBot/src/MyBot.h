#pragma once
#define DllExport   __declspec( dllexport )  
#include <sc2api\sc2_api.h>

class MyBot : public sc2::Agent 
{
public:
	MyBot();
	//! In non realtime games this function gets called after each step as indicated by step size.
	//! In realtime this function gets called as often as possible after request/responses are received from the game gathering observation state.
	virtual void OnStep();
};

//Functions expected by LadderManager.exe to load your bot
void DllExport *CreateNewAgent();
int DllExport GetAgentRace();
const char DllExport *GetAgentName();
