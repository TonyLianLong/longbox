/////////////////////////////////////////////////////////////////////////
// $Id: ios.cc,v 1.23 2017/01/23 21:35:08 vruppert Exp $
/////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) 2001  MandrakeSoft S.A.
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



// Define BX_PLUGGABLE in files that can be compiled into plugins.  For
// platforms that require a special tag on exported symbols, BX_PLUGGABLE 
// is used to know when we are exporting symbols and when we are importing.
#define BX_PLUGGABLE

#include "bochs.h"
#include "iodev.h"
#if BX_WITH_IOS
#include "icon_bochs.h"
/***********************/
/* Keyboard Definitons */
/*        And          */
/*     Functions       */
/***********************/

#define XK_space            0x020
#define XK_asciitilde       0x07e


#define XK_BackSpace        0x08
#define XK_Tab              0x09
//#define XK_Linefeed         0xFF0A
#define XK_Clear            0xFF0B
#define XK_Return           0x0D
#define XK_Pause            0x13
#define XK_Scroll_Lock      0x14
#define XK_Sys_Req          0x15
#define XK_Escape           0x1B

#define XK_Delete           0xFF

#define XK_Home             0xFF50
#define XK_Left             0xFF51
#define XK_Up               0xFF52
#define XK_Right            0xFF53
#define XK_Down             0xFF54
#define XK_Page_Up          0xFF55
#define XK_Page_Down        0xFF56
#define XK_End              0xFF57
#define XK_Begin            0xFF58

//#define XK_Select           0xFF60
//#define XK_Print            0xFF61
//#define XK_Execute          0xFF62
//#define XK_Insert           0xFF63

//#define XK_Cancel           0xFF69
//#define XK_Help             0xFF6A
//#define XK_Break            0xFF6B
//#define XK_Num_Lock         0xFF7F

#define XK_KP_Space         0xFF80
#define XK_KP_Tab           0xFF89
#define XK_KP_Enter         0xFF0A

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


Bit32u ascii_to_key_event[0x5f] = {
    //  !"#$%&'
    BX_KEY_SPACE,
    BX_KEY_1,
    BX_KEY_SINGLE_QUOTE,
    BX_KEY_3,
    BX_KEY_4,
    BX_KEY_5,
    BX_KEY_7,
    BX_KEY_SINGLE_QUOTE,
    
    // ()*+,-./
    BX_KEY_9,
    BX_KEY_0,
    BX_KEY_8,
    BX_KEY_EQUALS,
    BX_KEY_COMMA,
    BX_KEY_MINUS,
    BX_KEY_PERIOD,
    BX_KEY_SLASH,
    
    // 01234567
    BX_KEY_0,
    BX_KEY_1,
    BX_KEY_2,
    BX_KEY_3,
    BX_KEY_4,
    BX_KEY_5,
    BX_KEY_6,
    BX_KEY_7,
    
    // 89:;<=>?
    BX_KEY_8,
    BX_KEY_9,
    BX_KEY_SEMICOLON,
    BX_KEY_SEMICOLON,
    BX_KEY_COMMA,
    BX_KEY_EQUALS,
    BX_KEY_PERIOD,
    BX_KEY_SLASH,
    
    // @ABCDEFG
    BX_KEY_2,
    BX_KEY_A,
    BX_KEY_B,
    BX_KEY_C,
    BX_KEY_D,
    BX_KEY_E,
    BX_KEY_F,
    BX_KEY_G,
    
    
    // HIJKLMNO
    BX_KEY_H,
    BX_KEY_I,
    BX_KEY_J,
    BX_KEY_K,
    BX_KEY_L,
    BX_KEY_M,
    BX_KEY_N,
    BX_KEY_O,
    
    
    // PQRSTUVW
    BX_KEY_P,
    BX_KEY_Q,
    BX_KEY_R,
    BX_KEY_S,
    BX_KEY_T,
    BX_KEY_U,
    BX_KEY_V,
    BX_KEY_W,
    
    // XYZ[\]^_
    BX_KEY_X,
    BX_KEY_Y,
    BX_KEY_Z,
    BX_KEY_LEFT_BRACKET,
    BX_KEY_BACKSLASH,
    BX_KEY_RIGHT_BRACKET,
    BX_KEY_6,
    BX_KEY_MINUS,
    
    // `abcdefg
    BX_KEY_GRAVE,
    BX_KEY_A,
    BX_KEY_B,
    BX_KEY_C,
    BX_KEY_D,
    BX_KEY_E,
    BX_KEY_F,
    BX_KEY_G,
    
    // hijklmno
    BX_KEY_H,
    BX_KEY_I,
    BX_KEY_J,
    BX_KEY_K,
    BX_KEY_L,
    BX_KEY_M,
    BX_KEY_N,
    BX_KEY_O,
    
    // pqrstuvw
    BX_KEY_P,
    BX_KEY_Q,
    BX_KEY_R,
    BX_KEY_S,
    BX_KEY_T,
    BX_KEY_U,
    BX_KEY_V,
    BX_KEY_W,
    
    // xyz{|}~
    BX_KEY_X,
    BX_KEY_Y,
    BX_KEY_Z,
    BX_KEY_LEFT_BRACKET,
    BX_KEY_BACKSLASH,
    BX_KEY_RIGHT_BRACKET,
    BX_KEY_GRAVE
};

