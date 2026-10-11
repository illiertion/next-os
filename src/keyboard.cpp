#include "keyboard.h"

namespace keyboard {

    bool num_lock = false;
    bool shift_pressed;
    bool ctrl_pressed;
    bool alt_pressed;
    bool caps_lock;
    bool extended;

    char numpad_table[256];
    char key_table[256];
    char upper_key_table[256];
    char upper_key_table_caps[256];

    void keyboard_init()
    {
        // key_table
        key_table[0x1E] = 'a';
        key_table[0x30] = 'b';
        key_table[0x2E] = 'c';
        key_table[0x20] = 'd';
        key_table[0x12] = 'e';
        key_table[0x21] = 'f';
        key_table[0x22] = 'g';
        key_table[0x23] = 'h';
        key_table[0x17] = 'i';
        key_table[0x24] = 'j';
        key_table[0x25] = 'k';
        key_table[0x26] = 'l';
        key_table[0x32] = 'm';
        key_table[0x31] = 'n';
        key_table[0x18] = 'o';
        key_table[0x19] = 'p';
        key_table[0x10] = 'q';
        key_table[0x13] = 'r';
        key_table[0x1F] = 's';
        key_table[0x14] = 't';
        key_table[0x16] = 'u';
        key_table[0x2F] = 'v';
        key_table[0x11] = 'w';
        key_table[0x2D] = 'x';
        key_table[0x15] = 'y';
        key_table[0x2C] = 'z';

        key_table[0x02] = '1';
        key_table[0x03] = '2';
        key_table[0x04] = '3';
        key_table[0x05] = '4';
        key_table[0x06] = '5';
        key_table[0x07] = '6';
        key_table[0x08] = '7';
        key_table[0x09] = '8';
        key_table[0x0A] = '9';
        key_table[0x0B] = '0';

        key_table[0x0C] = '-';
        key_table[0x0D] = '=';
        key_table[0x1A] = '[';
        key_table[0x1B] = ']';
        key_table[0x27] = ';';
        key_table[0x28] = '\'';
        key_table[0x2B] = '\\';
        key_table[0x33] = ',';
        key_table[0x34] = '.';
        key_table[0x35] = '/';
        key_table[0x29] = '`';
        key_table[0x39] = ' ';

        // numpad_table
        numpad_table[0x52] = '0';
        numpad_table[0x4F] = '1';
        numpad_table[0x50] = '2';
        numpad_table[0x51] = '3';
        numpad_table[0x4B] = '4';
        numpad_table[0x4C] = '5';
        numpad_table[0x4D] = '6';
        numpad_table[0x47] = '7';
        numpad_table[0x48] = '8';
        numpad_table[0x49] = '9';
        numpad_table[0x53] = '.';
        numpad_table[0x4E] = '+';
        numpad_table[0x4A] = '-';
        numpad_table[0x37] = '*';

        // upper_key_table
        upper_key_table[0x1E] = 'A';
        upper_key_table[0x30] = 'B';
        upper_key_table[0x2E] = 'C';
        upper_key_table[0x20] = 'D';
        upper_key_table[0x12] = 'E';
        upper_key_table[0x21] = 'F';
        upper_key_table[0x22] = 'G';
        upper_key_table[0x23] = 'H';
        upper_key_table[0x17] = 'I';
        upper_key_table[0x24] = 'J';
        upper_key_table[0x25] = 'K';
        upper_key_table[0x26] = 'L';
        upper_key_table[0x32] = 'M';
        upper_key_table[0x31] = 'N';
        upper_key_table[0x18] = 'O';
        upper_key_table[0x19] = 'P';
        upper_key_table[0x10] = 'Q';
        upper_key_table[0x13] = 'R';
        upper_key_table[0x1F] = 'S';
        upper_key_table[0x14] = 'T';
        upper_key_table[0x16] = 'U';
        upper_key_table[0x2F] = 'V';
        upper_key_table[0x11] = 'W';
        upper_key_table[0x2D] = 'X';
        upper_key_table[0x15] = 'Y';
        upper_key_table[0x2C] = 'Z';

        upper_key_table[0x02] = '!';
        upper_key_table[0x03] = '@';
        upper_key_table[0x04] = '#';
        upper_key_table[0x05] = '$';
        upper_key_table[0x06] = '%';
        upper_key_table[0x07] = '^';
        upper_key_table[0x08] = '&';
        upper_key_table[0x09] = '*';
        upper_key_table[0x0A] = '(';
        upper_key_table[0x0B] = ')';

        upper_key_table[0x0C] = '_';
        upper_key_table[0x0D] = '+';

        upper_key_table[0x1A] = '{';
        upper_key_table[0x1B] = '}';

        upper_key_table[0x27] = ':';
        upper_key_table[0x28] = '"';

        upper_key_table[0x2B] = '|';

        upper_key_table[0x33] = '<';
        upper_key_table[0x34] = '>';
        upper_key_table[0x35] = '?';

        upper_key_table[0x29] = '~';

        // upper_key_table_caps
        upper_key_table_caps[0x1E] = 'A';
        upper_key_table_caps[0x30] = 'B';
        upper_key_table_caps[0x2E] = 'C';
        upper_key_table_caps[0x20] = 'D';
        upper_key_table_caps[0x12] = 'E';
        upper_key_table_caps[0x21] = 'F';
        upper_key_table_caps[0x22] = 'G';
        upper_key_table_caps[0x23] = 'H';
        upper_key_table_caps[0x17] = 'I';
        upper_key_table_caps[0x24] = 'J';
        upper_key_table_caps[0x25] = 'K';
        upper_key_table_caps[0x26] = 'L';
        upper_key_table_caps[0x32] = 'M';
        upper_key_table_caps[0x31] = 'N';
        upper_key_table_caps[0x18] = 'O';
        upper_key_table_caps[0x19] = 'P';
        upper_key_table_caps[0x10] = 'Q';
        upper_key_table_caps[0x13] = 'R';
        upper_key_table_caps[0x1F] = 'S';
        upper_key_table_caps[0x14] = 'T';
        upper_key_table_caps[0x16] = 'U';
        upper_key_table_caps[0x2F] = 'V';
        upper_key_table_caps[0x11] = 'W';
        upper_key_table_caps[0x2D] = 'X';
        upper_key_table_caps[0x15] = 'Y';
        upper_key_table_caps[0x2C] = 'Z';

        
        // 처음에는 Num Lock OFF
        keyboard::num_lock = false;
        keyboard::keyboard_set_leds();
    }

