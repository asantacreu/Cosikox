#ifndef CTEXT_H_
    #define CTEXT_H_

#include <SDL.h>
#include <SDL_image.h>

#include <string.h>


class CText{

    public:

            struct FontType{
                SDL_Surface* Surf_Text;
                int FontWidth, FontHeight;
                int LetterWidth, LetterHeight;
                int FirstLetter;
            } font;

    public:

            CText();
            ~CText();

            bool ReadFont(const char * name);

			bool ReadFontAlpha(const char * name);

            void WriteLetter(SDL_Surface* Surf_Dest, int x, int y, char letter);

            void WriteFrase(SDL_Surface* Surf_Dest, int x, int y, char *frase);

};




#endif // CTEXT_H_
