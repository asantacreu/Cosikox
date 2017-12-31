#ifndef _CAPP_H_
        #define _CAPP_H_

#include <SDL.h>



#include "CSoundBank.h"
#include "CMusicBank.h"

#include "CSurface.h"
#include "Define.h"
#include "CArea.h"
#include "CCamera.h"
#include "CEvent.h"
#include "CAnimation.h"
#include "CEntity.h"
#include "CPlayer.h"
#include "CFPS.h"
#include "CMod.h"
#include "CText.h"
#include "CControl.h"
#include "CMenu.h"
#include "CRings.h"
#include "CBullet.h"
#include "CPlatform.h"
#include "CRanking.h"
#include "COptions.h"

#include <tchar.h>
 



class CApp : public CEvent {

      public:
             int Jump;
			 int Victory;
             int InGame;
             int GameOver;
			 int Menu;
			 bool music;    
			 bool pause;
			 bool Dead;

      private:
              bool  Running;
              //game uses 4 states:
              //1. Intro Screen
              //2. Menu Screen
              //3. Playing Game
              //4. Paused in game with menu
              int		GameState;
			  COptions      Op;
              CPlayer       Player1;
              CText         Text;
              CMenu         M;
			  
			  CRanking		R;
			 
			
              SDL_Surface*  Surf_Display;
              SDL_Surface*  Surf_Ranking;
			  SDL_Surface*	Surf_GameOver;

      private:
              CEntity      Entity1;
              CEntity      Entity2;

      public:

             CApp();

             int OnExecute();

      public:
             bool            OnInit();

             void            OnEvent(SDL_Event* Event);

             void            OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

             void            OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);

             void            OnExit();

             void            CheckLife();

			 void            OnLoop();

             void            OnRender();

             void            OnCleanup();

			 void			 AddMob(int x, int y, bool MoveLeft, bool MoveRight, int type);

			 void			 AddPlatform(int x, int y, bool MoveLeft, bool MoveRight, int type);

			 bool			 UpdateStage();

			 void			 AddRing (int x, int y, int type);

			 void			 OnCleanupStage();

};


#endif
