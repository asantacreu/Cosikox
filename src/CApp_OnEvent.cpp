#include "CApp.h"

void CApp::OnEvent(SDL_Event* Event){

     CEvent::OnEvent(Event);
}


void CApp::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
	
	//if(GameState == 2) OnExit();

    switch(sym) {
        case SDLK_LEFT: {
             Player1.MoveLeft = true;
             CControl::Keys.PressLeft = true;
             break;
        }
        case SDLK_RIGHT: {
			Player1.MoveRight = true; 
			CControl::Keys.PressRight = true;

             break;
        }
        case SDLK_UP: {
			CControl::Keys.PressUp = true; 

             break;
        }

        case SDLK_DOWN: {
			 CControl::Keys.PressDown = true;

            break;
        }

		case SDLK_b: {
			CBullet *Bullet= new CBullet;
			if(Bullet->OnLoad("./gfx/bala.png",16,16,8) == false) break;
			if(Player1.CurrentFrameCol == 0){	
				Bullet->X = Player1.X - 50;
				Bullet->MoveLeft = true;
				Bullet->Y = Player1.Y + 20;
				Bullet->Type = ENTITY_TYPE_BULLET;
				CEntity::ObjectList.push_back(Bullet);
				Bullet->Flags = ENTITY_FLAG_NONE;
			}else{if(Player1.CurrentFrameCol == 1){	
				Bullet->X = Player1.X  + 32 + 50;
				Bullet->MoveRight = true;
				Bullet->Y = Player1.Y + 20;
				Bullet->Type = ENTITY_TYPE_BULLET;
				CEntity::ObjectList.push_back(Bullet);
				Bullet->Flags = ENTITY_FLAG_NONE;
				}
			}

			break;
		}
		
		case SDLK_i: {
			CControl::Keys.I = true;
			break;
		};

		case SDLK_o: {
			CControl::Keys.O = true;
			break;
		};

		case SDLK_p: {
			CControl::Keys.P = true;
			break;
		};
		case SDLK_k: {
			CControl::Keys.K = true;
			break;
		};

		case SDLK_l: {
			CControl::Keys.L = true;
			break;
		};

        case SDLK_ESCAPE: {
			 CControl::Keys.PressEsc = true;
             //CApp::OnExit();
			 pause = true; 
             break;
             }

	    case (SDLK_SPACE): {

			 if(!CControl::Keys.SpaceDown) {
				CControl::Keys.PressSpace = true;
				CControl::Keys.SpaceDown = true;
			 }
			 break;
		 }
    }
}

void CApp::OnKeyUp(SDLKey sym, SDLMod, Uint16 unicode){
     switch(sym){
                 case SDLK_LEFT: {
					 CControl::Keys.PressLeft = false;
					 Player1.MoveLeft = false;

                      break;
                 }

                 case SDLK_RIGHT: {
					  CControl::Keys.PressRight = false;
                      Player1.MoveRight = false;

                      break;
                 }

			     case SDLK_UP: {
					  CControl::Keys.PressUp = false;
			          break;
				 }

				 case SDLK_DOWN: {
					  CControl::Keys.PressDown = false;
			          break;
                 }

				case SDLK_i: {
					CControl::Keys.I = false;
					break;
				};

				case SDLK_o: {
					CControl::Keys.O = false;
					break;
				};

				case SDLK_p: {
					CControl::Keys.P = false;
					break;
				};
				case SDLK_k: {
					CControl::Keys.K = false;
					break;
				};

				case SDLK_l: {
					CControl::Keys.L = false;
					break;
				};

				 case SDLK_SPACE: {
					  CControl::Keys.PressSpace = false;
					  CControl::Keys.SpaceDown = false;
					  break;
				 }
				 case SDLK_ESCAPE: {
					  //CControl::Keys.PressEsc = false;
					 
					 break;
				 }
     }

}

void CApp::OnExit(){
     Running = false;
}

void CApp::CheckLife(){
    if(Player1.Hit){
		if(Player1.Life <= 0){
			UpdateStage();
			GameState = 2;
			Player1.CurrentStage = 0;
			music = false;
			Dead = true;
			//OnExit();
		}else{
			UpdateStage();
			Player1.X = 30;
			Player1.Y = 100;
			GameState = 1;		
		}
		Player1.Hit = false;
    }
}

