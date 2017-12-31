#ifndef CBULLET_H_
    #define CBULLET_H_

#include "CEntity.h"


class CBullet : public CEntity {
    public:
		int CheckCollision;

        CBullet();

		~CBullet();

		bool OnLoad(char* File, int Width, int Height, int MaxFrames);

        void OnLoop();

        void OnRender(SDL_Surface* Surf_Display);

        void OnCleanup();

        void OnAnimate();

		void OnMove(float MoveX, float MoveY);

		void OnCollisionTileX();

        bool OnCollision(CEntity* Entity);
};


#endif // CBULLET_H_
