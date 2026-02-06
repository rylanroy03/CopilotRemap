# CopilotRemap
<p align="center">
  <img src="icon/CopilotRemap.ico" width="64" height="64" alt="CopilotRemap Logo">
</p>
A utility to remap the hardware Copilot key (Win + Left Shift + F23) to Right Control.

## Overview
This program uses a low-level keyboard hook to intercept F23 signals and inject Right Control inputs. It is designed to run silently in the background via Task Scheduler.

* **Binary Size:** ~42KB
* **Memory Usage:** ~500KB
* **CPU Usage:** Negligible

## Installation

### Installer
Run the compiled Inno Setup installer `CopilotRemapInstaller.exe`. It will:
1. Install the executable to Program Files.
2. Create a Task Scheduler task to launch hidden at logon with high privileges.
3. Start the process immediately.

### Manual
1. Download `CopilotRemap.exe`. Alternatively, compile it yourself.
2. Create a task in Windows Task Scheduler set to "At log on" with "Highest privileges" targeting the executable.

## Build Instructions

### Requirements
* MSVC (cl.exe) **or** Code Runner VSCode Extension
* Inno Setup (for the installer)

### Steps
1. **Executable:** Build using the provided `.vscode/tasks.json`. It uses `/O1` and `/GS-` to minimize the binary footprint and skips standard CRT bloat via `/ENTRY:mainCRTStartup`.
2. **Installer:** Compile `setup.iss` in Inno Setup. Ensure the icon is located in the `./icon/` directory.

## Removal
Uninstall via Windows Settings. The uninstaller terminates the process and deletes the scheduled task before removing files.

If you installed manually, uninstallation is as simple as deleting the task and executable.

---
Calvindustries