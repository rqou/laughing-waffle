typedef volatile unsigned char vu8;
typedef volatile unsigned short vu16;

void delay() {
    for (volatile int i = 0; i < 32; i++) { }
}

void start_c() {
    *((vu16*)0x0A000000) = 0x55;

    *((vu16*)0x0A000004) = 2;

    for (int i = 0; i < 0x1000000; i++) {
        *((vu16*)0x0A000002) = *((vu8*)i);
        delay();
    }

    while (1) {}

    // // IO port
    // *((vu16*)0x050001CC) = 0xA;

    // // Baud (38400)
    // *((vu8*)0x050000C1) = 9;
    // // Mode
    // *((vu8*)0x050000C0) = 0;
    // // Control
    // *((vu8*)0x050000C2) = 0x30;
    // while (1) {
    //     // while (((*((vu8*)0x050000C4)) & 0x80) == 0) {}
    //     // *((vu8*)0x050000C3) = 0x55;
    // }
}
