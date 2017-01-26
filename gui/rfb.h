/////////////////////////////////////////////////////////////////////////
// $Id: rfb.h,v 1.4 2004/04/08 17:36:26 cbothamy Exp $
/////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) 2002  MandrakeSoft S.A.
//
//    MandrakeSoft S.A.
//    43, rue d'Aboukir
//    75002 Paris - France
//    http://www.linux-mandrake.com/
//    http://www.mandrakesoft.com/
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
//
// This file includes the rfb spec header and the port numbers

// Define the RFB types
typedef Bit32u         U32;
typedef Bit16u         U16;
typedef Bit8u          U8;
typedef Bit32s         S32;
typedef Bit16s         S16;
typedef Bit8s          S8;

// Port range
#define BX_RFB_PORT_MIN 5900
#define BX_RFB_PORT_MAX 5949


// RFB Protocol definitions. 
// Please refer to the specification document 
// http://www.realvnc.com/docs/rfbproto.pdf

typedef struct {
    U16 xPosition;
    U16 yPosition;
    U16 width;
    U16 height;
    U32 encodingType;
} rfbRectangle;

#define rfbRectangleSize (sizeof(rfbRectangle))


typedef struct {
    U8  bitsPerPixel;
    U8  depth;
    U8  bigEndianFlag;
    U8  trueColourFlag;
    U16 redMax;
    U16 greenMax;
    U16 blueMax;
    U8  redShift;
    U8  greenShift;
    U8  blueShift;
    U8  padding[3];
} rfbPixelFormat;

#define rfbPixelFormatSize (sizeof(rfbPixelFormat))


#define rfbProtocolVersionFormat "RFB %03d.%03d\n"
#define rfbServerProtocolMajorVersion 3
#define rfbServerProtocolMinorVersion 3

typedef char rfbProtocolVersionMessage[12 + 1]; // Add 1 for null byte
#define rfbProtocolVersionMessageSize (sizeof(rfbProtocolVersionMessage) - 1) // Real Message Length


#define rfbSecurityConnFailed 0
#define rfbSecurityNone 1
#define rfbSecurityVncAuth 2

#define rfbSecurityVncAuthOK 0
#define rfbSecurityVncAuthFailed 1
#define rfbSecurityVncAuthTooMany 2 // No longer used (3.7)


typedef struct {
    U8 sharedFlag;
} rfbClientInitMessage;

#define rfbClientInitMessageSize (sizeof(rfbClientInitMessage))


typedef struct {
    U16            framebufferWidth;
    U16            framebufferHeight;
    rfbPixelFormat serverPixelFormat;
    U32            nameLength;
    // U8[]        nameString;
} rfbServerInitMessage;

#define rfbServerInitMessageSize (sizeof(rfbServerInitMessage))

// Client to Server message types
#define rfbSetPixelFormat 0
#define rfbFixColourMapEntries 1
#define rfbSetEncodings 2
#define rfbFramebufferUpdateRequest 3
#define rfbKeyEvent 4
#define rfbPointerEvent 5
#define rfbClientCutText 6


// Client to Server messages

typedef struct {
	U8             messageType;
	U8             padding[3];
	rfbPixelFormat pixelFormat;
} rfbSetPixelFormatMessage;

#define rfbSetPixelFormatMessageSize (sizeof(rfbSetPixelFormatMessage))


typedef struct {
    U8  messageType;
    U8  padding;
    U16 firstColour;
    U16 numberOfColours;
} rfbFixColourMapEntriesMessage;

#define rfbFixColourMapEntriesMessageSize (sizeof(rfbFixColourMapEntriesMessage))


typedef struct {
	U8  messageType;
	U8  padding;
	U16 numberOfEncodings;
} rfbSetEncodingsMessage;

#define rfbSetEncodingsMessageSize (sizeof(rfbSetEncodingsMessage))


typedef struct {
	U8  messageType;
	U8  incremental;
	U16 xPosition;
	U16 yPosition;
	U16 width;
	U16 height;
} rfbFramebufferUpdateRequestMessage;

#define rfbFramebufferUpdateRequestMessageSize (sizeof(rfbFramebufferUpdateRequestMessage))


typedef struct {
	U8  messageType;
	U8  downFlag;
	U8  padding[2];
	U32 key;
} rfbKeyEventMessage;

#define rfbKeyEventMessageSize (sizeof(rfbKeyEventMessage))


typedef struct {
	U8  messageType;
	U8  buttonMask;
	U16 xPosition;
	U16 yPosition;
} rfbPointerEventMessage;

