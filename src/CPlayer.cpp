//=============================================================================
#include "CPlayer.h"

//=============================================================================
CPlayer::CPlayer() {
	TickLastLife = 0;

}

//=============================================================================
bool CPlayer::OnLoad(char* File, int Width, int Height, int MaxFrames) {
    if(CEntity::OnLoad(File, Width, Height, MaxFrames) == false) {
        return false;
    }

    return true;
}

//-----------------------------------------------------------------------------
void CPlayer::OnLoop() {
	CEntity::OnLoop();
		
	for(int i = CEntity::ObjectList.size()-1; i>=0; i--){
		CEntity *Entity = CEntity::ObjectList[i]; 
		if(Entity){ 
			if(		Entity->Type == ENTITY_TYPE_MOB_NORMAL || 
					Entity->Type == ENTITY_TYPE_MOB_NORMAL2){
				if( Entity->CollidesTop(this->X, this->Y, this->Width, this->Height)){
					Entity->Condemned = true;
					Entity = NULL;
				}
			}
		}
		if (Entity){
			if(Entity->Type == ENTITY_TYPE_RINGS_1 || Entity->Type == ENTITY_TYPE_RINGS_2){
				if(Entity->CollidesRing(this->X, this->Y, this->Width, this->Height)){
					if(Entity->Type == ENTITY_TYPE_RINGS_1) puntuacio += 10;
					if(Entity->Type == ENTITY_TYPE_RINGS_2) puntuacio += 1000;
					Entity->Condemned = true;
					Entity = NULL;
				}
			}
		}
	}	
}

//-----------------------------------------------------------------------------
void CPlayer::OnRender(SDL_Surface* Surf_Display) {
	CEntity::OnRender(Surf_Display);
	if(TickLastLife > SDL_GetTicks() - 1000){
		// Aqui tenim iun petit espai per posar una animació quant el pj xoca contra algun mob
	}
}

//------------------------------------------------------------------------------
void CPlayer::OnCleanup() {
	CEntity::OnCleanup();
}

//------------------------------------------------------------------------------
void CPlayer::OnAnimate() {
	if(SpeedX != 0) {
		Anim_Control.MaxFrames = 8;
	}else{
		Anim_Control.MaxFrames = 0;
	}

	CEntity::OnAnimate();
}

//------------------------------------------------------------------------------
bool CPlayer::OnCollision(CEntity* Entity) {

	if(Entity->Type != ENTITY_TYPE_PLATFORM && !Hit && CollidesTop(this->X, this->Y, this->Width, this->Height)){
			Life--;
			Hit = true;
	}
	TickLastLife = SDL_GetTicks();

    return true;
}

//=============================================================================
