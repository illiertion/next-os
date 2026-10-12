#include "keyboard.h"
#include "types.h"
#include "vga.h"
  
extern "C" void kernel_main()
{ 
  // 키보드 시작
  keyboard::keyboard_init();
  // hello from next os 출력
  while(true)
  {
    // 키보드 처리
    vga::Keyboard_handling();
  }
} // kernel_main