#define rfbPointerEventMessageSize (sizeof(rfbPointerEventMessage)) 

#define rfbButton1Mask 1
#define rfbButton2Mask 2
#define rfbButton3Mask 4


typedef struct {
	U8  messageType;
	U8  padding[3];
	U32 length;
	// U8[]  text;
} rfbClientCutTextMessage;

#define rfbClientCutTextMessageSize (sizeof(rfbClientCutTextMessage))

// Fill in correct names
typedef union {
	rfbSetPixelFormatMessage           spf;
	rfbFixColourMapEntriesMessage      fcme;
	rfbSetEncodingsMessage             se;
	rfbFramebufferUpdateRequestMessage fur;
	rfbKeyEventMessage                 ke;
	rfbPointerEventMessage             pe;
	rfbClientCutTextMessage            cct;
} rfbClientToServerMessage;


// Server to Client message types
#define rfbFramebufferUpdate   0
#define rfbSetColourMapEntries 1
#define rfbBell                2
#define rfbServerCutText       3

// Encoding types
#define rfbEncodingRaw         0
#define rfbEncodingCopyRect    1
#define rfbEncodingRRE         2
#define rfbEncodingCoRRE       4
#define rfbEncodingHextile     5
#define rfbEncodingZRLE       16
#define rfbEncodingCursor      0xffffff11
#define rfbEncodingDesktopSize 0xffffff21
#define rfbEncodingZlib        6
#define rfbEncodingTight       7
#define rfbEncodingZlibHex     8
#define rfbEncodingTightOption00 0xffffff00  // to 0xffffffff except 0xffffff11 and 0xffffff21
#define rfbEncodingTightOption01 0xffffff01
#define rfbEncodingTightOption02 0xffffff02  
#define rfbEncodingTightOption03 0xffffff03  
#define rfbEncodingTightOption04 0xffffff04  
#define rfbEncodingTightOption05 0xffffff05  
#define rfbEncodingTightOption06 0xffffff06  
#define rfbEncodingTightOption07 0xffffff07  
#define rfbEncodingTightOption08 0xffffff08  
#define rfbEncodingTightOption09 0xffffff09  
#define rfbEncodingTightOption0a 0xffffff0a  
#define rfbEncodingTightOption0b 0xffffff0b  
#define rfbEncodingTightOption0c 0xffffff0c  
#define rfbEncodingTightOption0d 0xffffff0d  
#define rfbEncodingTightOption0e 0xffffff0e  
#define rfbEncodingTightOption0f 0xffffff0f  
#define rfbEncodingTightOption10 0xffffff10  
#define rfbEncodingTightOption12 0xffffff12  
#define rfbEncodingTightOption13 0xffffff13  
#define rfbEncodingTightOption14 0xffffff14  
#define rfbEncodingTightOption15 0xffffff15  
#define rfbEncodingTightOption16 0xffffff16  
#define rfbEncodingTightOption17 0xffffff17  
#define rfbEncodingTightOption18 0xffffff18  
#define rfbEncodingTightOption19 0xffffff19  
#define rfbEncodingTightOption1a 0xffffff1a  
#define rfbEncodingTightOption1b 0xffffff1b  
#define rfbEncodingTightOption1c 0xffffff1c  
#define rfbEncodingTightOption1d 0xffffff1d  
#define rfbEncodingTightOption1e 0xffffff1e  
#define rfbEncodingTightOption1f 0xffffff1f  
#define rfbEncodingTightOption20 0xffffff20  

typedef struct {
        U32 id;
        char *name;
} rfbEncodingType;

