#pragma once

#include <iostream>

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

void init();
void setLed(int ledNumber);
char next(int ninputs, const char inputs[]);
int nextState(int currState, char input);
bool isFinalState(int s);
void waitFor(const int ms);