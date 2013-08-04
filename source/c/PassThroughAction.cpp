#include <linux/uinput.h>

#include <iostream>

#include "PassThroughAction.h"
#include "Output.h"
#include "G13.h"

using namespace std;

PassThroughAction::PassThroughAction(G13 *device, int code, int code2) {
        this->device = device;
	this->keycode = code;
	this->keycode2 = code2;
}
PassThroughAction::PassThroughAction(G13 *device, int code) {
        this->device = device;
	this->keycode = code;
        this->keycode = 0;
}
PassThroughAction::~PassThroughAction() {

}

int PassThroughAction::getKeyCode() {
	return keycode;
}

void PassThroughAction::setKeyCode(int code) {
	this->keycode = code;
}

#define METAKEY 8

void PassThroughAction::key_down() {
    int code;

    //cout << "keys are " << keycode << ", "<<keycode2 << endl;
    if (!device->actions[METAKEY]->isPressed()) {
        code = keycode;
    }
    else {
        code = keycode2;
    }

    if (code) {
	send_event(EV_KEY, code, 1);
    }
}

void PassThroughAction::key_up() {
    send_event(EV_KEY, keycode, 0);
    send_event(EV_KEY, keycode2, 0);
}
