#include "input.h"

namespace input
{    
    // 키보드 상태 변수
    bool num_lock = false;
    bool left_shift_pressed = false;
    bool right_shift_pressed = false;
    bool ctrl_pressed = false;
    bool alt_pressed = false;
    bool caps_lock = false;
    bool extended = false;
    bool shift_pressed = false;

    void set_shift_pressed()
    {
        if(left_shift_pressed || right_shift_pressed)
        {
            shift_pressed = true;
        }
        else
        {
            shift_pressed = false;
        }

    }


    // 키보드 E0 확장키 처리
    void Keyboard_extended_handling(uint8 code)
    {
        // 딜리트 처리
        if(code == 0x53)
        {
            if(vga::cursor_r >= 80 * 25)
            {
                return; 
            }
            for(uint16 i = vga::cursor_r; i < 80 * 25 - 1; i++)
            {
                vga::vga[i] = vga::vga[i + 1];
            }

            vga::vga[80 * 25 - 1] = ' ' | (0x07 << 8); // 마지막 줄을 공백으로 채움
            vga::vga_update_cursor();
            return;
        }
    }


    // 키보드 처리
    void Keyboard_handling()
    {
        uint8 code = keyboard::keyboard_read();

        //E0 확장키 처리
        if(code == 0xE0)
        {
            extended = true;
        }

        if(extended)
        {
            input::Keyboard_extended_handling(code);
            extended = false;
            return;
        }

        // left Shift 키 상태 업데이트
        if(code == 0x2A)
        { 
            left_shift_pressed = true;
            set_shift_pressed();
        }
        else if(code == 0xAA)
        {
            left_shift_pressed = false;
            set_shift_pressed();
        }

        // right Shift 키 상태 업데이트
        if(code == 0x36)
        {
            right_shift_pressed = true;
            set_shift_pressed();
        }
        
        else if(code == 0xB6)
        {
            right_shift_pressed = false;
            set_shift_pressed();
        }

        // caps 키 상태 업데이트
        if(code == 0x3A)
        {
            caps_lock = !caps_lock;
            keyboard::keyboard_set_leds();
            return;
        }

        // Num Lock 상태 업데이트
        if(code == 0x45)
        {
            num_lock = !num_lock;
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
            if(vga::cursor_r > 0)
            {
                vga::cursor_r--;
                vga::vga_print(' ');
                vga::cursor_r--;
                vga::vga_update_cursor();
                return;
            }
        }

        // 엔터 처리
        if(code == 0x1C)
        {
            vga::cursor_r = ((vga::cursor_r / 80) + 1) * 80;
            vga::vga_update_cursor();
            return;
        }

        // 탭 처리
        if(code == 0x0F)
        {
            vga::vga_print("    ");
            return;
        }

        char key = keyboard::keyboard_key_table(code);

        if(key == 0)
        {
            return;
        }

        vga::vga_print(key);
    }
}