void sendKey(Bit32u keysym)
{
    if(keysym != 0){
        printf("Key: 0x%x\n",keysym);
        Bit32u key_event;
        if ((keysym >= XK_space) && (keysym <= XK_asciitilde)) {
            key_event = ascii_to_key_event[keysym - XK_space];
            if((keysym >= 0x21 && keysym <= 0x26)||(keysym >= 0x28 && keysym <= 0x2b)||(keysym >= 0x3a && keysym <= 0x5f)||(keysym >= 0x7b && keysym <= 0x7e)){
                DEV_kbd_gen_scancode(BX_KEY_SHIFT_L);
                DEV_kbd_gen_scancode(key_event);
                DEV_kbd_gen_scancode(key_event|BX_KEY_RELEASED);
                DEV_kbd_gen_scancode(BX_KEY_SHIFT_L|BX_KEY_RELEASED);
            }else{
                DEV_kbd_gen_scancode(key_event);
                DEV_kbd_gen_scancode(key_event|BX_KEY_RELEASED);

            }
        }else{
            switch (keysym) {
                /*case XK_KP_1:
#ifdef XK_KP_End
                case XK_KP_End:
#endif
                    key_event = BX_KEY_KP_END; break;
                    
                case XK_KP_2:
#ifdef XK_KP_Down
                case XK_KP_Down:
#endif
                    key_event = BX_KEY_KP_DOWN; break;
                    
                case XK_KP_3:
#ifdef XK_KP_Page_Down
                case XK_KP_Page_Down:
#endif
                    key_event = BX_KEY_KP_PAGE_DOWN; break;
                    
                case XK_KP_4:
#ifdef XK_KP_Left
                case XK_KP_Left:
#endif
                    key_event = BX_KEY_KP_LEFT; break;
                    
                case XK_KP_5:
                    key_event = BX_KEY_KP_5; break;
                    
                case XK_KP_6:
#ifdef XK_KP_Right
                case XK_KP_Right:
#endif
                    key_event = BX_KEY_KP_RIGHT; break;
                    
                case XK_KP_7:
#ifdef XK_KP_Home
                case XK_KP_Home:
#endif
                    key_event = BX_KEY_KP_HOME; break;
                    
                case XK_KP_8:
#ifdef XK_KP_Up
                case XK_KP_Up:
#endif
                    key_event = BX_KEY_KP_UP; break;
                    
                case XK_KP_9:
#ifdef XK_KP_Page_Up
                case XK_KP_Page_Up:
#endif
                    key_event = BX_KEY_KP_PAGE_UP; break;
                    
                case XK_KP_0:
#ifdef XK_KP_Insert
                case XK_KP_Insert:
                    key_event = BX_KEY_KP_INSERT; break;
#endif
                    
                case XK_KP_Decimal:
#ifdef XK_KP_Delete
                case XK_KP_Delete:
                    key_event = BX_KEY_KP_DELETE; break;
#endif*/
                    
#ifdef XK_KP_Enter
                case 0xA:
                    key_event = BX_KEY_KP_ENTER; break;
#endif
                    
                /*case XK_KP_Subtract: key_event = BX_KEY_KP_SUBTRACT; break;
                case XK_KP_Add:      key_event = BX_KEY_KP_ADD; break;
                    
                case XK_KP_Multiply: key_event = BX_KEY_KP_MULTIPLY; break;
                case XK_KP_Divide:   key_event = BX_KEY_KP_DIVIDE; break;
                    
                    
                case XK_Up:          key_event = BX_KEY_UP; break;
                case XK_Down:        key_event = BX_KEY_DOWN; break;
                case XK_Left:        key_event = BX_KEY_LEFT; break;
                case XK_Right:       key_event = BX_KEY_RIGHT; break;
                    
                    
                case XK_Delete:      key_event = BX_KEY_DELETE; break;
                case XK_Tab:         key_event = BX_KEY_TAB; break;
                case XK_Return:      key_event = BX_KEY_ENTER; break;
                case XK_Escape:      key_event = BX_KEY_ESC; break;
                case XK_F1:          key_event = BX_KEY_F1; break;
                case XK_F2:          key_event = BX_KEY_F2; break;
                case XK_F3:          key_event = BX_KEY_F3; break;
                case XK_F4:          key_event = BX_KEY_F4; break;
                case XK_F5:          key_event = BX_KEY_F5; break;
                case XK_F6:          key_event = BX_KEY_F6; break;
                case XK_F7:          key_event = BX_KEY_F7; break;
                case XK_F8:          key_event = BX_KEY_F8; break;
                case XK_F9:          key_event = BX_KEY_F9; break;
                case XK_F10:         key_event = BX_KEY_F10; break;
                case XK_F11:         key_event = BX_KEY_F11; break;
                case XK_F12:         key_event = BX_KEY_F12; break;
                case XK_Control_L:   key_event = BX_KEY_CTRL_L; break;
                case XK_Shift_L:     key_event = BX_KEY_SHIFT_L; break;
                case XK_Shift_R:     key_event = BX_KEY_SHIFT_R; break;
                case XK_Caps_Lock:   key_event = BX_KEY_CAPS_LOCK; break;
                    //case XK_Num_Lock:    key_event = BX_KEY_NUM_LOCK; break;
                case XK_Alt_L:       key_event = BX_KEY_ALT_L; break;
                    
                case XK_Insert:      key_event = BX_KEY_INSERT; break;
                case XK_Home:        key_event = BX_KEY_HOME; break;
                case XK_End:         key_event = BX_KEY_END; break;
                case XK_Page_Up:     key_event = BX_KEY_PAGE_UP; break;
                case XK_Page_Down:   key_event = BX_KEY_PAGE_DOWN; break;*/
                case XK_BackSpace:   key_event = BX_KEY_BACKSPACE; break;
                default:
                    fprintf(stderr, "# handle_events(): keysym %x unhandled!\n", (unsigned) keysym);
                    return;
                    break;
            }
            DEV_kbd_gen_scancode(key_event);
            DEV_kbd_gen_scancode(key_event|BX_KEY_RELEASED);
        }
    }
}
extern "C"{
#include "box-main.h"
    void ios_send_key(uint8_t key){
        sendKey(key);
    }
}

