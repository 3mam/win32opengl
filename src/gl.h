#ifndef GL_H
#define GL_H

#include <windows.h>
typedef unsigned int GLubyte;
typedef char GLchar;
typedef unsigned int GLuint;
typedef unsigned int GLenum;
typedef unsigned int GLbitfield;
typedef int GLint;
typedef int GLsizei;
typedef float GLfloat;
typedef double GLdouble;
typedef float GLclampf;
typedef int GLsizei;
typedef unsigned int GLsizeiptr;
typedef void GLvoid;
typedef unsigned char GLboolean;

typedef GLuint(APIENTRY *pCreateShader)(GLenum);
typedef void(APIENTRY *pShaderSource)(GLuint, GLsizei, const GLchar **,
                                      const GLint *);
typedef void(APIENTRY *pCompileShader)(GLuint);
typedef GLuint(APIENTRY *pCreateProgram)(void);
typedef void(APIENTRY *pAttachShader)(GLuint, GLuint);
typedef void(APIENTRY *pLinkProgram)(GLuint);
typedef GLuint(APIENTRY *pGetAttribLocation)(GLuint, const GLchar *);
typedef void(APIENTRY *pUseProgram)(GLuint);
typedef void(APIENTRY *pGenBuffers)(GLsizei, GLuint *);
typedef void(APIENTRY *pBindBuffer)(GLenum, GLuint);
typedef void(APIENTRY *pBufferData)(GLenum, GLsizeiptr, const GLvoid *, GLenum);
typedef void(APIENTRY *pEnableVertexAttribArray)(GLuint);
typedef void(APIENTRY *pVertexAttribPointer)(GLuint, GLint, GLenum, GLboolean,
                                             GLsizei, const GLvoid *);
typedef void(APIENTRY *pGenTextures)(GLsizei, GLuint *);
typedef void(APIENTRY *pBindTexture)(GLenum, GLuint);
typedef void(APIENTRY *pTexParameteri)(GLenum, GLenum, GLint);
typedef void(APIENTRY *pTexImage2D)(GLenum, GLint, GLint, GLsizei, GLsizei,
                                    GLint, GLenum, GLenum, const GLvoid *);
typedef void(APIENTRY *pViewport)(GLint, GLint, GLsizei, GLsizei);
typedef void(APIENTRY *pDrawArrays)(GLenum, GLint, GLsizei);
typedef void(APIENTRY *pEnable)(GLenum);
typedef void(APIENTRY *pClear)(GLbitfield);
typedef void(APIENTRY *pClearColor)(GLclampf, GLclampf, GLclampf, GLclampf);

typedef const GLubyte(APIENTRY *pGetString)(GLenum);

typedef HGLRC(APIENTRY *pCreateContextAttribsARB)(HDC, HGLRC, const int *);
typedef BOOL(APIENTRY *pChoosePixelFormatARB)(HDC, const int *,
                                              const FLOAT *, UINT, int *, UINT *);

#define GL_FRAGMENT_SHADER 0x8B30
#define GL_VERTEX_SHADER 0x8B31
#define GL_ARRAY_BUFFER 0x8892
#define GL_STATIC_DRAW 0x88E4
#define GL_FLOAT 0x1406
#define GL_TEXTURE_2D 0x0DE1
#define GL_TEXTURE_WRAP_S 0x2802
#define GL_TEXTURE_WRAP_T 0x2803
#define GL_CLAMP_TO_EDGE 0x812F
#define GL_REPEAT 0x2901
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_TEXTURE_MIN_FILTER 0x2801
#define GL_NEAREST 0x2600
#define GL_LINEAR 0x2601
#define GL_NEAREST_MIPMAP_NEAREST 0x2700
#define GL_LINEAR_MIPMAP_NEAREST 0x2701
#define GL_NEAREST_MIPMAP_LINEAR 0x2702
#define GL_LINEAR_MIPMAP_LINEAR 0x2703
#define GL_RGBA 0x1908
#define GL_RGB 0x1907
#define GL_UNSIGNED_BYTE 0x1401
#define GL_UNSIGNED_INT_8_8_8_8 0x8035
#define GL_TRIANGLES 0x0004
#define GL_POINTS 0x0000
#define GL_COLOR_BUFFER_BIT 0x00004000
#define GL_DEPTH_BUFFER_BIT 0x00000100
#define GL_BLEND 0x0BE2
#define GL_SRC_ALPHA 0x0302
#define GL_ONE_MINUS_SRC_ALPHA 0x0303

#define WGL_CONTEXT_MAJOR_VERSION_ARB 0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB 0x2092
#define WGL_CONTEXT_PROFILE_MASK_ARB 0x9126
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB 0x00000001

#define GL_VENDOR 0x1F00
#define GL_RENDERER 0x1F01
#define GL_VERSION 0x1F02
#define GL_EXTENSIONS 0x1F03