rfbEncodingType rfbEncodings[] = {
        {rfbEncodingRaw, "Raw"},
        {rfbEncodingCopyRect, "CopyRect"},
        {rfbEncodingRRE, "RRE"},
        {rfbEncodingCoRRE, "CoRRE"},
        {rfbEncodingHextile, "Hextile"},
        {rfbEncodingZRLE, "ZRLE"},
        {rfbEncodingCursor, "Cursor"},
        {rfbEncodingDesktopSize, "DesktopSize"},
        {rfbEncodingZlib, "Zlib"},
        {rfbEncodingTight, "Tight"},
        {rfbEncodingZlibHex, "ZlibHex"},
        {rfbEncodingTightOption00, "TightOption00"},
        {rfbEncodingTightOption01, "TightOption01"},
        {rfbEncodingTightOption02, "TightOption02"},
        {rfbEncodingTightOption03, "TightOption03"},
        {rfbEncodingTightOption04, "TightOption04"},
        {rfbEncodingTightOption05, "TightOption05"},
        {rfbEncodingTightOption06, "TightOption06"},
        {rfbEncodingTightOption07, "TightOption07"},
        {rfbEncodingTightOption08, "TightOption08"},
        {rfbEncodingTightOption09, "TightOption09"},
        {rfbEncodingTightOption0a, "TightOption0a"},
        {rfbEncodingTightOption0b, "TightOption0b"},
        {rfbEncodingTightOption0c, "TightOption0c"},
        {rfbEncodingTightOption0d, "TightOption0d"},
        {rfbEncodingTightOption0e, "TightOption0e"},
        {rfbEncodingTightOption0f, "TightOption0f"},
        {rfbEncodingTightOption10, "TightOption10"},
        {rfbEncodingTightOption12, "TightOption12"},
        {rfbEncodingTightOption13, "TightOption13"},
        {rfbEncodingTightOption14, "TightOption14"},
        {rfbEncodingTightOption15, "TightOption15"},
        {rfbEncodingTightOption16, "TightOption16"},
        {rfbEncodingTightOption17, "TightOption17"},
        {rfbEncodingTightOption18, "TightOption18"},
        {rfbEncodingTightOption19, "TightOption19"},
        {rfbEncodingTightOption1a, "TightOption1a"},
        {rfbEncodingTightOption1b, "TightOption1b"},
        {rfbEncodingTightOption1c, "TightOption1c"},
        {rfbEncodingTightOption1d, "TightOption1d"},
        {rfbEncodingTightOption1e, "TightOption1e"},
        {rfbEncodingTightOption1f, "TightOption1f"},
        {rfbEncodingTightOption20, "TightOption20"},
};

#define rfbEncodingsCount (sizeof(rfbEncodings) / sizeof(rfbEncodingType))

// Server To Client Messages

typedef struct {
	U8  messageType;
	U8  padding;
	U16 numberOfRectangles;
} rfbFramebufferUpdateMessage;

#define rfbFramebufferUpdateMessageSize (sizeof(rfbFramebufferUpdateMessage))

typedef struct {
	rfbRectangle r;
} rfbFramebufferUpdateRectHeader;

#define rfbFramebufferUpdateRectHeaderSize (sizeof(rfbFramebufferUpdateRectHeader))

typedef struct {
	U16 srcXPosition;
	U16 srcYPosition;
} rfbCopyRect;

#define rfbCopyRectSize (sizeof(rfbCopyRect))


/* typedef struct { */
/* 	U32   numberOfSubrectangles; */
/* 	PIXEL backgroundPixelValue; */
/* } rfbRREHeader; */

/* #define rfbRREHeaderSize (sizeof(rfbRREHeader)) */


/* typedef struct { */
/* 	U32   numberOfSubrectangles; */
/* 	PIXEL backgroundPixelValue; */
/* } rfbCoRRERectangle; */

/* #define rfbCoRRERectangleSize (sizeof(rfbCoRRERectangle)) */


#define rfbHextileRaw			(1 << 0)
#define rfbHextileBackgroundSpecified	(1 << 1)
#define rfbHextileForegroundSpecified	(1 << 2)
#define rfbHextileAnySubrects		(1 << 3)
#define rfbHextileSubrectsColoured	(1 << 4)

#define rfbHextilePackXY(x,y) (((x) << 4) | (y))
#define rfbHextilePackWH(w,h) ((((w)-1) << 4) | ((h)-1))
#define rfbHextileExtractX(byte) ((byte) >> 4)
#define rfbHextileExtractY(byte) ((byte) & 0xf)
#define rfbHextileExtractW(byte) (((byte) >> 4) + 1)
#define rfbHextileExtractH(byte) (((byte) & 0xf) + 1)


typedef struct {
	U8  messageType;
	U8  padding;
	U16 firstColour;
	U16 numberOfColours;
} rfbSetColourMapEntriesMessage;

#define rfbSetColourMapEntriesMessageSize (sizeof(rfbSetColourMapEntriesMessage))



typedef struct {
	U8 messageType;
} rfbBellMessage;

#define rfbBellMessageSize (sizeof(rfbBellMessage))



typedef struct {
	U8  messageType;
	U8  padding[3];
	U32 length;
	// U8[]  text;
} rfbServerCutTextMessage;

#define rfbServerCutTextMessageSize (sizeof(rfbServerCutTextMessage))

// Fill in correct names
typedef union {
	rfbFramebufferUpdateMessage fu;
	rfbBellMessage              b;
	rfbServerCutTextMessage     sct;
} rfbServerToClientMessage;

