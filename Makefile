
CXX = x86_64-elf-g++
ASM = nasm
LD = x86_64-elf-ld

# Find header directories(헤더 검색 경로 탐색)
INCLUDE_DIRS := $(shell find src -type d) .

# Compiler flags(컴파일 옵션)
CXXFLAGS = -ffreestanding -mno-red-zone -c $(addprefix -I,$(INCLUDE_DIRS))
ASMFLAGS = -f elf64

LINKER_SCRIPT = src/kernel/boot/linker.ld

ISO = build/next-os.iso


# Find all source files recursively(모든 하위 폴더 탐색)
CPP_SOURCES := $(shell find src -type f -name '*.cpp')
ASM_SOURCES := $(shell find src -type f -name '*.asm')

# Generate object file paths(오브젝트 파일 경로 생성)
CPP_OBJECTS := $(patsubst src/%.cpp,build/%.o,$(CPP_SOURCES))
ASM_OBJECTS := $(patsubst src/%.asm,build/%.o,$(ASM_SOURCES))

OBJECTS := $(CPP_OBJECTS) $(ASM_OBJECTS)


# Default target(기본 빌드)
.PHONY: all clean

all:
	$(MAKE) clean
	$(MAKE) $(ISO)


# Create build directory(빌드 폴더 생성)
build:
	mkdir -p build


# Compile C++ files(C++ 파일 컴파일)
build/%.o: src/%.cpp | build
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $< -o $@


# Compile Assembly files(어셈블리 파일 컴파일)
build/%.o: src/%.asm | build
	mkdir -p $(dir $@)
	$(ASM) $(ASMFLAGS) $< -o $@


# Link kernel(커널 링크)
build/kernel.elf: $(OBJECTS) $(LINKER_SCRIPT) | build
	@if [ -z "$(strip $(OBJECTS))" ]; then \
		echo "Error: No source files found in src/"; \
		exit 1; \
	fi
	$(LD) -T $(LINKER_SCRIPT) -o $@ $(OBJECTS)


# Create ISO image(ISO 이미지 생성)
$(ISO): build/kernel.elf grub.cfg
	mkdir -p build/isodir/boot/grub
	cp build/kernel.elf build/isodir/boot/kernel.elf
	cp grub.cfg build/isodir/boot/grub/grub.cfg
	grub-mkrescue -o $(ISO) build/isodir


# Clean build files(빌드 파일 삭제)
clean:
	rm -rf build
