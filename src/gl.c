#include "gl.h"

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

GLint glInit(void) {
  HINSTANCE opengl32 = LoadLibraryA("opengl32.dll");

  glCreateShader = (pCreateShader)wglGetProcAddress("glCreateShader");
  glShaderSource = (pShaderSource)wglGetProcAddress("glShaderSource");
  glCompileShader = (pCompileShader)wglGetProcAddress("glCompileShader");
  glCreateProgram = (pCreateProgram)wglGetProcAddress("glCreateProgram");
  glAttachShader = (pAttachShader)wglGetProcAddress("glAttachShader");
  glLinkProgram = (pLinkProgram)wglGetProcAddress("glLinkProgram");
  glGetAttribLocation =
      (pGetAttribLocation)wglGetProcAddress("glGetAttribLocation");
  glUseProgram = (pUseProgram)wglGetProcAddress("glUseProgram");
  glGenBuffers = (pGenBuffers)wglGetProcAddress("glGenBuffers");
  glBindBuffer = (pBindBuffer)wglGetProcAddress("glBindBuffer");
  glBufferData = (pBufferData)wglGetProcAddress("glBufferData");
  glEnableVertexAttribArray = (pEnableVertexAttribArray)wglGetProcAddress("glEnableVertexAttribArray");
  glVertexAttribPointer = (pVertexAttribPointer)wglGetProcAddress("glVertexAttribPointer");
  glGenTextures = (pGenTextures)GetProcAddress(opengl32,"glGenTextures");
  glBindTexture = (pBindTexture)GetProcAddress(opengl32,"glBindTexture");
  glTexParameteri = (pTexParameteri)GetProcAddress(opengl32, "glTexParameteri");
  glTexImage2D = (pTexImage2D)GetProcAddress(opengl32, "glTexImage2D");
  glViewport = (pViewport)GetProcAddress(opengl32, "glViewport");
  glDrawArrays = (pDrawArrays)GetProcAddress(opengl32,"glDrawArrays");
  glEnable = (pEnable)GetProcAddress(opengl32, "glEnable");
  glClear = (pClear)GetProcAddress(opengl32, "glClear");
  glClearColor = (pClearColor)GetProcAddress(opengl32, "glClearColor");
  glGetString = (pGetString)GetProcAddress(opengl32, "glGetString");
  glCreateContextAttribsARB = (pCreateContextAttribsARB)wglGetProcAddress(
      "wglCreateContextAttribsARB");
  glChoosePixelFormatARB = (pChoosePixelFormatARB)wglGetProcAddress(
      "wglChoosePixelFormatARB");

  if (glGetString == NULL) return -1;
  if (glCreateShader == NULL) return -2;
  if (glShaderSource == NULL) return -3;
  if (glCompileShader == NULL) return -4;
  if (glCreateProgram == NULL) return -5;
  if (glAttachShader == NULL) return -6;
  if (glLinkProgram == NULL) return -7;
  if (glGetAttribLocation == NULL) return -8;
  if (glUseProgram == NULL) return -9;
  if (glGenBuffers == NULL) return -10;
  if (glBindBuffer == NULL) return -11;
  if (glBufferData == NULL) return -12;
  if (glEnableVertexAttribArray == NULL) return -13;
  if (glVertexAttribPointer == NULL) return -14;
  if (glGenTextures == NULL) return -15;
  if (glBindTexture == NULL) return -16;
  if (glTexParameteri == NULL) return -17;
  if (glTexImage2D == NULL) return -18;
  if (glViewport == NULL) return -19;
  if (glDrawArrays == NULL) return -20;
  if (glEnable == NULL) return -21;
  if (glClear == NULL) return -22;
  if (glClearColor == NULL) return -23;
  if (glCreateContextAttribsARB == NULL) return -24;
  if (glChoosePixelFormatARB == NULL) return -25;

  return 1;
}

GLuint glShader(const GLchar *str, GLenum typ) {
  GLuint shader = (GLuint)glCreateShader(typ);
  glShaderSource(shader, 1, &str, NULL);
  glCompileShader(shader);
  // GLint success = 0;
  // glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  // printf("%d\n", success);
  return shader;
}

GLuint glCreateShaders(const GLchar *ver, const GLchar *frag) {
  GLuint verShader = glShader(ver, GL_VERTEX_SHADER);
  GLuint fragShader = glShader(frag, GL_FRAGMENT_SHADER);
  GLuint id = (GLuint)glCreateProgram();
  glAttachShader(id, verShader);
  glAttachShader(id, fragShader);
  glLinkProgram(id);

  return id;
}
