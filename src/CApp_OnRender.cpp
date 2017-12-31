#include "CApp.h"

//#include <unistd.h>
#include <dos.h>
#include <stdio.h>
#include <conio.h>

void CApp::OnRender(){

	switch (GameState){

		case 0: {
			if(M.MenuType!=3){
				M.OnRender(Surf_Display);
			}else{				
				Op.OnRender(Surf_Display);
			}
			 SDL_Flip(Surf_Display);
	 
			 break;
		}

		case 1: {

				SDL_Rect Rect;
				Rect.x = 0;
				Rect.y = 0;
				Rect.w = WWIDTH;
				Rect.h = WHEIGHT;

				SDL_FillRect(Surf_Display, &Rect, 0);


				// Control Change Stages!!
				if(Player1.Life <= 0) Text.WriteFrase(Surf_Display, 400, 400, "GAME OVER" );
				CArea::AreaControl.OnRender(Surf_Display,  -CCamera::CameraControl.GetX(), -CCamera::CameraControl.GetY());
				for(unsigned int i = 0;i < CEntity::ObjectList.size();i++) {
					if(!CEntity::ObjectList[i]) continue;
					CEntity::ObjectList[i]->OnRender(Surf_Display);
					}

				Text.WriteFrase(Surf_Display, 400, 0, "Cosikox 1.0.10" );
				char str2[33];
				sprintf_s(str2, "Lives = %d", Player1.Life);
				Text.WriteFrase(Surf_Display, 0, 0, str2 );

				char str[33];
				sprintf_s(str, "Score = %d", Player1.puntuacio);
				Text.WriteFrase(Surf_Display, 900, 0, str );
				/*char strr[33];
				sprintf(strr, "Player.X = %f", Player1.X);
				Text.WriteFrase(Surf_Display, 900, 50, strr );
				char strrr[33];
				sprintf(strrr, "Player.Y = %f", Player1.Y);
				Text.WriteFrase(Surf_Display, 900, 70, strrr );
				*/

				if( Player1.StageClear == true) {
					if(Player1.CurrentStage == 4){
						Text.WriteFrase(Surf_Display, 400, 400, "CONGRATULATIONS!! You have reached the end of the game!" );
						GameState = 3;
					}else{

						Player1.StageClear = false;
						Text.WriteFrase(Surf_Display, 400, 400, "Stage cleared!" );
						SDL_Flip(Surf_Display);
						SDL_Delay(500);

                                
						char stgnum[33];
						Player1.CurrentStage++;

						this->UpdateStage();

						CArea::AreaControl.OnRender(Surf_Display,  -CCamera::CameraControl.GetX(), -CCamera::CameraControl.GetY());
						sprintf_s(stgnum, "Stage %d", Player1.CurrentStage);
						Text.WriteFrase(Surf_Display, 200, 400, stgnum );
						SDL_Flip(Surf_Display);
						SDL_Delay(1500);
						Player1.StageClear = false;
						CCamera::CameraControl.SetPos(Player1.X,Player1.Y);
					}


				}

				char Buffer[255];
				sprintf_s(Buffer, "FPS: %d", CFPS::FPSControl.GetFPS());
				Text.WriteFrase(Surf_Display, 0, 50, Buffer);
				
				SDL_Flip(Surf_Display);

				break;
		}
		case 2: {
			
             R.OnRender(Surf_Display);
			 
			 char name[73];
			 sprintf_s(name, "GAME OVER!         Final Score = %d    Press SPACE to EXIT", Player1.puntuacio);
             Text.WriteFrase(Surf_Display, 200, 450, name);
			 SDL_Flip(Surf_Display);

			 
			 break;
		}
				case 3: {
			
             R.OnRender(Surf_Display);
			 
			 char name[73];
			 sprintf_s(name, "   Final Score = %d    Press SPACE to EXIT", Player1.puntuacio);
             Text.WriteFrase(Surf_Display, 200, 450, name);
			 SDL_Flip(Surf_Display);

			 // LA montse pujol és una PUTA!!!!
			 break;
		}
	}
}

