ENTRY(_start) /* 시작점을 _start로 지정 */

SECTIONS /* 섹션 정의 */
{
  .multiboot :
  {
    *(.multiboot*) /* 모든 입력 .multiboot section을 출력 .multiboot 넣음 */
  }
  .text :
  {
    *(.text*) /* 모든 입력 .text section을 출력 .text에 넣음 */
  }

  .rodata :
  {
    *(.rodata*) /* 모든 입력 .rodata section을 출력 .rodata에 넣음 */
  }

  .bss :
  {
    *(.bss*) /* 모든 입력 .bss section을 출력 .bss에 넣음 */
  }
}
