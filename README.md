# Windows Taskbar Progress bar
## Overview
Add progress bar in Windows Taskbar icon using Windows API's Taskbar Extensions for Windows 7 and later. This is a DLL (Dynamic Link Library) which can be used by older languages, for example, Visual Basic 6 etc. Programs that cannot directly access Taskbar extensions, for example, Excel's VBA etc. This DLL can also be used by high level languages, for example, Python; or other scripting languages like VBScript or PowerShell Script etc.

## Exported Functions
* `LONG WINAPI About()`
* `LONG WINAPI TaskbarInitialize()`
* `LONG WINAPI TaskbarRelease()`
* `LONG WINAPI TaskbarNoProgressbar(HWND hWindow)`
* `LONG WINAPI TaskbarIndeterminateProgressbar(HWND hWindow)`
* `LONG WINAPI TaskbarNormalProgressbar(HWND hWindow)`
* `LONG WINAPI TaskbarErrorProgressbar(HWND hWindow)`
* `LONG WINAPI TaskbarPauseProgressbar(HWND hWindow)`
* `LONG WINAPI TaskbarSetProgressValue(HWND hWindow, LONG lCompleted, LONG lTotal)`

>[!NOTE]
>All functions return boolean value of `TRUE` or `FALSE`.

## License
Copyright © Farhan Ali Qureshi. All rights reserved. Please see the [LGPL-2.1 License](LICENSE) file for details.
