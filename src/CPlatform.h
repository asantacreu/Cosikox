#ifndef CPLATFORM_H_
    #define CPLATFORM_H_

#include "CEntity.h"


class CPlatform : public CEntity {
    public:
		int CheckCollision;

        CPlatform();

		~CPlatform();

		bool OnLoad(char* File, int Width, int Height, int MaxFrames);

        void OnLoop();

        void OnRender(SDL_Surface* Surf_Display);

        void OnCleanup();

        void OnAnimate();

		void OnMove(float MoveX, float MoveY);

		void OnCollisionTileX();

        bool OnCollision(CEntity* Entity);
};


#endif // CPLATFORM_H_
