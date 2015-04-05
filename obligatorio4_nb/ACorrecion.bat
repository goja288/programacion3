@echo off

IF EXIST tarea4.exe DEL tarea4.exe
IF EXIST Otros\tests\*.sal del Otros\tests\*.sal
IF EXIST Otros\tests\*.diff del Otros\tests\*.diff

rem set path=C:\MinGW\bin;C:\MinGW\include;C:\MinGW\lib;C:\msys\1.0\bin;C:\MinGW\mingw32\bin;C:\MinGW\mingw32\lib

make -f Makefile_tarea4

IF EXIST main.o DEL main.o
IF EXIST buscoamor.o DEL buscoamor.o
IF EXIST tarea4.o DEL tarea4.o

IF NOT EXIST tarea4.exe GOTO NOCOMPILA
cls

SET Correcion=(prueba1 prueba2 prueba3 prueba4 pruebaP1 pruebaP2 pruebaP3 pruebaP4 pruebaP5 pruebaP6 pruebaP7 pruebaP8 pruebaP9 pruebaN5 pruebaN6 pruebaN7 pruebaN8 pruebaN9 pruebaN10 pruebaN11 pruebaN12)
set Correctos = 0
set Incorrectos = 0
set TotalTests = 0

FOR %%I IN %Correcion% DO (
	TITLE SALIDAS Y DIFFS -                                     %%I
	tarea4 <Otros\tests\%%I.in> Otros\tests\%%I.sal
	diff Otros\tests\%%I.out Otros\tests\%%I.sal
	diff Otros\tests\%%I.out Otros\tests\%%I.sal > Otros\tests\%%I.diff
	IF NOT ERRORLEVEL 1 (
		del Otros\tests\%%I.diff Otros\tests\%%I.sal
		set /a Correctos+=1
	) ELSE (
	set /a Incorrectos+=1)
	pause
	cls
)

rem Búsqueda de SALIDAS INCORRECTAS
echo Listara las salidas incorrectas:
echo.
IF EXIST Otros\tests\*.diff (
cd Otros\tests\
dir /B *.diff 2>nul
)

rem Resumen del Testeo
Title Resumen del Testeo - SCRIPT Ale v%2
echo.
echo.
echo Tests Correctos: %Correctos%
echo.
echo Tests Incorrectos: %Incorrectos%
echo.
set /a TotalTests+=%Correctos%
set /a TotalTests+=%Incorrectos%
echo Total Tests: %TotalTests%
echo.
echo.
echo.
echo.
echo.
echo                         FIN de los TESTS DE CORRECION
echo.
echo.
echo.
echo.
pause
cls

GOTO FIN

:NOCOMPILA
cls
Title NO COMPILA
echo No compila
echo.
echo.
echo.
echo.
echo.
pause
GOTO FIN

:FIN

exit