#include "COptions.h"

COptions::COptions(){

    ScrollX = 100;//-152; // Posicio X del menu
    Option = 0;
    //MenuType = 0;
    Surf_Menu_Options = NULL;
	Surf_Menu_Options_Fondo = NULL;
	//Music = NULL;
    //OldTime = 0;
};

/*void COptions::SetMenu(int MType){
    MenuType = MType;
    Option = 0;
    ScrollX = -152;
};*/

void COptions::OnLoop(){
	if(ScrollX <= -8) MenuTimer();
	else {
		if(CControl::Keys.PressUp){
			if(Option == 1){
				Option = 0;
			}else if(Option ==2){
				Option = 1;
			}
			SDL_Delay(100);
		}
		if(CControl::Keys.PressDown){
			if(Option == 1){
				Option = 2;
			}else if(Option ==0){
				Option = 1;
			}
			SDL_Delay(100);
		}
		//SDL_Delay(100); //Delay perque sino passa de la opcio 1 a la 2 
	}
}

void COptions::MenuTimer(){
    if(OldTime + 5 < SDL_GetTicks()){
        ScrollX += 8;
        OldTime = SDL_GetTicks();
    }
}

bool COptions::OnLoad(){

	if((Surf_Menu_Options =		  CSurface::OnLoad("./gfx/bg_menu_options.png")) == NULL){ 
		return false;
	}
	if((Surf_Menu_Options_Fondo = CSurface::OnLoad("./gfx/bg_menu_fondo.png")) == NULL){ 
		return false;
	}
	if((Surf_Menu_Options_Volume = CSurface::OnLoad("./gfx/volume.png")) == NULL){ 
		return false;
	}
	return true;
}

void COptions::OnRender(SDL_Surface* Surf_Display){
	CSurface::OnDraw(Surf_Display, Surf_Menu_Options_Fondo, 0,0 );
	switch(Option){
		
		case 0:{//Music Volume Active
			
			CSurface::OnDraw(Surf_Display, Surf_Menu_Options, ScrollX, 240, 0, 0,  530, 32);
			CSurface::OnDraw(Surf_Display, Surf_Menu_Options, ScrollX, 280, 0, 64 + 32, 530, 32);
			CSurface::OnDraw(Surf_Display, Surf_Menu_Options, ScrollX, 320, 0, 128+ 32,152, 32);
			
			break;
		}
		case 1:{//Sound Volume Active

			CSurface::OnDraw(Surf_Display, Surf_Menu_Options, ScrollX, 240, 0, 32, 530, 32);
			CSurface::OnDraw(Surf_Display, Surf_Menu_Options, ScrollX, 280, 0, 64,  530, 32);
			CSurface::OnDraw(Surf_Display, Surf_Menu_Options, ScrollX, 320, 0, 128 + 32,152, 32);
			break;
		}
		case 2:{//Back Active

			CSurface::OnDraw(Surf_Display, Surf_Menu_Options, ScrollX, 240, 0, 32, 530, 32);
			CSurface::OnDraw(Surf_Display, Surf_Menu_Options, ScrollX, 280, 0, 64 + 32, 530, 32);
			CSurface::OnDraw(Surf_Display, Surf_Menu_Options, ScrollX, 320, 0, 128    , 152, 32);
			break;
		}
	}
	int volumeM = CMusicBank::MusicControl.Volume/3.86;
	int volumeS = CSoundBank::SoundControl.Volume/3.86;
	for(int i = 0;i<volumeM;i++){
			CSurface::OnDraw(Surf_Display, Surf_Menu_Options_Volume, ScrollX+173+(10*i), 240+10, 0, 0,10, 14);
	}
	for(int j = 0;j<volumeS;j++){
		
		CSurface::OnDraw(Surf_Display, Surf_Menu_Options_Volume, ScrollX+173+(10*j), 280+10, 0, 0,10, 14);
	}
}

int COptions::GetOption(){
    return(Option);
}

void COptions::OnCleanup(){
    if(Surf_Menu_Options) SDL_FreeSurface(Surf_Menu_Options);
    Surf_Menu_Options = NULL;
}
