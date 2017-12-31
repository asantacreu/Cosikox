#include "CMenu.h"

CMenu::CMenu(){

    ScrollX = -152;
    Option = 0;
    MenuType = 0;
    Surf_Menu = NULL;
	Surf_Menu_Fondo = NULL;
	Music = NULL;
    OldTime = 0;
};

void CMenu::SetMenu(int MType){
    MenuType = MType;
    Option = 0;
    ScrollX = -152;
};

void CMenu::OnLoop(){
	
    if(ScrollX <= -8) MenuTimer();
    else {
		if(CControl::Keys.PressUp){
			if(Option == 1){
				Option = 0;
			}else if(Option ==2){
				Option = 1;
			}
		}
		if(CControl::Keys.PressDown){
			if(Option == 1){
				Option = 2;
			}else if(Option ==0){
				Option = 1;
			}
		}
		SDL_Delay(100); //Delay perque sino passa de la opcio 1 a la 2 
	}
}

bool CMenu::OnLoad(){
	if((Surf_Menu =		  CSurface::OnLoad("./gfx/bg_menu.png")) == NULL){ 
		return false;
	}
	if((Surf_Menu_Fondo = CSurface::OnLoad("./gfx/bg_menu_fondo.png")) == NULL){ 
		return false;
	}
	return true;
}


void CMenu::MenuTimer(){
    if(OldTime + 5 < SDL_GetTicks()){
        ScrollX += 8;
        OldTime = SDL_GetTicks();
    }
}

void CMenu::OnRender(SDL_Surface* Surf_Display){
	CSurface::OnDraw(Surf_Display, Surf_Menu_Fondo, 0,0 );
	switch(Option){
		case 0:{//START/RESUME Active

			CSurface::OnDraw(Surf_Display, Surf_Menu, ScrollX, 240, 0, 0  + (MenuType*192) + 0,  153, 32);
			CSurface::OnDraw(Surf_Display, Surf_Menu, ScrollX, 280, 0, 64 + (MenuType*192) + 32, 153, 32);
			CSurface::OnDraw(Surf_Display, Surf_Menu, ScrollX, 320, 0, 128 + (MenuType*192) + 32,153, 32);
			break;
		}
		case 1:{//OPTIONS Active

			CSurface::OnDraw(Surf_Display, Surf_Menu, ScrollX, 240, 0, 0  + (MenuType*192) + 32, 153, 32);
			CSurface::OnDraw(Surf_Display, Surf_Menu, ScrollX, 280, 0, 64 + (MenuType*192) + 0,  153, 32);
			CSurface::OnDraw(Surf_Display, Surf_Menu, ScrollX, 320, 0, 128 + (MenuType*192) + 32,153, 32);
			break;
		}
		case 2:{//EXIT Active

			CSurface::OnDraw(Surf_Display, Surf_Menu, ScrollX, 240, 0, 0  + (MenuType*192) + 32, 153, 32);
			CSurface::OnDraw(Surf_Display, Surf_Menu, ScrollX, 280, 0, 64 + (MenuType*192) + 32, 153, 32);
			CSurface::OnDraw(Surf_Display, Surf_Menu, ScrollX, 320, 0, 128 + (MenuType*192) + 0, 153, 32);
			break;
		}
	}
}

int CMenu::GetOption(){
    return(Option);
}

void CMenu::OnCleanup(){
    if(Surf_Menu) SDL_FreeSurface(Surf_Menu);
    Surf_Menu = NULL;
}
