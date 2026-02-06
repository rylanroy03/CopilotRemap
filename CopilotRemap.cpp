#include <windows.h>
#pragma comment(lib, "user32.lib")

// Virtual-key codes used by this hook
constexpr WORD VK_F23_KEY = 0x86;       // F23 key
constexpr WORD VK_LWIN_KEY   = 0x5B;    // Left Windows key
constexpr WORD VK_LSHIFT_KEY = 0xA0;    // Left Shift key
constexpr WORD VK_RCTRL_KEY  = 0xA3;    // Right Control key

// Keyboard hook function to intercept key events
LRESULT CALLBACK KeyboardHookProc(int hookCode, WPARAM msg, LPARAM lParam) {
    KBDLLHOOKSTRUCT *kbd = (KBDLLHOOKSTRUCT *)lParam;

    if (hookCode == HC_ACTION && kbd->vkCode == VK_F23_KEY && !(kbd->flags & 0x10)) 
        {
        bool isKeyDown = (msg == 0x0100 || msg == 0x0104);
        INPUT inputs[3] = {{1},{1},{1}};

        if (isKeyDown) {
            inputs[0].ki.wVk = VK_LWIN_KEY;   inputs[0].ki.dwFlags = 2;
            inputs[1].ki.wVk = VK_LSHIFT_KEY; inputs[1].ki.dwFlags = 2;
            inputs[2].ki.wVk = VK_RCTRL_KEY;
            SendInput(3, inputs, sizeof(INPUT));
        } else {
            inputs[0].ki.wVk = VK_RCTRL_KEY;  inputs[0].ki.dwFlags = 2;
            SendInput(1, inputs, sizeof(INPUT));
        }
        return 1;
    }

    return CallNextHookEx(0, hookCode, msg, lParam);
}

int main() {
    SetWindowsHookEx(13, KeyboardHookProc, 0, 0);
    MSG message;
    while (GetMessage(&message, 0, 0, 0));
    return 0;
}