class bx_ios_gui_c : public bx_gui_c {
public:
  bx_ios_gui_c (void) {}
  DECLARE_GUI_VIRTUAL_METHODS()
};

// declare one instance of the gui object and call macro to insert the
// plugin code
static bx_ios_gui_c *theGui = NULL;
IMPLEMENT_GUI_PLUGIN_CODE(ios)

#define LOG_THIS theGui->

// This file defines stubs for the GUI interface, which is a
// place to start if you want to port bochs to a platform, for
// which there is no support for your native GUI, or if you want to compile
// bochs without any native GUI support (no output window or
// keyboard input will be possible).
// Look in 'x.cc', 'beos.cc', and 'win32.cc' for specific
// implementations of this interface.  -Kevin



// ::SPECIFIC_INIT()
//
// Called from gui.cc, once upon program startup, to allow for the
// specific GUI code (X11, BeOS, ...) to be initialized.
//
// argc, argv: not used right now, but the intention is to pass native GUI
//     specific options from the command line.  (X11 options, BeOS options,...)
//
// tilewidth, tileheight: for optimization, graphics_tile_update() passes
//     only updated regions of the screen to the gui code to be redrawn.
//     These define the dimensions of a region (tile).
// headerbar_y:  A headerbar (toolbar) is display on the top of the
//     VGA window, showing floppy status, and other information.  It
//     always assumes the width of the current VGA mode width, but
//     it's height is defined by this parameter.

  void
