#include "CCamera.h"

CCamera CCamera::CameraControl;

CCamera::CCamera(){
                    X = Y = 0;

                    TargetX = TargetY = NULL;

                    Targetmode = TARGET_MODE_NORMAL;
}

void CCamera::OnMove(int MoveX, int MoveY){
     X += MoveX;
     Y += MoveY;
}

int CCamera::GetX(){
	float x =  (WWIDTH / 2);
	float x_limit =  (MAP_HEIGHT * TILE_SIZE * 3)-x;
	float *x_ptr= &x;
	float *x_limit_ptr= &x_limit;
    if(TargetX != NULL){
               if(Targetmode == TARGET_MODE_CENTER){
				   if(*TargetX <= *x_ptr ){//Limita la pantalla
					   return  0;
				   }else if(*TargetX >= *x_limit_ptr){
					   return x_limit-x;
				   }
				return *TargetX - (WWIDTH / 2);

               }

               return *TargetX;

    }

    return X;
}

int CCamera::GetY(){
	float y =  (WHEIGHT / 2);
	float y_limit = (MAP_HEIGHT * TILE_SIZE * 3)-y; 
	float *y_ptr= &y;
	float *y_limit_ptr= &y_limit;
    if(TargetY != NULL){
               if(Targetmode == TARGET_MODE_CENTER){
				   if(*TargetY <= *y_ptr ){//Limita la pantalla
					   return  0;
				   }else if(*TargetY >= *y_limit_ptr){
					   return y_limit-y;
				   }
                   return *TargetY - (WHEIGHT / 2);

               }

               return *TargetY;

    }

    return Y;
}

void CCamera::SetPos(int X, int Y){
     this->X = X;
     this->Y = Y;
}

void CCamera::SetTarget(float* X, float* Y){
     TargetX = X;
     TargetY = Y;
}

