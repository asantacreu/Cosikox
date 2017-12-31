#ifndef COPTIONS_H_
    #define COPTIONS_H_

#include "CMusicBank.h"
#include "CSoundBank.h"
#include "CSurface.h"
#include "CControl.h"



class COptions {

	public:
		int		Music;

		int     MenuType;

	private:
        int     ScrollX;

        unsigned long    OldTime;

        int     Option;

		

        SDL_Surface*    Surf_Menu_Options;

		SDL_Surface*	Surf_Menu_Options_Fondo;

		SDL_Surface*	Surf_Menu_Options_Volume;

    public:

        COptions();

        //void SetMenu(int MType);
        void MenuTimer();

        void OnLoop();
        void OnRender(SDL_Surface* Surf_Display);
        bool OnLoad();
        void OnCleanup();

        int GetOption();

};


#endif // COPTIONS_H_
