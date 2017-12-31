#include "CApp.h"

void CApp::OnCleanup(){

    OnCleanupStage();

	CArea::AreaControl.OnCleanup();
	for(unsigned int i = 0;i < CEntity::ObjectList.size();i++) {
		if(!CEntity::ObjectList[i]) continue;
		CEntity::ObjectList[i]->OnCleanup();
		//delete CEntity::ObjectList[i]; // Comentat perque petaba al tancar
		CEntity::ObjectList.clear();
	}
	CSoundBank::SoundControl.OnCleanup();
	CMusicBank::MusicControl.OnCleanup();
	M.OnCleanup();
	Op.OnCleanup();
	Mix_CloseAudio();

    SDL_FreeSurface(Surf_Display);
    SDL_Quit();
}

void CApp::OnCleanupStage(){
	for(unsigned int i = 0;i < CEntity::ObjectList.size();i++) {
		if(!CEntity::ObjectList[i]) continue;
		if(CEntity::ObjectList[i]->Type != ENTITY_TYPE_PLAYER_NORMAL){
		CEntity::ObjectList[i]->OnCleanup();
		//delete CEntity::ObjectList[i]; // Comentat perque petaba al tancar
		CEntity::ObjectList.clear();
		CEntity::ObjectList.push_back(&Player1);
		}
	}
}
