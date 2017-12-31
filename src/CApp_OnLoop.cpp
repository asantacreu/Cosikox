#include "CApp.h"

void CApp::OnLoop(){
	//GameState = 2 ;


	switch(GameState) {

		case 0: {//Menus
			if(!music && M.MenuType == 0){//plays musicmenu
					CMusicBank::MusicControl.Play(M.Music);
					music = true;
			}
			if(M.MenuType!=3){
				M.OnLoop();
			}else{
				Op.OnLoop();
			}

			if(CControl::Keys.PressSpace) {
				if(M.MenuType == 0){//Main Menu
					
					switch(M.GetOption()){
						case 0: {//START
							GameState = 1;
							music = false;
							break;
						}
						case 1: {//OPTIONS
							M.MenuType = 3;
							break;
						}
						case 2: {//EXIT
							OnExit();
							music = false;
							break;
						}
					}
				}else if(M.MenuType == 1){//Pause Menu
					switch(M.GetOption()){
						case 0: {//RESUME
							M.MenuType = 0;
							GameState = 1;
							break;
						}
						case 1: {//OPTIONS
							M.MenuType = 3;
							break;
						}
						case 2: {//EXIT
							OnExit(); // Per el moment, com que no podem reiniciar el joc, fem exit directe.
							break;
						}
					}
				}else if(M.MenuType == 2){//Exit Menu??
					switch(M.GetOption()){
						case 0: {
							M.MenuType = 0;
							GameState = 0;
							break;
						}
						case 1: {
							OnExit(); // Revisar perquè ara surt del joc i volem que torni al principi!!!
							GameState = 0;
							break;
						}
					}
				}else if(M.MenuType == 3){//Options Menu
					if(Op.GetOption()==2){
						M.MenuType = 0;//Torna al menu inici
						SDL_Delay(100);
					}
				}
			
			}
			if(CControl::Keys.PressRight){
				if(M.MenuType == 3){
					 if(Op.GetOption()==0){
						if(CMusicBank::MusicControl.Volume<SDL_MIX_MAXVOLUME)
							CMusicBank::MusicControl.Volume++;
					 }else if(Op.GetOption()==1){
						if(CSoundBank::SoundControl.Volume<SDL_MIX_MAXVOLUME)
							CSoundBank::SoundControl.Volume++;
					 }
				}
			}
			if(CControl::Keys.PressLeft){
					if(M.MenuType == 3){
					 if(Op.GetOption()==0){
						if(CMusicBank::MusicControl.Volume>0)
							CMusicBank::MusicControl.Volume--;
					 }else if(Op.GetOption()==1){
						if(CSoundBank::SoundControl.Volume>0)
							CSoundBank::SoundControl.Volume--;
					 }
				}
			}

			break;
		}

		case 1: {

			if(pause){
				GameState--;
				M.MenuType = 1;
				pause = false;
			}

			if(!music){
				CMusicBank::MusicControl.Play(InGame);
				music = true;
			}
			if(CControl::Keys.PressUp){
				Player1.Jump();
				CSoundBank::SoundControl.Play(Jump);
			}
			
			for(int i = 0;i < CEntity::ObjectList.size(); i++){
				if(CEntity::ObjectList[i]){
					CEntity::ObjectList[i]->OnLoop();
			}
			}
			//Collision Events
			for(int i = 0;i < CEntityCol::EntityColList.size();i++){
				CEntity* EntityA = CEntityCol::EntityColList[i].EntityA;
				CEntity* EntityB = CEntityCol::EntityColList[i].EntityB;

				if(EntityA == NULL || EntityB == NULL) continue; 

				if(EntityA->OnCollision(EntityB)){
					EntityB->OnCollision(EntityA);

				}

			}

			CEntityCol::EntityColList.clear();
			Player1.OnLoop();

			for(int i = CEntity::ObjectList.size()-1; i>=0; i--){
				CEntity *Entity = CEntity::ObjectList[i]; 
				if(Entity){ 
					if( Entity->Condemned){
						if(Entity->Type == ENTITY_TYPE_MOB_NORMAL2 || Entity->Type == ENTITY_TYPE_MOB_NORMAL || Entity->Type == ENTITY_TYPE_MOB_KILLER){
							CEntity::puntuacio += 100;
						}
						CEntity::ObjectList.erase(CEntity::ObjectList.begin() + i);
						CEntityCol::EntityColList.clear();
						delete Entity;
						Entity = NULL;
					}
				}
			}	
			 break;
		}

		case 2: {// END GAME LOST
			if(!music){
				CMusicBank::MusicControl.Play(GameOver);
				music = true;
			}
            //R.OnLoop();
			if(CControl::Keys.PressSpace) {
				GameState = 0;
				M.MenuType = 0;
				Player1.X = 30;
				Player1.Y = 100;
				Player1.Life = 3;
				Player1.CurrentStage = 0;
				Dead = false;
				CEntity::puntuacio = 0;
				UpdateStage();
				SDL_Delay(150);
			}
			if(CControl::Keys.PressEsc){
					OnExit();
			}
						
			break;
		
		}

		case 3: {// END GAME WIN
			if(!music){
				CMusicBank::MusicControl.Play(Victory);
				music = true;
			}

            //R.OnLoop();

			if(CControl::Keys.PressSpace) {
				GameState = 0;
				M.MenuType = 0;
				Player1.X = 30;
				Player1.Y = 100;
				Player1.Life = 3;
				Player1.CurrentStage = 0;
				Player1.SpeedX = Player1.SpeedY = 0;
				Dead = false;
				CEntity::puntuacio = 0;
				UpdateStage();
				SDL_Delay(150);
			}
			if(CControl::Keys.PressEsc){
					OnExit();
			}
						
			break;
		
		} 
	}

    CFPS::FPSControl.OnLoop();

    SDL_WM_SetCaption("Cosikox", NULL);


}


//==============================================================================
