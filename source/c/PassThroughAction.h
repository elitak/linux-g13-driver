
#ifndef __PASS_THROUGH_ACTION_H__
#define __PASS_THROUGH_ACTION_H__

#include "G13Action.h"

class G13;

class PassThroughAction : public G13Action {
private:
	int keycode;
        int keycode2;
        G13 *device;

protected:
	virtual void key_down();
	virtual void key_up();

public:
	PassThroughAction(G13 *device, int code);
	PassThroughAction(G13 *device, int code, int code2);
	virtual ~PassThroughAction();

	int getKeyCode();
	void setKeyCode(int code);
};

#endif
