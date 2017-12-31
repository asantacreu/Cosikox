#include "CRanking.h"

CRanking::CRanking(){

    ScrollX = -152;
    Option = 0;
    RankingType = 0;
    Surf_Ranking = NULL;
	Surf_Ranking_Fondo = NULL;
	Music = NULL;
    OldTime = 0;
};

void CRanking::SetRanking(int RType){
    RankingType = RType;
    Option = 0;
    ScrollX = -152;
};

void CRanking::OnLoop(){
	
    if(ScrollX <= -8) RankingTimer();
        else {
            if(CControl::Keys.PressUp) Option = 0;
            if(CControl::Keys.PressDown) Option = 1;
    }
}

bool CRanking::OnLoad(){
	if((Surf_Ranking =		  CSurface::OnLoad("./font/bg_ranking.png")) == NULL){ 
		return false;
	}
	if((Surf_Ranking_Fondo = CSurface::OnLoad("./font/bg_ranking_fondo.png")) == NULL){ 
		return false;
	}
	return true;
}


void CRanking::RankingTimer(){
    if(OldTime + 5 < SDL_GetTicks()){
        ScrollX += 8;
        OldTime = SDL_GetTicks();
    }
}

void CRanking::OnRender(SDL_Surface* Surf_Display){
	CSurface::OnDraw(Surf_Display, Surf_Ranking_Fondo, 0,0 );
    //CSurface::OnDraw(Surf_Display, Surf_Ranking, ScrollX, 240, 0, 0  + (RankingType*128) + (Option*32), 153, 32);
   // CSurface::OnDraw(Surf_Display, Surf_Ranking, ScrollX, 280, 0, 96 + (RankingType*128) - (Option*32), 153, 32);

}

int CRanking::GetOption(){
    return(Option);
}

void CRanking::OnCleanup(){
    if(Surf_Ranking) SDL_FreeSurface(Surf_Ranking);
    Surf_Ranking = NULL;
}
