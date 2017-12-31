//=============================================================================
#include "CBullet.h"
#include "CEntity.h"

//=============================================================================
CBullet::CBullet() {
}

CBullet::~CBullet(){
int a = 0; a++;
}
//=============================================================================
bool CBullet::OnLoad(char* File, int Width, int Height, int MaxFrames) {
    if(CEntity::OnLoad(File, Width, Height, MaxFrames) == false) {
        return false;
    }

    return true;
}

//-----------------------------------------------------------------------------
void CBullet::OnLoop() {
	CEntity::OnLoop();
}

void CBullet::OnMove(float MoveX, float MoveY) {
	if(MoveX == 0 && MoveY == 0) return;

	double NewX = 0;
	double NewY = 0;

	CanJump = false;

	MoveX *= CFPS::FPSControl.GetSpeedFactor();
	MoveY *= CFPS::FPSControl.GetSpeedFactor();

	if(MoveX != 0) {
		if(MoveX >= 0) 	NewX =  CFPS::FPSControl.GetSpeedFactor();
		else 			NewX = -CFPS::FPSControl.GetSpeedFactor();
	}

	if(MoveY != 0) {
		if(MoveY >= 0) 	NewY =  CFPS::FPSControl.GetSpeedFactor();
		else 			NewY = -CFPS::FPSControl.GetSpeedFactor();
	}

	while(true) {
		
			if(CEntity::PosValidMap((int)(X + NewX), (int)(Y))) {
				X += NewX;
			}else{
				OnCollisionTileX(); // abans feiem: SpeedX = 0;
			}

			if(CEntity::PosValidMap((int)(X), (int)(Y + NewY))) {
				Y += NewY;
			}else{
                if(MoveY > 0) {
                    CanJump = true;
                }

				SpeedY = 0;
			}
		

		MoveX += -NewX;
		MoveY += -NewY;

		if(NewX > 0 && MoveX <= 0) NewX = 0;
		if(NewX < 0 && MoveX >= 0) NewX = 0;

		if(NewY > 0 && MoveY <= 0) NewY = 0;
		if(NewY < 0 && MoveY >= 0) NewY = 0;

		if(MoveX == 0) NewX = 0;
		if(MoveY == 0) NewY = 0;

		if(MoveX == 0 && MoveY 	== 0) 	break;
		if(NewX  == 0 && NewY 	== 0) 	break;
	}
}

//-----------------------------------------------------------------------------
void CBullet::OnRender(SDL_Surface* Surf_Display) {
	CEntity::OnRender(Surf_Display);
}

//------------------------------------------------------------------------------
void CBullet::OnCleanup() {
	CEntity::OnCleanup();
}

//------------------------------------------------------------------------------
void CBullet::OnAnimate() {
	if(SpeedX != 0) {
		Anim_Control.MaxFrames = 8;
	}else{
		Anim_Control.MaxFrames = 0;
	}

	CEntity::OnAnimate();
}

//------------------------------------------------------------------------------
bool CBullet::OnCollision(CEntity* Entity) {
	if( Entity->Type == ENTITY_TYPE_BULLET) {
		Condemned = false;
		return true;
	}
	if( Entity->Type == ENTITY_TYPE_PLAYER_NORMAL) 
		return false;
		
		SpeedX = 0;
		Condemned = true;

    return true;
}

void CBullet::OnCollisionTileX(){
		Condemned = true;
}


//=============================================================================
