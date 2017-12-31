#ifndef CRANKING_H_
    #define CRANKING_H_

#include "CSurface.h"
#include "CControl.h"

class CRanking {

	public:
		int		Music;

		int     RankingType;

	private:
        int     ScrollX;

        unsigned long    OldTime;

        int     Option;

		

        SDL_Surface*    Surf_Ranking;

		SDL_Surface*	Surf_Ranking_Fondo;

    public:

        CRanking();

        void SetRanking(int MType);
        void RankingTimer();

        void OnLoop();
        void OnRender(SDL_Surface* Surf_Display);
        bool OnLoad();
        void OnCleanup();

        int GetOption();

};


#endif // CRANKING_H_
