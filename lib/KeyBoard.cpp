#include "KeyBoard.h"
#include <unistd.h>

void Keyboard::run()
{
     tcgetattr(STDIN_FILENO,&oldt);
     while(keyboard_processing)
     {
	usleep(1);
	key = getEnterKey();
	CLEAR_CHARACTER;
     }
}

bool Keyboard::pressedKeysIs(int k1,int k2)
{
         CLEAR_CHARACTER;
         return (key == k1 || key == k2) ? (clearKey(),true) : false ;
}

bool Keyboard::pressedKeyIs(int k)
{
        CLEAR_CHARACTER;
        return (key == k) ? (clearKey(), true) : false ;
}

void Keyboard::clearKey()
{
          key = 0;
} 

bool Keyboard::kbhit()
{
     for(int i = 0; i < getSize(); i++)
     {
           if(key == keyboard[i].first) 
	   {
		   CLEAR_CHARACTER;
		   return true;
	   }
    }
    CLEAR_CHARACTER;
    return false;
}

std::pair<int,std::string>  Keyboard::getKey(int index)
{
     if(index >= 0 && index <= keyboard.size())
     {
         return keyboard[index];
     }
     return std::make_pair<int,std::string>(int(),std::string());
}

size_t Keyboard::getSize()
{
          return keyboard.size();
}

int Keyboard::getEnterKey() 
{
     struct termios newt;
     int ch;
     newt = oldt;
     newt.c_lflag &= ~( ICANON | ECHO );
     tcsetattr( STDIN_FILENO, TCSANOW, &newt );
     ch = getchar();
     tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
     return ch;
}

void Keyboard::terminate()
{
         keyboard_processing = false;
         system("reset");
}
