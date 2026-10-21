#pragma once
#include "types.h"
#include "keyboard.h"

namespace vga {
  //<변수 선언>
  extern uint16* vga;
  extern uint16& cursor_r;

  //<함수 선언>
  void vga_print(const char* text, uint16 txcolor = 0x7, uint16 bgcolor = 0x0); // 문자열 처리
  void vga_print(char text, uint16 txcolor = 0x7, uint16 bgcolor = 0x0); // 문자 처리
  void Keyboard_handling();
  void vga_update_cursor();
}
