# CopilotRemap
<p align="center">
  <img src="icon/CopilotRemap.ico" width="64" height="64" alt="CopilotRemap Logo">
</p>
A utility to remap the hardware Copilot key (Win + Left Shift + F23) to Right Control.

## Overview
This program uses the windows keyboard hook to intercept F23 and inject Right Ctrl. It runs silently in the background as a service.

* **Binary Size:** ~42KB
* **Memory Usage:** ~500KB
* **CPU Usage:** Negligible

## Installation

### Installer
Run the compiled Inno Setup installer `CopilotRemapInstaller.exe`. It will:
1. Install the executable to AppData/Program Files (for user only/for all users).
2. Adds a registry entry to HKCU/KHLM (user/all).
3. Start the process immediately (optional).

### Manual
1. Download `CopilotRemap.exe`. Alternatively, compile it yourself.
2. Configure for unassisted launch for executable using preferred method.

## Build Instructions

### Requirements
* MSVC (cl.exe) **or** Code Runner VSCode Extension
* Inno Setup (for the installer)

### Steps
1. **Executable:** Build using the provided `.vscode/tasks.json`.
2. **Installer:** Compile `setup.iss` in Inno Setup.

## Removal
Uninstall via Windows Settings. The uninstaller removes all files and registry entries.

If you installed manually, uninstallation is as simple as deleting your autolaunch and the exe.

---
Calvindustries