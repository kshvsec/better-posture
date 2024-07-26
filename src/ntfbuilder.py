import ctypes
import time
import sys
from ntfclass import NOTIFYICONDATA
    
NIF_INFO = 0x00000010
NIIF_INFO = 0x00000001
NIM_ADD = 0x00000000
NIM_MODIFY = 0x00000001

def show_notification(title, msg):
    nid = NOTIFYICONDATA()
    nid.cbSize = ctypes.sizeof(NOTIFYICONDATA)
    nid.uFlags = NIF_INFO
    nid.szInfo = msg.encode('utf-8')
    nid.szInfoTitle = title.encode('utf-8')
    nid.dwInfoFlags = NIIF_INFO

    shell32 = ctypes.windll.shell32
    shell32.Shell_NotifyIconA(NIM_ADD, ctypes.byref(nid))
    shell32.Shell_NotifyIconA(NIM_MODIFY, ctypes.byref(nid))

    # time.sleep(1)
    # time.sleep(5)

    time.sleep(10)

# show_notification("Notification Title", "This is a desktop notification!") # debug

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print(f"Usage: {sys.argv[0]} <title> <message>")
        sys.exit(1)
    
    title = sys.argv[1]
    message = sys.argv[2]
    show_notification(title, message)