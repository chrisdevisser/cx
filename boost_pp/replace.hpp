REM for /r %%i in (*) do ("C:\Program Files (x86)\GnuWin32\bin\sed" -re "s/#(.*?)<boost\/preprocessor\/(.*?)>/#\1\"\2\"/g" %%i > %%i2)
for /r %%i in (*) do (
cd %%~dpi
ren %%~nxi %%~ni.hpp
)