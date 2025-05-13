# MaxLaunch

MaxLaunch is a utility designed to launch Windows executables in a maximized window. It automatically adjusts the executable name by replacing `.max.exe` with `.exe` and ensures the application starts in a maximized window state. For example, renaming the utility to `notepad.max.exe` will launch `notepad.exe` in a maximized window.

## Features

- **Automatic Window Maximization**: Launches the target executable in a maximized window.
- **Executable Name Adjustment**: Automatically adjusts the executable name by replacing `.max.exe` with `.exe`.
- **Command Line Arguments Support**: Passes command line arguments to the target executable. If you don't need this, you can simply use a `.lnk` (shortcut) file to achieve similar functionality without command line support.
