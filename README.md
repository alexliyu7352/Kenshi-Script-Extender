# KenshiScriptExtender
A library for function hooking and script extending in Kenshi.

# BEWARE!!! 
This project has not been beautified or optimised past the testing stage at all 
and needs a huge cleanup before I declare it totally acceptable.

# Adding Hooks
If you want to add any new hooks, create them in "function_address.h" and write your hook functions in "hook_functions.h".
Apply them before "startKSEThread" is ran for safety and to avoid crashing.

# Installing KSE
To install KSE run "KSE Installer.exe", (make sure the "KSE_x64.dll" is in the same directory as the installer), and click install. Select your "kenshi_x64.exe" in the Kenshi directory and then its done! To uninstall follow the same instructions except click uninstall.
