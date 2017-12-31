#ifndef CMENU_H_
    #define CMENU_H_

#include "CSurface.h"
#include "CControl.h"

class CMenu {

	public:
		int		Music;

		int     MenuType;

	private:
        int     ScrollX;

        unsigned long    OldTime;

        int     Option;

		

        SDL_Surface*    Surf_Menu;

		SDL_Surface*	Surf_Menu_Fondo;

    public:

        CMenu();

        void SetMenu(int MType);
        void MenuTimer();

        void OnLoop();
        void OnRender(SDL_Surface* Surf_Display);
        bool OnLoad();
        void OnCleanup();

        int GetOption();

};


#endif // CMENU_H_
