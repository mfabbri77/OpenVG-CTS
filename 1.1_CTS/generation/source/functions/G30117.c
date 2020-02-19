/*------------------------------------------------------------------------------
Copyright (c) 2008 The Khronos Group Inc.

All Rights Reserved.  This code is protected by copyright laws and contains
material proprietary to the Khronos Group, Inc.  This is UNPUBLISHED
PROPRIETARY SOURCE CODE that may not be disclosed in whole or in part to third
parties, and may not be reproduced, republished, distributed, transmitted,
displayed, broadcast or otherwise exploited in any manner without the express
prior written permission of Khronos Group.

The receipt or possession of this code does not convey any rights to reproduce,
disclose, or distribute its contents, or to manufacture, use, or sell anything
that it may describe, in whole or in part other than under the terms of the
Khronos Adopters Agreement or Khronos Conformance Test Source License Agreement
as executed between Khronos and the recipient.

For the avoidance of doubt, this code when provided: a) under the Khronos
Conformance Test Source License Agreement is for the sole purpose of creating
conformance tests for delivery to Khronos and does not provide for formally
testing products or use of Khronos trademarks on conformant products; b) under
the Khronos Adopters Agreement is for the sole purpose of formally
administering tests to products pursuant to the Khronos Conformance Process
Document.

Khronos, OpenKODE, OpenVG, OpenWF, glFX, OpenMAX and OpenSL ES are trademarks
of the Khronos Group Inc.  COLLADA is a trademark of Sony Computer
Entertainment Inc. used by permission by Khronos.  OpenGL and OpenML are
registered trademarks and the OpenGL ES logo is a trademark of Silicon Graphics
Inc. used by permission by Khronos. 

Use, duplication or disclosure by the Government is subject to restrictions as
set forth in subdivision (c)(1)(ii) of the Rights in Technical Data and
Computer Software clause at DFARS 252.227-7013, and/or in similar or successor
clauses in the FAR, DOD or NASA FAR Supplement. Unpublished rights reserved
under the Copyright Laws of the United States and other countries.
------------------------------------------------------------------------------*/

#include "../main.h"
#include "../util/util.h"

