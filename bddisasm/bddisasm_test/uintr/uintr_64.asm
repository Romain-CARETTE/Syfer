    bits 64
    
    db 0xf3, 0x0f, 0x01, 0xec           ; uiret
    db 0xf3, 0x0f, 0x01, 0xed           ; testui
    db 0xf3, 0x0f, 0x01, 0xee           ; clui
    db 0xf3, 0x0f, 0x01, 0xef           ; stui
    db 0xf3, 0x0f, 0xc7, 0xf1           ; senduipi rcx