#define _S0 5
#define _S1 6
#define _S2 6
#define _S3 13
#define _ERR 19

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>

#ifndef NO_PI
#include <wiringPi.h>
#endif

using namespace std;

static int i = 0;

///
/// Utils
///
void init()
{
#ifndef NO_PI
    wiringPiSetup();
    pinMode(led_Blue, OUTPUT);
#endif
}

void setLed(int ledNumber)
{
#ifndef NO_PI
    switch (ledNumber)
    {
    case 0:
        digitalWrite(_S0);
        break;
    case 1:
        digitalWrite(_S1);
        break;
    case 2:
        digitalWrite(_S2);
        break;
    case 3:
        digitalWrite(_S3);
        break;
    default:
        digitalWrite(_ERR)
        break;
    }
#else
    cout << "Setting led " << ledNumber << endl;
#endif
}

/* Gets next inputs, or 'x' if no inputs available */
char next(int ninputs, const char inputs[])
{
	if(i >= ninputs)
		return 'x';
	return inputs[i++];
}

/*
 * Computes next state. Returns the following
 *   >0 : the next state
 *   -1 : input sequence not legal
 *   -2 : we're in final state
 *   -3 : internal error
 */
int nextState(int currState, char input)
{
	switch(currState)
	{
		case 0:
			switch(input)
			{
				case 'a': return 2;
				case 'b': return 1;
				case 'c': return 3;
				default:  break;
			}
			break;
			
		case 1:
			switch(input)
			{
				case 'a': break;
				case 'b': return 1;
				case 'c': return 3;
				default:  break;
			}
			break;
			
		case 2:
			switch(input)
			{
				case 'a': return 0;
				case 'b': break;
				case 'c': break;
				default: break;
			}
			break;
			
		case 3:
			return -2;
			
		default:
			return -3;
	}
	
	// If we're here, it's an error
	return -1;
}

bool isFinalState(int s)
{
	return s == 3;
}

void waitFor(const int ms)
{
#ifndef NO_PI
        delay(ms);
#else
        usleep(ms * 1000);
#endif
}