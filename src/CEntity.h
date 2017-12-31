//==============================================================================
#ifndef _CENTITY_H_
    #define _CENTITY_H_

#include <vector>

#include "CArea.h"
#include "CAnimation.h"
#include "CCamera.h"
#include "CFPS.h"
#include "CSurface.h"

//==============================================================================
enum {
	ENTITY_TYPE_GENERIC = 0,

	ENTITY_TYPE_PLAYER_NORMAL,

	ENTITY_TYPE_PLAYER_GROWED,

	ENTITY_TYPE_MOB_NORMAL2,

	ENTITY_TYPE_MOB_NORMAL,

	ENTITY_TYPE_MOB_KILLER,
	
	ENTITY_TYPE_PLATFORM,

	ENTITY_TYPE_RINGS_1,

	ENTITY_TYPE_RINGS_2,

	ENTITY_TYPE_BULLET
};

//==============================================================================
enum {
	ENTITY_FLAG_NONE 	= 0,

	ENTITY_FLAG_GRAVITY	= 0x00000001,
	ENTITY_FLAG_GHOST	= 0x00000002,
	ENTITY_FLAG_MAPONLY	= 0x00000004
};

//==============================================================================
class CEntity {
	public:
		static std::vector<CEntity*>    ObjectList;

		static int puntuacio;
		
	protected:
		CAnimation      Anim_Control;

		SDL_Surface*    Surf_Entity;

	public:
		
		
		int		MusicGame; //?
		float	X;
		float	Y;

		int		Width;
		int		Height;

		bool	MoveLeft;
		bool	MoveRight;

	public:
		int		Type;

		int  	Life;
		bool	Hit;
		int     CurrentStage;
		bool    StageClear;
		int		Flags;
		bool	Collided;
		int		CheckCollisionWall;
		int		CheckCollisionEntity;
		bool    Condemned;
	public:
		float	SpeedX;
		float	SpeedY;

		float	AccelX;
		float	AccelY;

    protected:

		bool	CanJump;

	public:
		float	MaxSpeedX;
		float	MaxSpeedY;
		int		CurrentFrameCol;
		int		CurrentFrameRow;

	protected:
		int		Col_X;
		int		Col_Y;
		int		Col_Width;
		int		Col_Height;

	public:
		CEntity();

		virtual ~CEntity();

	public:
		virtual bool OnLoad(char* File, int Width, int Height, int MaxFrames);

		virtual void OnLoop();

		virtual void OnRender(SDL_Surface* Surf_Display);

		virtual void OnCleanup();

		virtual void OnAnimate();

		virtual bool OnCollision(CEntity* Entity);

	public:
		virtual void OnMove(float MoveX, float MoveY);

		bool 	Jump();

		void 	StopMove();

	public:
		bool    Collides(int oX, int oY, int oW, int oH);

		bool    CollidesTop(int oX, int oY, int oW, int oH);

		bool    CollidesRing(int oX, int oY, int oW, int oH);
		
		bool 	PosValidTile(CTile* Tile);

		void	OnCollisionTileX();

		//bool	CheckPosition();

		bool 	PosValid(int NewX, int NewY);

		bool	PosValidMap(int NewX, int NewY);

		bool	PosValidEntities(int NewX, int NewY);

	private:

		

		

		bool 	PosValidEntity(CEntity* Entity, int NewX, int NewY);
};

//==============================================================================
class CEntityCol {
    public:
        static std::vector<CEntityCol>	EntityColList;

	public:
		CEntity* EntityA;
		CEntity* EntityB;

	public:
		CEntityCol();
};

//==============================================================================

#endif
