//=============================================================================
#include "CMod.h"
#include "CEntity.h"

//=============================================================================
CMob::CMob() {
	CheckCollision = 0;
}

//=============================================================================
bool CMob::OnLoad(char* File, int Width, int Height, int MaxFrames) {
    if(CEntity::OnLoad(File, Width, Height, MaxFrames) == false) {
        return false;
    }

    return true;
}

//-----------------------------------------------------------------------------
void CMob::OnLoop() {
	if(MoveLeft == false && MoveRight == false){
		StopMove();
	}

	if(MoveLeft) {
		AccelX = -0.5;
	}else

	if(MoveRight) {
		AccelX = 0.5;
	}


	if(Flags & ENTITY_FLAG_GRAVITY) {
		AccelY = 0.75f;
	}

	SpeedX += AccelX * CFPS::FPSControl.GetSpeedFactor();
	SpeedY += AccelY * CFPS::FPSControl.GetSpeedFactor();

	if(SpeedX > MaxSpeedX)  SpeedX =  MaxSpeedX;
	if(SpeedX < -MaxSpeedX) SpeedX = -MaxSpeedX;
	if(SpeedY > MaxSpeedY)  SpeedY =  MaxSpeedY;
	if(SpeedY < -MaxSpeedY) SpeedY = -MaxSpeedY;

	CEntity::OnAnimate();
	OnMove(SpeedX, SpeedY);
}

void CMob::OnMove(float MoveX, float MoveY) {
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
		if(Flags & ENTITY_FLAG_GHOST) {
			CEntity::PosValid((int)(X + NewX), (int)(Y + NewY)); //We don't care about collisions, but we need to send events to other entities

			X += NewX;
			Y += NewY;
		}else{
			if(CEntity::PosValid((int)(X + NewX), (int)(Y))) {
				X += NewX;
			}else{
				OnCollisionTileX(); // abans feiem: SpeedX = 0;
			}

			if(CEntity::PosValid((int)(X), (int)(Y + NewY))) {
				Y += NewY;
			}else{
                if(MoveY > 0) {
                    CanJump = true;
                }

				SpeedY = 0;
			}
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
void CMob::OnRender(SDL_Surface* Surf_Display) {
	CEntity::OnRender(Surf_Display);
}

//------------------------------------------------------------------------------
void CMob::OnCleanup() {
	CEntity::OnCleanup();
}

//------------------------------------------------------------------------------
void CMob::OnAnimate() {
	if(SpeedX != 0) {
		Anim_Control.MaxFrames = 8;
	}else{
		Anim_Control.MaxFrames = 0;
	}

	CEntity::OnAnimate();
}

//------------------------------------------------------------------------------
bool CMob::OnCollision(CEntity* Entity) {

	if (Entity->Type == ENTITY_TYPE_BULLET){
		Condemned = true;
	}

	//if(CEntity::CheckPosition() == false){
	
   	if(CheckCollisionEntity==3000) {
		CheckCollisionEntity= 0;
	}
	if(CheckCollisionEntity==0){

		if(MoveLeft){
			MoveLeft = false;
			MoveRight = true;
		}
		else if(MoveRight){
			MoveRight = false;
			MoveLeft = true;
		};
	}
	//SpeedX = -SpeedX + 10;
	CheckCollisionEntity++;

    return true;
}

void CMob::OnCollisionTileX(){
	if(CheckCollisionWall==100) {
		CheckCollisionWall= 0;
	}
	if(CheckCollisionWall==0){

		if(MoveLeft){
			MoveLeft = false;
			MoveRight = true;
		}
		else if(MoveRight){
			MoveRight = false;
			MoveLeft = true;
		};
	}
	//SpeedX = -SpeedX + 10;
	CheckCollisionWall++;
}

//=============================================================================