/***********************/
/* Keyboard Definitons */
/*        And          */
/*     Functions       */
/***********************/

#define XK_space            0x020
#define XK_asciitilde       0x07e

#define XK_dead_grave       0xFE50
#define XK_dead_acute       0xFE51
#define XK_dead_circumflex  0xFE52
#define XK_dead_tilde       0xFE53

#define XK_BackSpace        0xFF08
#define XK_Tab              0xFF09
#define XK_Linefeed         0xFF0A
#define XK_Clear            0xFF0B
#define XK_Return           0xFF0D
#define XK_Pause            0xFF13
#define XK_Scroll_Lock      0xFF14
#define XK_Sys_Req          0xFF15
#define XK_Escape           0xFF1B

#define XK_Delete           0xFFFF

#define XK_Home             0xFF50
#define XK_Left             0xFF51
#define XK_Up               0xFF52
#define XK_Right            0xFF53
#define XK_Down             0xFF54
#define XK_Page_Up          0xFF55
#define XK_Page_Down        0xFF56
#define XK_End              0xFF57
#define XK_Begin            0xFF58

#define XK_Select           0xFF60
#define XK_Print            0xFF61
#define XK_Execute          0xFF62
#define XK_Insert           0xFF63

#define XK_Cancel           0xFF69
#define XK_Help             0xFF6A
#define XK_Break            0xFF6B
#define XK_Num_Lock         0xFF7F

#define XK_KP_Space         0xFF80
#define XK_KP_Tab           0xFF89
#define XK_KP_Enter         0xFF8D

#define XK_KP_Home          0xFF95
#define XK_KP_Left          0xFF96
#define XK_KP_Up            0xFF97
#define XK_KP_Right         0xFF98
#define XK_KP_Down          0xFF99
#define XK_KP_Prior         0xFF9A
#define XK_KP_Page_Up       0xFF9A
#define XK_KP_Next          0xFF9B
#define XK_KP_Page_Down     0xFF9B
#define XK_KP_End           0xFF9C
#define XK_KP_Begin         0xFF9D
#define XK_KP_Insert        0xFF9E
#define XK_KP_Delete        0xFF9F
#define XK_KP_Equal         0xFFBD
#define XK_KP_Multiply      0xFFAA
#define XK_KP_Add           0xFFAB
#define XK_KP_Separator     0xFFAC
#define XK_KP_Subtract      0xFFAD
#define XK_KP_Decimal       0xFFAE
#define XK_KP_Divide        0xFFAF

#define XK_KP_F1            0xFF91
#define XK_KP_F2            0xFF92
#define XK_KP_F3            0xFF93
#define XK_KP_F4            0xFF94

#define XK_KP_0             0xFFB0
#define XK_KP_1             0xFFB1
#define XK_KP_2             0xFFB2
#define XK_KP_3             0xFFB3
#define XK_KP_4             0xFFB4
#define XK_KP_5             0xFFB5
#define XK_KP_6             0xFFB6
#define XK_KP_7             0xFFB7
#define XK_KP_8             0xFFB8
#define XK_KP_9             0xFFB9

#define XK_F1               0xFFBE
#define XK_F2               0xFFBF
#define XK_F3               0xFFC0
#define XK_F4               0xFFC1
#define XK_F5               0xFFC2
#define XK_F6               0xFFC3
#define XK_F7               0xFFC4
#define XK_F8               0xFFC5
#define XK_F9               0xFFC6
#define XK_F10              0xFFC7
#define XK_F11              0xFFC8
#define XK_F12              0xFFC9
#define XK_F13              0xFFCA
#define XK_F14              0xFFCB
#define XK_F15              0xFFCC
#define XK_F16              0xFFCD
#define XK_F17              0xFFCE
#define XK_F18              0xFFCF
#define XK_F19              0xFFD0
#define XK_F20              0xFFD1
#define XK_F21              0xFFD2
#define XK_F22              0xFFD3
#define XK_F23              0xFFD4
#define XK_F24              0xFFD5


#define XK_Shift_L          0xFFE1
#define XK_Shift_R          0xFFE2
#define XK_Control_L        0xFFE3
#define XK_Control_R        0xFFE4
#define XK_Caps_Lock        0xFFE5
#define XK_Shift_Lock       0xFFE6
#define XK_Meta_L           0xFFE7
#define XK_Meta_R           0xFFE8
#define XK_Alt_L            0xFFE9
#define XK_Alt_R            0xFFEA