bx_ios_gui_c::specific_init(int argc, char **argv, unsigned tilewidth, unsigned tileheight,
                     unsigned headerbar_y)
{
  put("NGUI");
    printf("NON-GUI INIT\n");
  UNUSED(argc);
  UNUSED(argv);
  UNUSED(tilewidth);
  UNUSED(tileheight);
  UNUSED(headerbar_y);

  UNUSED(bochs_icon_bits);  // global variable

  if (SIM->get_param_bool(BXPN_PRIVATE_COLORMAP)->get()) {
    BX_INFO(("private_colormap option ignored."));
  }
}


// ::HANDLE_EVENTS()
//
// Called periodically (vga_update_interval in .bochsrc) so the
// the gui code can poll for keyboard, mouse, and other
// relevant events.

  void
bx_ios_gui_c::handle_events(void)
{
}


// ::FLUSH()
//
// Called periodically, requesting that the gui code flush all pending
// screen update requests.

  void
bx_ios_gui_c::flush(void)
{
}


// ::CLEAR_SCREEN()
//
// Called to request that the VGA region is cleared.  Don't
// clear the area that defines the headerbar.

  void
bx_ios_gui_c::clear_screen(void)
{
}



// ::TEXT_UPDATE()
//
// Called in a VGA text mode, to update the screen with
// new content.
//
// old_text: array of character/attributes making up the contents
//           of the screen from the last call.  See below
// new_text: array of character/attributes making up the current
//           contents, which should now be displayed.  See below
//
// format of old_text & new_text: each is 4000 bytes long.
//     This represents 80 characters wide by 25 high, with
//     each character being 2 bytes.  The first by is the
//     character value, the second is the attribute byte.
//     I currently don't handle the attribute byte.
//
// cursor_x: new x location of cursor
// cursor_y: new y location of cursor

  void
bx_ios_gui_c::text_update(Bit8u *old_text, Bit8u *new_text,
                      unsigned long cursor_x, unsigned long cursor_y,
                      bx_vga_tminfo_t tm_info, unsigned nrows)
{
  ios_screen_display(new_text,cursor_x,cursor_y);
  UNUSED(old_text);
  UNUSED(new_text);
  UNUSED(cursor_x);
  UNUSED(cursor_y);
  UNUSED(tm_info);
  UNUSED(nrows);
}

  int
bx_ios_gui_c::get_clipboard_text(Bit8u **bytes, Bit32s *nbytes)
{
  UNUSED(bytes);
  UNUSED(nbytes);
  return 0;
}

  int
bx_ios_gui_c::set_clipboard_text(char *text_snapshot, Bit32u len)
{
  UNUSED(text_snapshot);
  UNUSED(len);
  return 0;
}


// ::PALETTE_CHANGE()
//
// Allocate a color in the native GUI, for this color, and put
// it in the colormap location 'index'.
// returns: 0=no screen update needed (color map change has direct effect)
//          1=screen updated needed (redraw using current colormap)

  bx_bool
bx_ios_gui_c::palette_change(unsigned index, unsigned red, unsigned green, unsigned blue)
{
  UNUSED(index);
  UNUSED(red);
  UNUSED(green);
  UNUSED(blue);
  return(0);
}


