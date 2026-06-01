@echo off
gcc main.c bfs.c dijkstra.c -o main.exe

if %errorlevel% neq 0 (
    echo.
    echo ERRO NA COMPILACAO!
    pause
    exit
)

echo.
echo COMPILACAO CONCLUIDA!
echo.

main.exe

pause
