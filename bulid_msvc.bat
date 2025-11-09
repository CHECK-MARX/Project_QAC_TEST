@echo off
setlocal

rem --- load VS env (edit one that exists) ---
if exist "%ProgramFiles(x86)%\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars32.bat" (
  call "%ProgramFiles(x86)%\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvars32.bat"
) else if exist "%ProgramFiles(x86)%\Microsoft Visual Studio\2019\BuildTools\VC\Auxiliary\Build\vcvars32.bat" (
  call "%ProgramFiles(x86)%\Microsoft Visual Studio\2019\BuildTools\VC\Auxiliary\Build\vcvars32.bat"
) else (
  echo vcvars32.bat not found
  exit /b 1
)

where cl || exit /b 1

rem --- compile only; show includes for QAC sync ---
cl /nologo /utf-8 /TC /c /W3 /MD /Zi /showIncludes qac_gui_sample.c
exit /b %ERRORLEVEL%