// ::GRAPHICS_TILE_UPDATE()
//
// Called to request that a tile of graphics be drawn to the
// screen, since info in this region has changed.
//
// tile: array of 8bit values representing a block of pixels with
//       dimension equal to the 'tilewidth' & 'tileheight' parameters to
//       ::specific_init().  Each value specifies an index into the
//       array of colors you allocated for ::palette_change()
// x0: x origin of tile
// y0: y origin of tile
//
// note: origin of tile and of window based on (0,0) being in the upper
//       left of the window.

  void
bx_ios_gui_c::graphics_tile_update(Bit8u *tile, unsigned x0, unsigned y0)
{
  UNUSED(tile);
  UNUSED(x0);
  UNUSED(y0);
}



// ::DIMENSION_UPDATE()
//
// Called when the VGA mode changes it's X,Y dimensions.
// Resize the window to this size, but you need to add on
// the height of the headerbar to the Y value.
//
// x: new VGA x size
// y: new VGA y size (add headerbar_y parameter from ::specific_init().
// fheight: new VGA character height in text mode
// fwidth : new VGA character width in text mode
// bpp : bits per pixel in graphics mode

  void
bx_ios_gui_c::dimension_update(unsigned x, unsigned y, unsigned fheight, unsigned fwidth, unsigned bpp)
{
  UNUSED(x);
  UNUSED(y);
  UNUSED(fheight);
  UNUSED(fwidth);
  UNUSED(bpp);
}


// ::CREATE_BITMAP()
//
// Create a monochrome bitmap of size 'xdim' by 'ydim', which will
// be drawn in the headerbar.  Return an integer ID to the bitmap,
// with which the bitmap can be referenced later.
//
// bmap: packed 8 pixels-per-byte bitmap.  The pixel order is:
//       bit0 is the left most pixel, bit7 is the right most pixel.
// xdim: x dimension of bitmap
// ydim: y dimension of bitmap

  unsigned
bx_ios_gui_c::create_bitmap(const unsigned char *bmap, unsigned xdim, unsigned ydim)
{
  UNUSED(bmap);
  UNUSED(xdim);
  UNUSED(ydim);
  return(0);
}


// ::HEADERBAR_BITMAP()
//
// Called to install a bitmap in the bochs headerbar (toolbar).
//
// bmap_id: will correspond to an ID returned from
//     ::create_bitmap().  'alignment' is either BX_GRAVITY_LEFT
//     or BX_GRAVITY_RIGHT, meaning install the bitmap in the next
//     available leftmost or rightmost space.
// alignment: is either BX_GRAVITY_LEFT or BX_GRAVITY_RIGHT,
//     meaning install the bitmap in the next
//     available leftmost or rightmost space.
// f: a 'C' function pointer to callback when the mouse is clicked in
//     the boundaries of this bitmap.

  unsigned
bx_ios_gui_c::headerbar_bitmap(unsigned bmap_id, unsigned alignment, void (*f)(void))
{
  UNUSED(bmap_id);
  UNUSED(alignment);
  UNUSED(f);
  return(0);
}


// ::SHOW_HEADERBAR()
//
// Show (redraw) the current headerbar, which is composed of
// currently installed bitmaps.

  void
bx_ios_gui_c::show_headerbar(void)
{
}


// ::REPLACE_BITMAP()
//
// Replace the bitmap installed in the headerbar ID slot 'hbar_id',
// with the one specified by 'bmap_id'.  'bmap_id' will have
// been generated by ::create_bitmap().  The old and new bitmap
// must be of the same size.  This allows the bitmap the user
// sees to change, when some action occurs.  For example when
// the user presses on the floppy icon, it then displays
// the ejected status.
//
// hbar_id: headerbar slot ID
// bmap_id: bitmap ID

  void
bx_ios_gui_c::replace_bitmap(unsigned hbar_id, unsigned bmap_id)
{
  UNUSED(hbar_id);
  UNUSED(bmap_id);
}


// ::EXIT()
//
// Called before bochs terminates, to allow for a graceful
// exit from the native GUI mechanism.

  void
bx_ios_gui_c::exit(void)
{
  BX_INFO(("bx_ios_gui_c::exit() not implemented yet."));
}

  void
bx_ios_gui_c::mouse_enabled_changed_specific (bx_bool val)
{
}

#endif /* if BX_WITH_IOS */
