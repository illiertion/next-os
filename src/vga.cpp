#include "vga.h"

namespace vga {
  //<변수 선언>
  uint16* vga = (uint16*)0xB8000;
  uint16 cursor = 0;
  uint16& cursor_r = cursor;


  //<함수 구현부>

  // vga 처리, 문자열
  void vga_print(const char* text, uint16 txcolor, uint16 bgcolor) //txcolor: 텍스트 색, bgcolor: 배경 색; 기본 값: txcolor = 0x7, bgcolor = 0x0
  {
    // 텍스트의 길이 값
    uint16 length = 0;

    while (text[length] != '\0')
    {
        length++;
    }

    //vga에 쓰기
    for (uint32 i = 0; i < length; i++)
    {
      vga[cursor] = (text[i] | (bgcolor | txcolor << 8));
      cursor++;
    }
  } 

   // vga 처리, 문자
  void vga_print(char text, uint16 txcolor, uint16 bgcolor) //txcolor: 텍스트 색, bgcolor: 배경 색; 기본 값: txcolor = 0x7, bgcolor = 0x0
  {
      vga[cursor] = (text | (bgcolor | txcolor << 8));
      cursor++;
  } 

  // 키보드 처리
  void Keyboard_handling()
  {
    uint8 code = keyboard::keyboard_read();

    // Shift 키 상태 업데이트
    if(code == 0x36 || code == 0x2A)
    {
        keyboard::shift_pressed = true;
        return;
    }
    else if(code == 0xB6 || code == 0xAA)
    {
        keyboard::shift_pressed = false;
        return;
    }

    // caps 키 상태 업데이트
    if(code == 0x3A)
    {
        keyboard::caps_lock = !keyboard::caps_lock;
        keyboard::keyboard_set_leds();
        return;
    }
    
    // Num Lock 상태 업데이트
    if(code == 0x45)
    {
        keyboard::num_lock = !keyboard::num_lock;
        keyboard::keyboard_set_leds();
        return;
    }

    // 키를 뗀 경우
    if(code & 0x80)
    {
        return;
    }

    // 백스페이스 처리
    if(code == 0x0E)
    {
        if(cursor > 0)
        {
            cursor--;
            vga_print(' ');
            cursor--;
            return;
        }
    }

    char key = keyboard::keyboard_key_table(code);

    if(key == 0)
    {
        return;
    }

    vga_print(key);
    }
}

