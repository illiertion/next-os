#pragma once
#include "types.h"
#include "vga.h"

namespace keyboard {
  void keyboard_init();
  uint8 inb(uint16 port);
  void outb(uint16 port, uint8 value);
  uint8 keyboard_read();
  char keyboard_key_table(uint8 key);
  void keyboard_set_leds();

  extern bool shift_pressed;
  extern bool ctrl_pressed;
  extern  bool alt_pressed;
  extern bool caps_lock;
  extern bool num_lock;
  extern bool extended;
}