CT_Result G30117_PathStroking_by_ATI (CT_File *AnsFile)
{
    VGPaint fillpaint;
    VGPaint strokepaint;

	static const VGfloat strokeWidth = 8.f;

 VGPath path226;
 VGubyte  path226cmd[]={ /* 4 segments */
   VG_MOVE_TO_ABS    , VG_LINE_TO_ABS    , VG_LINE_TO_ABS    ,
   VG_CLOSE_PATH     };
 VGfloat path226coord[]={ /* 6 coordinates */
     0.000000e+000f,  -2.000000e+001f,   5.000000e+001f,   0.000000e+000f,   0.000000e+000f,   2.000000e+001f};

 VGPath path227;
 VGubyte  path227cmd[]={ /* 3 segments */
   VG_MOVE_TO_ABS    , VG_LINE_TO_ABS    , VG_LINE_TO_ABS    };
 VGfloat path227coord[]={ /* 6 coordinates */
     0.000000e+000f,  -2.050000e+001f,   1.000000e+001f,   0.000000e+000f,   0.000000e+000f,   2.050000e+001f};

    VGfloat matrix[9];
    VGfloat defaultColor[] = {1.0f, 1.0f, 1.0f, 1.0f};/*clear color  */                      

    path226=vgCreatePath(VG_PATH_FORMAT_STANDARD,VG_PATH_DATATYPE_F, 1.0000f,0.0000f, 0,0, (unsigned int)VG_PATH_CAPABILITY_APPEND_TO);
    vgAppendPathData(path226,sizeof(path226cmd)/sizeof(VGubyte),path226cmd,path226coord);
    path227=vgCreatePath(VG_PATH_FORMAT_STANDARD,VG_PATH_DATATYPE_F, 1.0000f,0.0000f, 0,0, (unsigned int)VG_PATH_CAPABILITY_APPEND_TO);
    vgAppendPathData(path227,sizeof(path227cmd)/sizeof(VGubyte),path227cmd,path227coord);

    if ( path226 == VG_INVALID_HANDLE )
        return CT_ERROR;
    if ( path227 == VG_INVALID_HANDLE )
        return CT_ERROR;

    fillpaint = vgCreatePaint();
    if ( fillpaint == VG_INVALID_HANDLE )
        return CT_ERROR;
    vgSetParameteri(fillpaint, VG_PAINT_TYPE, VG_PAINT_TYPE_COLOR);
    vgSetParameterfv(fillpaint, VG_PAINT_COLOR, 4, defaultColor);
    strokepaint = vgCreatePaint();
    if ( strokepaint == VG_INVALID_HANDLE )
        return CT_ERROR;
    vgSetParameteri(strokepaint, VG_PAINT_TYPE, VG_PAINT_TYPE_COLOR);
    vgSetParameterfv(strokepaint, VG_PAINT_COLOR, 4, defaultColor);

    vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
    vgLoadMatrix(matrix);

    vgSetfv(VG_CLEAR_COLOR, 4, defaultColor);
    vgClear(0, 0, WINDSIZEX, WINDSIZEY);
    vgSeti(VG_RENDERING_QUALITY, VG_RENDERING_QUALITY_NONANTIALIASED);

  matrix[0]=   1.000000e+000f; matrix[1]=   0.000000e+000f; matrix[2]=   0.000000e+000f;
  matrix[3]=   0.000000e+000f; matrix[4]=   1.000000e+000f; matrix[5]=   0.000000e+000f;
  matrix[6]=   0.500000e+001f; matrix[7]=   3.200000e+001f; matrix[8]=   1.000000e+000f;

  vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
  vgLoadMatrix(matrix);
  vgSetColor(fillpaint,0x00FF00FF);
  vgSetPaint(fillpaint, VG_FILL_PATH);
  vgSeti(VG_FILL_RULE,VG_NON_ZERO);
  vgSetColor(strokepaint,0x000000FF);
  vgSetPaint(strokepaint, VG_STROKE_PATH);
  vgSetf(VG_STROKE_LINE_WIDTH,strokeWidth);
  vgSetf(VG_STROKE_MITER_LIMIT,6.0000f);
  vgSeti(VG_STROKE_CAP_STYLE,VG_CAP_ROUND );
  vgSeti(VG_STROKE_JOIN_STYLE,VG_JOIN_ROUND);
  vgDrawPath(path226,VG_FILL_PATH|VG_STROKE_PATH);

  matrix[0]=   1.000000e+000f; matrix[1]=   0.000000e+000f; matrix[2]=   0.000000e+000f;
  matrix[3]=   0.000000e+000f; matrix[4]=   1.000000e+000f; matrix[5]=   0.000000e+000f;
  matrix[6]=   2.000000e+001f; matrix[7]=   3.200000e+001f; matrix[8]=   1.000000e+000f;
  vgSeti(VG_MATRIX_MODE, VG_MATRIX_PATH_USER_TO_SURFACE);
  vgLoadMatrix(matrix);
  vgSetColor(fillpaint,0x00FF00FF);
  vgSetPaint(fillpaint, VG_FILL_PATH);
  vgSeti(VG_FILL_RULE,VG_NON_ZERO);
  vgSetColor(strokepaint,0x000000FF);
  vgSetPaint(strokepaint, VG_STROKE_PATH);
  vgSetf(VG_STROKE_LINE_WIDTH,strokeWidth);
  vgSetf(VG_STROKE_MITER_LIMIT,6.0000f);
  vgSeti(VG_STROKE_CAP_STYLE,VG_CAP_ROUND );
  vgSeti(VG_STROKE_JOIN_STYLE,VG_JOIN_ROUND);
  vgDrawPath(path227,VG_FILL_PATH|VG_STROKE_PATH);

    vgDestroyPath(path226);
    vgDestroyPath(path227);
    
    vgDestroyPaint(fillpaint);
    vgDestroyPaint(strokepaint);

    if (vgGetError() == VG_NO_ERROR) {
        DISPLAY_TEST_BUFFER();    
        return CT_NO_ERROR;
    }
    else {
        return CT_ERROR;
    }
 }

