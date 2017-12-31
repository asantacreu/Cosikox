#ifndef CCONTROL_H_
    #define CCONTROL_H_

#include <SDL.h>



class CControl{

    public:
        static	 CControl Keys;

        CControl();

        bool                PressUp;
        bool                PressDown;
        bool                PressLeft;
        bool			    PressRight;
        bool			    PressSpace;
       // bool			    PressPause;
        bool			    PressEsc;
        bool			    SpaceDown;
		bool				I;
		bool				O;
		bool				P;
		bool				K;
		bool				L;

        //Player1 stadistics

        int                 Life;
        int                 Score;
};



#endif // CCONTROL_H_
