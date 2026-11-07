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
      vga[cursor] = text[i] | (((bgcolor << 4) | txcolor) << 8);
      cursor++;
      vga_update_cursor();
    }
  } 

   // vga 처리, 문자
  void vga_print(char text, uint16 txcolor, uint16 bgcolor) //txcolor: 텍스트 색, bgcolor: 배경 색; 기본 값: txcolor = 0x7, bgcolor = 0x0
  {
      vga[cursor] = text | (((bgcolor << 4) | txcolor) << 8);
      cursor++;
      vga_update_cursor();
  } 

  // 키보드 처리
  void Keyboard_handling()
  {
    uint8 code = keyboard::keyboard_read();

    // Shift 키 상태 업데이트
    if(code == 0x2A)
    { 
        keyboard::left_shift_pressed = true;
    }
    else if(code == 0x36)
    {
        keyboard::right_shift_pressed = true;
    }
    else if(code == 0xAA)
    {
        keyboard::left_shift_pressed = false;
    }
    else if(code == 0xB6)
    {
        keyboard::right_shift_pressed = false;
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
            vga_update_cursor();
            return;
        }
    }

    // 엔터 처리
    if(code == 0x1C)
    {
        cursor = ((cursor / 80) + 1) * 80;
        vga_update_cursor();
        return;
    }   

    char key = keyboard::keyboard_key_table(code);

    if(key == 0)
    {
        return;
    }

    vga_print(key);
    }

    // VGA 하드웨어 커서 위치 갱신 함수
    // 아니, ai가 짜줬는데 못알아 먹겟어요!!ㅠㅠ
    void vga_update_cursor()
    {
        // VGA 커서 제어 레지스터 선택 포트(0x3D4)에 하위 8비트 선택 번호(0x0F) 전달
        keyboard::outb(0x3D4, 0x0F);

        // 현재 cursor 위치에서 하위 8비트만 추출하여 데이터 포트(0x3D5)에 전달
        keyboard::outb(0x3D5, cursor & 0xFF);

        // VGA 커서 제어 레지스터 선택 포트(0x3D4)에 상위 8비트 선택 번호(0x0E) 전달
        keyboard::outb(0x3D4, 0x0E);

        // 현재 cursor를 오른쪽으로 8비트 이동한 뒤 하위 8비트만 추출하여 전달
        keyboard::outb(0x3D5, (cursor >> 8) & 0xFF);
    }
}

