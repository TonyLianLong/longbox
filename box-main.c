//
//  box-main.c
//  longbox
//
//  Created by Tony on 16/9/16.
//  Copyright © 2016年 Tonylianlong. All rights reserved.
//

#include "box-main.h"
#include "font/vga.bitmap.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define screenwid 800 //We may change it to a variable afterwards
#define screenhei 600 //We may change it to a variable afterwards
char *documentPath;
char *bundlePath;
char *filepath;
void (^updateScreen)(struct PixelData*,uint32_t,uint32_t) = NULL;
extern int bochs_main (const char* configString);
extern void ios_send_key(uint8_t key);
struct PixelData screen[screenwid*screenhei];
void ios_screen_init(){
    for(int i = 0;i < screenwid*screenhei;i++){
        screen[i].a = 0xFF;
        screen[i].r = 0;
        screen[i].g = 0;
        screen[i].b = 0;
    }
    updateScreen(screen,screenwid,screenhei);
}

void ios_screen_display(uint8_t *screendata,unsigned long cursor_x,unsigned long cursor_y){//It must be 80*25*2
    for(int a = 0;a < 80;a++){
        for(int b = 0;b < 25;b++){
            char c = screendata[(a+b*80)<<1];
            if((cursor_x == a)&&(cursor_y == b)){
                //printf("cursor_x:%lu cursor_y:%lu",cursor_x,cursor_y);
                for(int i = 0;i < 16;i++){
                    for(int j = 0;j < 8;j++){
                        if((bx_vgafont[c].data[i]>>j)&1){
                            screen[(b*16+i)*screenwid+j+a*8].r = 0x00;
                            screen[(b*16+i)*screenwid+j+a*8].g = 0x00;
                            screen[(b*16+i)*screenwid+j+a*8].b = 0x00;
                        }else{
                            screen[(b*16+i)*screenwid+j+a*8].r = 0xFF;
                            screen[(b*16+i)*screenwid+j+a*8].g = 0xFF;
                            screen[(b*16+i)*screenwid+j+a*8].b = 0xFF;
                        }
                    }
                }
            }else{
                for(int i = 0;i < 16;i++){
                    for(int j = 0;j < 8;j++){
                        if((bx_vgafont[c].data[i]>>j)&1){
                            screen[(b*16+i)*screenwid+j+a*8].r = 0xFF;
                            screen[(b*16+i)*screenwid+j+a*8].g = 0xFF;
                            screen[(b*16+i)*screenwid+j+a*8].b = 0xFF;
                        }else{
                            screen[(b*16+i)*screenwid+j+a*8].r = 0x00;
                            screen[(b*16+i)*screenwid+j+a*8].g = 0x00;
                            screen[(b*16+i)*screenwid+j+a*8].b = 0x00;
                        }
                    }
                }
            }
        }
    }
    updateScreen(screen,screenwid,screenhei);
}
void sendKey(uint8_t keyType,uint8_t key){
    if(keyType == 1){
        if(key == 0){
            ios_send_key(8);
        }
    }else{
        ios_send_key(key);
    }
}
int box_main(char *document, char *bundle){
    documentPath = document;
    bundlePath = bundle;
    printf("We are now in C.\n");
    printf("Bundlepath: %s filepath size:%lu!\n",bundle,strlen(document)+1);
    //char buf[200];
    filepath = (char *)malloc(strlen(document)+sizeof("/bochsrc.txt"));//+strlen(srcname)+1
    strcpy(filepath,document);
    strcat(filepath,"/bochsrc.txt");
    printf("Bochsrc path:%s\n",filepath);
    /*FILE *fd = fopen(filepath,"r");
    if(fd){
        fread(buf,sizeof(char),10,fd);
        fclose(fd);
        buf[10] = 0;
        printf("%s\n",buf);
    }else{
        perror ("Read file");
    }*/
    ios_screen_init();
    //return 0;
    return bochs_main(filepath);
}
