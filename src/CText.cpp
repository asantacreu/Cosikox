#include "CText.h"




CText::CText(){
	font.Surf_Text = NULL;
	//TextType = 0;
}
CText::~CText() {
   // if (font.Surf_Text) 
	//	SDL_FreeSurface(font.Surf_Text);
	//SDL_GetError();
}
bool CText::ReadFont(const char * name){
    if (font.Surf_Text) 
		SDL_FreeSurface(font.Surf_Text);
	font.Surf_Text   = IMG_Load(name);
    font.FontWidth   = 256;
    font.FontHeight  = 256;
    font.LetterWidth = 16;
    font.LetterHeight= 16;
    font.FirstLetter = 0;
    return (font.Surf_Text!=NULL); //font.Surf_Text;

}

void CText::WriteLetter(SDL_Surface* Surf_Dest, int x, int y, char letter){
    SDL_Rect destination, origin;

    int line, column;
    int lettersPerLine, lettersPerColumn;

    lettersPerLine = font.FontWidth / font.LetterWidth;
    lettersPerColumn = font.FontHeight / font.LetterHeight;

    line = letter / lettersPerColumn;
    column = letter % lettersPerColumn;
    origin.x = column * font.LetterWidth;
    origin.y = line * font.LetterHeight;
    origin.w = 16;
    origin.h = 16;
    destination.x = x;
    destination.y = y;

    SDL_BlitSurface(font.Surf_Text, &origin,  Surf_Dest, &destination);
}

void CText::WriteFrase(SDL_Surface* Surf_Dest, int x, int y, char *frase){

    unsigned int i;

    for(i=0; i<strlen(frase); i++){
            WriteLetter(Surf_Dest, x + i * font.LetterWidth, y, frase[i]);
    }
}




