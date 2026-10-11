@echo off

echo ==========================
echo Next OS Build
echo ==========================

docker run --rm -v "%CD%:/workspace" os-dev make

if errorlevel 1 (
    echo.
    echo [BUILD FAILED]
    pause
    exit /b 1
)

echo.
echo ==========================
echo Starting QEMU
echo ==========================

qemu-system-x86_64 -cdrom build\next-os.iso -trace "ps2_write_keyboard" -trace "ps2_set_ledstate"

pause