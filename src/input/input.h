#include "common/types.h"
#include "device/keyboard/keyboard.h"

namespace input
{
    void Keyboard_extended_handling(uint8 code);
    void Keyboard_handling();

    
    extern bool shift_pressed;
    extern bool ctrl_pressed;
    extern bool alt_pressed;
    extern bool caps_lock;
    extern bool num_lock;
    extern bool extended;
}