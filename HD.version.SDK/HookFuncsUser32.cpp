#include <windows.h>
#include "HookFuncs.h"

void HookFuncsUser32() {
	PROC pfnOrig;
}


/*
Åù : [<&USER32.AdjustWindowRectEx>]     USER32.AdjustWindowRectEx
Åù : [<&USER32.BeginPaint>]             USER32.BeginPaint
CALL DWORD PTR DS : [<&USER32.CallWindowProcA>]        USER32.CallWindowProcA
CALL DWORD PTR DS : [<&USER32.CharNextA>]              USER32.CharNextA
CALL DWORD PTR DS : [<&USER32.CheckMenuItem>]          USER32.CheckMenuItem
CALL DWORD PTR DS : [<&USER32.ClientToScreen>]         USER32.ClientToScreen
CALL DWORD PTR DS : [<&USER32.CopyRect>]               USER32.CopyRect
CALL DWORD PTR DS : [<&USER32.CreateWindowExA>]        USER32.CreateWindowExA
CALL DWORD PTR DS : [<&USER32.EnableMenuItem>]         USER32.EnableMenuItem
CALL DWORD PTR DS : [<&USER32.EndDialog>]              USER32.EndDialog
CALL DWORD PTR DS : [<&USER32.EndPaint>]               USER32.EndPaint
CALL DWORD PTR DS : [<&USER32.EnumDisplaySettingsA>]   USER32.EnumDisplaySettingsA
CALL DWORD PTR DS : [<&USER32.DestroyMenu>]            USER32.DestroyMenu
CALL DWORD PTR DS : [<&USER32.DestroyWindow>]          USER32.DestroyWindow
CALL DWORD PTR DS : [<&USER32.GetActiveWindow>]        USER32.GetActiveWindow
CALL DWORD PTR DS : [<&USER32.GetClientRect>]          USER32.GetClientRect
CALL DWORD PTR DS : [<&USER32.GetDC>]                  USER32.GetDC
CALL DWORD PTR DS : [<&USER32.EqualRect>]              USER32.EqualRect
CALL DWORD PTR DS : [<&USER32.FindWindowA>]            USER32.FindWindowA
CALL DWORD PTR DS : [<&USER32.GetDoubleClickTime>]     USER32.GetDoubleClickTime
CALL DWORD PTR DS : [<&USER32.GetForegroundWindow>]    USER32.GetForegroundWindow
CALL DWORD PTR DS : [<&USER32.GetIconInfo>]            USER32.GetIconInfo
CALL DWORD PTR DS : [<&USER32.GetLastActivePopup>]     USER32.GetLastActivePopup
CALL DWORD PTR DS : [<&USER32.GetMenu>]                USER32.GetMenu
CALL DWORD PTR DS : [<&USER32.GetMenuItemCount>]       USER32.GetMenuItemCount
CALL DWORD PTR DS : [<&USER32.GetMenuItemID>]          USER32.GetMenuItemID
CALL DWORD PTR DS : [<&USER32.GetMonitorInfoA>]        USER32.GetMonitorInfoA
CALL DWORD PTR DS : [<&USER32.GetParent>]              USER32.GetParent
CALL DWORD PTR DS : [<&USER32.GetQueueStatus>]         USER32.GetQueueStatus
CALL DWORD PTR DS : [<&USER32.GetSystemMenu>]          USER32.GetSystemMenu
CALL DWORD PTR DS : [<&USER32.GetSystemMetrics>]       USER32.GetSystemMetrics
CALL DWORD PTR DS : [<&USER32.GetWindowLongA>]         USER32.GetWindowLongA
CALL DWORD PTR DS : [<&USER32.GetWindowPlacement>]     USER32.GetWindowPlacement
CALL DWORD PTR DS : [<&USER32.GetWindowRect>]          USER32.GetWindowRect
CALL DWORD PTR DS : [<&USER32.InflateRect>]            USER32.InflateRect
CALL DWORD PTR DS : [<&USER32.IsIconic>]               USER32.IsIconic
CALL DWORD PTR DS : [<&USER32.IsRectEmpty>]            USER32.IsRectEmpty
CALL DWORD PTR DS : [<&USER32.keybd_event>]            USER32.keybd_event
CALL DWORD PTR DS : [<&USER32.LoadCursorA>]            USER32.LoadCursorA
CALL DWORD PTR DS : [<&USER32.LoadIconA>]              USER32.LoadIconA
CALL DWORD PTR DS : [<&USER32.LoadImageA>]             USER32.LoadImageA
CALL DWORD PTR DS : [<&USER32.LoadStringA>]            USER32.LoadStringA
CALL DWORD PTR DS : [<&USER32.MapVirtualKeyA>]         USER32.MapVirtualKeyA
CALL DWORD PTR DS : [<&USER32.MsgWaitForMultipleObjec  USER32.MsgWaitForMultipleObjects
CALL DWORD PTR DS : [<&USER32.PostMessageA>]           USER32.PostMessageA
CALL DWORD PTR DS : [<&USER32.PostQuitMessage>]        USER32.PostQuitMessage
CALL DWORD PTR DS : [<&USER32.PostThreadMessageA>]     USER32.PostThreadMessageA
CALL DWORD PTR DS : [<&USER32.PtInRect>]               USER32.PtInRect
CALL DWORD PTR DS : [<&USER32.RegisterClassExA>]       USER32.RegisterClassExA
CALL DWORD PTR DS : [<&USER32.RegisterWindowMessageA>  USER32.RegisterWindowMessageA
CALL DWORD PTR DS : [<&USER32.ReleaseDC>]              USER32.ReleaseDC
CALL DWORD PTR DS : [<&USER32.SetWindowLongA>]         USER32.SetWindowLongA
CALL DWORD PTR DS : [<&USER32.SetWindowPlacement>]     USER32.SetWindowPlacement
CALL DWORD PTR DS : [<&USER32.SetWindowPos>]           USER32.SetWindowPos
CALL DWORD PTR DS : [<&USER32.ScreenToClient>]         USER32.ScreenToClient
CALL DWORD PTR DS : [<&USER32.SendMessageA>]           USER32.SendMessageA
CALL DWORD PTR DS : [<&USER32.SetActiveWindow>]        USER32.SetActiveWindow
CALL DWORD PTR DS : [<&USER32.SetFocus>]               USER32.SetFocus
CALL DWORD PTR DS : [<&USER32.SetForegroundWindow>]    USER32.SetForegroundWindow
CALL DWORD PTR DS : [<&USER32.SetRect>]                USER32.SetRect
CALL DWORD PTR DS : [<&USER32.SetRectEmpty>]           USER32.SetRectEmpty
CALL DWORD PTR DS : [<&USER32.SetScrollInfo>]          USER32.SetScrollInfo
CALL DWORD PTR DS : [<&USER32.ShowWindow>]             USER32.ShowWindow
CALL DWORD PTR DS : [<&USER32.SubtractRect>]           USER32.SubtractRect
CALL DWORD PTR DS : [<&USER32.SystemParametersInfoA>]  USER32.SystemParametersInfoA
CALL DWORD PTR DS : [<&USER32.TrackPopupMenu>]         USER32.TrackPopupMenu
CALL DWORD PTR DS : [<&USER32.TranslateMessage>]       USER32.TranslateMessage
CALL DWORD PTR DS : [<&USER32.UnionRect>]              USER32.UnionRect
CALL DWORD PTR DS : [<&USER32.UpdateWindow>]           USER32.UpdateWindow
CALL DWORD PTR DS : [<&USER32.DefWindowProcA>]         USER32.77232240
CALL DWORD PTR DS : [<&USER32.DispatchMessageA>]       gameover.5CD0DF40
CALL DWORD PTR DS : [<&USER32.GetAsyncKeyState>]      gameover.5CD0E000
CALL DWORD PTR DS : [<&USER32.GetCursorPos>]           gameover.5CD0E090
CALL DWORD PTR DS : [<&USER32.GetKeyState>]            gameover.5CD0E0D0
CALL DWORD PTR DS : [<&USER32.GetKeyboardState>]       gameover.5CD0E110
CALL DWORD PTR DS : [<&USER32.PeekMessageA>]           gameover.5CD0E260
CALL DWORD PTR DS : [<&USER32.SetCursor>]              gameover.5CD0E350
CALL DWORD PTR DS : [<&USER32.SetCursorPos>]           gameover.5CD0E380

*/