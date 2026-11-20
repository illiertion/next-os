#pragma once
#include "common/types.h"
#include "kernel/vga/vga.h"

namespace keyboard {
  void keyboard_init();
  uint8 inb(uint16 port);
  void outb(uint16 port, uint8 value);
  uint8 keyboard_read();
  char keyboard_key_table(uint8 key);
  void keyboard_set_leds();

}
