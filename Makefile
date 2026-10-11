CXX = x86_64-elf-g++
ASM = nasm
LD = x86_64-elf-ld

CXXFLAGS = -ffreestanding -mno-red-zone -c

CPP_SOURCES := $(wildcard src/*.cpp)
ASM_SOURCES := $(wildcard src/*.asm)

CPP_OBJECTS := $(CPP_SOURCES:src/%.cpp=build/%.o)
ASM_OBJECTS := $(ASM_SOURCES:src/%.asm=build/%.o)

OBJECTS := $(CPP_OBJECTS) $(ASM_OBJECTS)

ISO = build/next-os.iso

all: clean $(ISO)

# build 폴더 자동 생성
build:
	mkdir -p build

build/%.o: src/%.cpp | build
	$(CXX) $(CXXFLAGS) $< -o $@

build/%.o: src/%.asm | build
	$(ASM) -f elf64 $< -o $@

build/kernel.elf: $(OBJECTS) src/linker.ld
	$(LD) -T src/linker.ld -o $@ $(OBJECTS)

$(ISO): build/kernel.elf grub.cfg
	mkdir -p build/isodir/boot/grub
	cp build/kernel.elf build/isodir/boot/kernel.elf
	cp grub.cfg build/isodir/boot/grub/grub.cfg
	grub-mkrescue -o $(ISO) build/isodir

clean:
	rm -rf build