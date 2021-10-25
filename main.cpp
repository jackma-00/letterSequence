///
/// NOTE On Desktop systems, compile with -D NO_PI flag
//

#include "src/lib.h"

///
/// Configuration
///

const int timeoutMs = 2000; // 1 second
const char inputs[] = {'a', 'a', 'b', 'c'};
int ninputs = sizeof(inputs) / sizeof(inputs[0]);

int main()
{
    init();

    // Ok, inited. Now do your work...

    cout << "Inputs size is " << ninputs << endl;
	int currState = 0;
	int state = -1;
	char c;
	
	while(1)
	{
		// Get next input
		c = next(ninputs, inputs);
		
		// We ran out of inputs, and
		if(c == 'x')
		{
			if(!isFinalState(currState))
				goto error;
			// This should never happen, if our algo works well
			else
				break;
		}
		
		cout << "Next input word is " << c << ", current state is " << currState << endl;
		
		state = nextState(currState, c);
        
        setLed(state);
        waitFor(timeoutMs);

		
		// Check for errors
		if(state < 0)
			goto error;
		
		cout << "Next state will be " << state << endl;
		
		if(isFinalState(state))
			break;
		
		// Update curr state
		currState = state;
	}
	
	cout << "Input sequence is legal for our Language" << endl;
	return 0;

error:
	cout << "ERROR!" << endl;
	cout << "Input " << c << " not legal for state " << currState << endl;
	cout << "Error code is " << state << endl;
	return state;
}