    uint8 inb(uint16 port)
    {
        uint8 result;

        asm volatile (
            "inb %1, %0"
            : "=a"(result)
            : "d"(port)
        );

        return result;
    }

    void outb(uint16 port, uint8 value)
    {
        asm volatile (
            "outb %0, %1"
            :
            : "a"(value), "d"(port)
        );
    }

    uint8 keyboard_read()
    {
        while(true)
        {
            if(inb(0x64) & 1)
            {
                
                return inb(0x60);
            }
        }
    }

    char keyboard_key_table(uint8 key)
    {
        // 넘패드 처리
        char key_ = numpad_table[key];

        if(num_lock && key_ != 0)
        {
            return key_;
        }

        if(!num_lock && key_ != 0)
        {
            return 0;
        }

        // 문자 처리
        key_ = key_table[key];

        if(key_ >= 'a' && key_ <= 'z')
        {
            // 문자 처리
            if(caps_lock)
            {
                if(shift_pressed)
                {
                    return key_;
                }
                else
                {
                    return upper_key_table_caps[key];
                }
            }
            else
            {
                if(shift_pressed)
                {
                    return upper_key_table[key];
                }
                else
                {
                    return key_;
                }
            }
        }
        else
        {
            // 숫자 / 기호 → Shift만 처리
            if(shift_pressed)
            {
                return upper_key_table[key];
            }
            else
            {
                return key_;
            }
        }
    }

    void keyboard_set_leds()
    {
        uint8 response;
        uint8 led = 0;

        // 키보드 입력 버퍼가 비워질 때까지 대기
        while(inb(0x64) & 2)
        {
        }

        // LED 설정 명령
        outb(0x60, 0xED);

        // 키보드의 ACK(0xFA) 대기
        while(true)
        {
            if(inb(0x64) & 1)
            {
                response = inb(0x60);

                // 명령을 정상적으로 받음
                if(response == 0xFA)
                {
                    break;
                }

                // RESEND(0xFE)를 받으면 명령 다시 전송
                if(response == 0xFE)
                {
                    while(inb(0x64) & 2)
                    {
                    }

                    outb(0x60, 0xED);
                }
            }
        }

        // 다시 키보드 입력 버퍼가 비워질 때까지 대기
        while(inb(0x64) & 2)
        {
        }

        // LED 상태 설정
        if(num_lock)
        {
            led |= 0x02;
        }

        if(caps_lock)
        {
            led |= 0x04;
        }

        outb(0x60, led);

        // LED 데이터에 대한 ACK 대기
        while(true)
        {
            if(inb(0x64) & 1)
            {
                response = inb(0x60);

                // 정상 처리
                if(response == 0xFA)
                {
                    break;
                }

                // RESEND가 오면 LED 데이터 다시 전송
                if(response == 0xFE)
                {
                    while(inb(0x64) & 2)
                    {
                    }

                    outb(0x60, led);
                }
            }
        }
    }
} // namespace keyboard