#define GL_TRUE 1
#define GL_FALSE 0

#define WGL_NUMBER_PIXEL_FORMATS_ARB 0x2000
#define WGL_DRAW_TO_WINDOW_ARB 0x2001
#define WGL_DRAW_TO_BITMAP_ARB 0x2002
#define WGL_ACCELERATION_ARB 0x2003
#define WGL_NEED_PALETTE_ARB 0x2004
#define WGL_NEED_SYSTEM_PALETTE_ARB 0x2005
#define WGL_SWAP_LAYER_BUFFERS_ARB 0x2006
#define WGL_SWAP_METHOD_ARB 0x2007
#define WGL_NUMBER_OVERLAYS_ARB 0x2008
#define WGL_NUMBER_UNDERLAYS_ARB 0x2009
#define WGL_TRANSPARENT_ARB 0x200A
#define WGL_TRANSPARENT_RED_VALUE_ARB 0x2037
#define WGL_TRANSPARENT_GREEN_VALUE_ARB 0x2038
#define WGL_TRANSPARENT_BLUE_VALUE_ARB 0x2039
#define WGL_TRANSPARENT_ALPHA_VALUE_ARB 0x203A
#define WGL_TRANSPARENT_INDEX_VALUE_ARB 0x203B
#define WGL_SHARE_DEPTH_ARB 0x200C
#define WGL_SHARE_STENCIL_ARB 0x200D
#define WGL_SHARE_ACCUM_ARB 0x200E
#define WGL_SUPPORT_GDI_ARB 0x200F
#define WGL_SUPPORT_OPENGL_ARB 0x2010
#define WGL_DOUBLE_BUFFER_ARB 0x2011
#define WGL_STEREO_ARB 0x2012
#define WGL_PIXEL_TYPE_ARB 0x2013
#define WGL_COLOR_BITS_ARB 0x2014
#define WGL_RED_BITS_ARB 0x2015
#define WGL_RED_SHIFT_ARB 0x2016
#define WGL_GREEN_BITS_ARB 0x2017
#define WGL_GREEN_SHIFT_ARB 0x2018
#define WGL_BLUE_BITS_ARB 0x2019
#define WGL_BLUE_SHIFT_ARB 0x201A
#define WGL_ALPHA_BITS_ARB 0x201B
#define WGL_ALPHA_SHIFT_ARB 0x201C
#define WGL_ACCUM_BITS_ARB 0x201D
#define WGL_ACCUM_RED_BITS_ARB 0x201E
#define WGL_ACCUM_GREEN_BITS_ARB 0x201F
#define WGL_ACCUM_BLUE_BITS_ARB 0x2020
#define WGL_ACCUM_ALPHA_BITS_ARB 0x2021
#define WGL_DEPTH_BITS_ARB 0x2022
#define WGL_STENCIL_BITS_ARB 0x2023
#define WGL_AUX_BUFFERS_ARB 0x2024
#define WGL_NO_ACCELERATION_ARB 0x2025
#define WGL_GENERIC_ACCELERATION_ARB 0x2026
#define WGL_FULL_ACCELERATION_ARB 0x2027
#define WGL_SWAP_EXCHANGE_ARB 0x2028
#define WGL_SWAP_COPY_ARB 0x2029
#define WGL_SWAP_UNDEFINED_ARB 0x202A
#define WGL_TYPE_RGBA_ARB 0x202B
#define WGL_TYPE_COLORINDEX_ARB 0x202C

#define WGL_SAMPLE_BUFFERS_ARB 0x2041
#define WGL_SAMPLES_ARB 0x2042

pCreateContextAttribsARB glCreateContextAttribsARB;
pChoosePixelFormatARB glChoosePixelFormatARB;

pGetString glGetString;
pCreateShader glCreateShader;
pShaderSource glShaderSource;
pCompileShader glCompileShader;
pCreateProgram glCreateProgram;
pAttachShader glAttachShader;
pLinkProgram glLinkProgram;
pGetAttribLocation glGetAttribLocation;
pUseProgram glUseProgram;
pGenBuffers glGenBuffers;
pBindBuffer glBindBuffer;
pBufferData glBufferData;
pEnableVertexAttribArray glEnableVertexAttribArray;
pVertexAttribPointer glVertexAttribPointer;
pGenTextures glGenTextures;
pBindTexture glBindTexture;
pTexParameteri glTexParameteri;
pTexImage2D glTexImage2D;
pViewport glViewport;
pDrawArrays glDrawArrays;
pEnable glEnable;
pClear glClear;
pClearColor glClearColor;

GLint glInit();
GLuint glShader(const GLchar *, GLenum);
GLuint glCreateShaders(const GLchar *, const GLchar *);
#endif  // GL_H
