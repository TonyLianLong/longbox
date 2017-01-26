//
//  box-main.h
//  longbox
//
//  Created by Tony on 16/9/16.
//  Copyright © 2016年 Tonylianlong. All rights reserved.
//

#ifndef box_main_h
#define box_main_h
#include <stdio.h>
#include <string.h>
struct PixelData {
    uint8_t a;
    uint8_t r;
    uint8_t g;
    uint8_t b;
};
extern char *documentPath;
extern char *bundlePath;
//Accessable after box_main set the pointer
extern void ios_screen_display(uint8_t *screendata,unsigned long cursor_x,unsigned long cursor_y);
extern int box_main(char *document, char *bundle);
extern void sendKey(uint8_t keyType,uint8_t key);
extern void (^updateScreen)(struct PixelData*,uint32_t,uint32_t);
#endif /* box_main_h */
