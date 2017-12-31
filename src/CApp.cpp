#include "CApp.h"

CApp::CApp(){
             Running      = true;

             Surf_Display = NULL;

//           Surf_Menu    = NULL;

			 pause		  = false;

             GameState    = 0;

			 music		  = false;

			 Surf_GameOver= NULL;

			 Dead		  = false;

			 Victory	= NULL;
             InGame = NULL;
             GameOver = NULL;
			 Menu = NULL;




}

int CApp::OnExecute(){


                  if(OnInit() == false){
                            return -1;
                  }



                  SDL_Event Event;

                  while(Running){
                                 while(SDL_PollEvent(&Event)){
                                                              OnEvent(&Event);

                                 }

                                 OnLoop();

                                 OnRender();
									
                                if(!Dead) CheckLife();
                  }

                  OnCleanup();


                   return 0;
}


#include "windows.h"
/*int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine_A, int nCmdShow) {	
	main(0,0);
};*/


int _tmain(int argc, char* argv[]){
    CApp theApp;

    return theApp.OnExecute();
}
