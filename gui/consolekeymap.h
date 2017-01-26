/////////////////////////////////////////////////////////////////////////
// $Id: rfbkeys.h 11701 2013-05-31 16:46:15Z vruppert $
/////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) 2009-2013  The Bochs Project
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
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
/////////////////////////////////////////////////////////////////////////

// This file includes the key definitions and keyboard mapping stuff
// Edited

  enum {
  XK_space = 0x020,
  XK_exclam,
  XK_quotedbl,
  XK_numbersign,
  XK_dollar,
  XK_percent,
  XK_ampersand,
  XK_apostrophe,
  XK_parenleft,
  XK_parenright,
  XK_asterisk,
  XK_plus,
  XK_comma,
  XK_minus,
  XK_period,
  XK_slash,
  XK_0,
  XK_1,
  XK_2,
  XK_3,
  XK_4,
  XK_5,
  XK_6,
  XK_7,
  XK_8,
  XK_9,
  XK_colon,
  XK_semicolon,
  XK_less,
  XK_equal,
  XK_greater,
  XK_question,
  XK_at,
  XK_A,
  XK_B,
  XK_C,
  XK_D,
  XK_E,
  XK_F,
  XK_G,
  XK_H,
  XK_I,
  XK_J,
  XK_K,
  XK_L,
  XK_M,
  XK_N,
  XK_O,
  XK_P,
  XK_Q,
  XK_R,
  XK_S,
  XK_T,
  XK_U,
  XK_V,
  XK_W,
  XK_X,
  XK_Y,
  XK_Z,
  XK_bracketleft,
  XK_backslash,
  XK_bracketright,
  XK_asciicircum,
  XK_underscore,
  XK_grave,
  XK_a,
  XK_b,
  XK_c,
  XK_d,
  XK_e,
  XK_f,
  XK_g,
  XK_h,
  XK_i,
  XK_j,
  XK_k,
  XK_l,
  XK_m,
  XK_n,
  XK_o,
  XK_p,
  XK_q,
  XK_r,
  XK_s,
  XK_t,
  XK_u,
  XK_v,
  XK_w,
  XK_x,
  XK_y,
  XK_z,
  XK_braceleft,
  XK_bar,
  XK_braceright,
  XK_asciitilde
};


#define XK_nobreakspace     0x00a0
#define XK_exclamdown       0x00a1
#define XK_cent             0x00a2
#define XK_sterling         0x00a3
#define XK_currency         0x00a4
#define XK_yen              0x00a5
#define XK_brokenbar        0x00a6
#define XK_section          0x00a7
#define XK_diaeresis        0x00a8
#define XK_copyright        0x00a9
#define XK_ordfeminine      0x00aa
#define XK_guillemotleft    0x00ab
#define XK_notsign          0x00ac
#define XK_hyphen           0x00ad
#define XK_registered       0x00ae
#define XK_macron           0x00af
#define XK_degree           0x00b0
#define XK_plusminus        0x00b1
#define XK_twosuperior      0x00b2
#define XK_threesuperior    0x00b3
#define XK_acute            0x00b4
#define XK_mu               0x00b5
#define XK_paragraph        0x00b6
#define XK_periodcentered   0x00b7
#define XK_cedilla          0x00b8
#define XK_onesuperior      0x00b9
#define XK_masculine        0x00ba
#define XK_guillemotright   0x00bb
#define XK_onequarter       0x00bc
#define XK_onehalf          0x00bd
#define XK_threequarters    0x00be
#define XK_questiondown     0x00bf
#define XK_Agrave           0x00c0
#define XK_Aacute           0x00c1
#define XK_Acircumflex      0x00c2
#define XK_Atilde           0x00c3
#define XK_Adiaeresis       0x00c4
#define XK_Aring            0x00c5
#define XK_AE               0x00c6
#define XK_Ccedilla         0x00c7
#define XK_Egrave           0x00c8
#define XK_Eacute           0x00c9
#define XK_Ecircumflex      0x00ca
#define XK_Ediaeresis       0x00cb
#define XK_Igrave           0x00cc
#define XK_Iacute           0x00cd
#define XK_Icircumflex      0x00ce
#define XK_Idiaeresis       0x00cf
#define XK_ETH              0x00d0
#define XK_Ntilde           0x00d1
#define XK_Ograve           0x00d2
#define XK_Oacute           0x00d3
#define XK_Ocircumflex      0x00d4
#define XK_Otilde           0x00d5
#define XK_Odiaeresis       0x00d6
#define XK_multiply         0x00d7
#define XK_Oslash           0x00d8
#define XK_Ooblique         0x00d8
#define XK_Ugrave           0x00d9
#define XK_Uacute           0x00da
#define XK_Ucircumflex      0x00db
#define XK_Udiaeresis       0x00dc
#define XK_Yacute           0x00dd
#define XK_THORN            0x00de
#define XK_ssharp           0x00df
#define XK_agrave           0x00e0
#define XK_aacute           0x00e1
#define XK_acircumflex      0x00e2
#define XK_atilde           0x00e3
#define XK_adiaeresis       0x00e4
#define XK_aring            0x00e5
#define XK_ae               0x00e6
#define XK_ccedilla         0x00e7
#define XK_egrave           0x00e8
#define XK_eacute           0x00e9
#define XK_ecircumflex      0x00ea
#define XK_ediaeresis       0x00eb
#define XK_igrave           0x00ec
#define XK_iacute           0x00ed
#define XK_icircumflex      0x00ee
#define XK_idiaeresis       0x00ef
#define XK_eth              0x00f0
#define XK_ntilde           0x00f1
#define XK_ograve           0x00f2
#define XK_oacute           0x00f3
#define XK_ocircumflex      0x00f4
#define XK_otilde           0x00f5
#define XK_odiaeresis       0x00f6
#define XK_division         0x00f7
#define XK_oslash           0x00f8
#define XK_ooblique         0x00f8
#define XK_ugrave           0x00f9
#define XK_uacute           0x00fa
#define XK_ucircumflex      0x00fb
#define XK_udiaeresis       0x00fc
#define XK_yacute           0x00fd
#define XK_thorn            0x00fe
#define XK_ydiaeresis       0x00ff

#define XK_EuroSign         0x20ac

#define XK_ISO_Level3_Shift 0xFE03
#define XK_ISO_Left_Tab     0xFE20

#define XK_dead_grave       0xFE50
#define XK_dead_acute       0xFE51
#define XK_dead_circumflex  0xFE52
#define XK_dead_tilde       0xFE53

#define XK_BackSpace        0xFF7F // 0xFF08
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
#define XK_Menu             0xff67
#define XK_Cancel           0xFF69
#define XK_Help             0xFF6A
#define XK_Break            0xFF6B
// #define XK_Num_Lock         0xFF7F

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
/////////////////////////////////////////////////////////////////////////
// $Id: rfbkeys.h 11701 2013-05-31 16:46:15Z vruppert $
/////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) 2009-2013  The Bochs Project
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
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
/////////////////////////////////////////////////////////////////////////

// This file includes the rfb key definitions and keyboard mapping stuff

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
#define XK_Super_L          0xFFEB
#define XK_Super_R          0xFFEC