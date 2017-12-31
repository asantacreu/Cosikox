#ifndef CMOD_H_
    #define CMOD_H_

#include "CEntity.h"


class CMob : public CEntity {
    public:
		int CheckCollision;

        CMob();

		bool OnLoad(char* File, int Width, int Height, int MaxFrames);

        void OnLoop();

        void OnRender(SDL_Surface* Surf_Display);

        void OnCleanup();

        void OnAnimate();

		void    OnMove(float MoveX, float MoveY);

		void OnCollisionTileX();

        bool OnCollision(CEntity* Entity);
};


#endif // CMob_H_
