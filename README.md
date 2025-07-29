# 🪟 Mini Shell - Terminal Emulator (Windows Version)

A lightweight Windows-compatible shell built in C++, demonstrating systems programming concepts using the Windows API. This project simulates a basic terminal interface where users can run common Windows commands like `dir`, `echo`, and `ping`.

---

## 📌 Features

- 🖥️ Execute native Windows commands (via `cmd /C`)
- ⚙️ Process creation using `CreateProcess()`
- 🧵 Child process handling with `WaitForSingleObject()`
- 📄 Input parsing for arguments
- 🚪 Built-in `exit` command to quit the shell

---

## ⚙️ How It Works

1. Displays a command prompt: `myshell>`.
2. Accepts user input (e.g., `dir`, `echo Hello`).
3. Constructs a Windows command line: `cmd /C <command>`.
4. Uses `CreateProcess()` to spawn a new process.
5. Waits for the process to complete before resuming.

---

## 🧪 Sample Output

```shell
myshell> echo Hello from Mini Shell!
Hello from Mini Shell!

myshell> dir
 Volume in drive C has no label.
 Volume Serial Number is XXXX-XXXX
 Directory of C:\Users\YourName

myshell> ping google.com
Pinging google.com [x.x.x.x] with 32 bytes of data:
...

myshell> exit
