
#include "CControl.h"

CControl CControl::Keys;

CControl::CControl() {

    	PressUp   = false;
        PressDown = false;
        PressLeft = false;
        PressRight= false;
        PressSpace= false;
        //PressPause = false;
        PressEsc  = false;
        SpaceDown = false;
		I		  = false;
		O		  = false;
		P         = false;
		K		  = false;
		L		  = false;


        Score = 0;
        Life = 0;

};
