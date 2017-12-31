//=============================================================================
#include "CRings.h"

//=============================================================================
CRings::CRings() {

	Flags = ENTITY_FLAG_MAPONLY;

}

//=============================================================================
bool CRings::OnLoad(char* File, int Width, int Height, int MaxFrames) {
    if(CEntity::OnLoad(File, Width, Height, MaxFrames) == false) {
        return false;
    }

    return true;
}

//-----------------------------------------------------------------------------
void CRings::OnLoop() {
	CEntity::OnLoop();
	
		
}

//-----------------------------------------------------------------------------
void CRings::OnRender(SDL_Surface* Surf_Display) {
	CEntity::OnRender(Surf_Display);
}

//------------------------------------------------------------------------------
void CRings::OnCleanup() {
	CEntity::OnCleanup();
}

//------------------------------------------------------------------------------
void CRings::OnAnimate() {

	CEntity::OnAnimate();
}

//------------------------------------------------------------------------------
bool CRings::OnCollision(CEntity* Entity) {



    return true;
}

//=============================================================================
