@echo off

echo ==========================
echo Building with MinGW (UTF-8)...
echo ==========================

REM 设置编译器（如果 g++ 不在 PATH，可以写完整路径）
set CXX=g++

REM 编译参数
REM -finput-charset=UTF-8   源文件按 UTF-8 读取
REM -fexec-charset=UTF-8    程序内部字符编码
REM -std=c++17              使用 C++17
REM -Wall -Wextra           警告信息
%CXX% main.cpp -o student_app.exe ^
    -std=c++17 ^
    -finput-charset=UTF-8 ^
    -fexec-charset=UTF-8 ^
    -Wall -Wextra

if %errorlevel% neq 0 (
    echo.
    echo [ERROR] 编译失败！
    pause
    exit /b
)

echo.
echo Build success!
echo ==========================

pause