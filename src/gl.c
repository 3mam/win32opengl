#include "gl.h"

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
  glGenTextures = (pGenTextures)wglGetProcAddress("glGenTextures");
  glBindTexture = (pBindTexture)wglGetProcAddress("glBindTexture");
  glTexParameteri = (pTexParameteri)GetProcAddress(opengl32, "glTexParameteri");
  glTexImage2D = (pTexImage2D)GetProcAddress(opengl32, "glTexImage2D");
  glViewport = (pViewport)GetProcAddress(opengl32, "glViewport");
  glDrawArrays = (pDrawArrays)wglGetProcAddress("glDrawArrays");
  glEnable = (pEnable)GetProcAddress(opengl32, "glEnable");
  glClear = (pClear)GetProcAddress(opengl32, "glClear");
  glClearColor = (pClearColor)GetProcAddress(opengl32, "glClearColor");
  glGetString = (pGetString)GetProcAddress(opengl32, "glGetString");
  glCreateContextAttribsARB = (pCreateContextAttribsARB)wglGetProcAddress(
      "wglCreateContextAttribsARB");
  glChoosePixelFormatARB = (pChoosePixelFormatARB)wglGetProcAddress(
      "wglChoosePixelFormatARB");

  if (glGetString == NULL) return -1;
  if (glCreateShader == NULL) return -1;
  if (glShaderSource == NULL) return -1;
  if (glCompileShader == NULL) return -1;
  if (glCreateProgram == NULL) return -1;
  if (glAttachShader == NULL) return -1;
  if (glLinkProgram == NULL) return -1;
  if (glGetAttribLocation == NULL) return -1;
  if (glUseProgram == NULL) return -1;
  if (glGenBuffers == NULL) return -1;
  if (glBindBuffer == NULL) return -1;
  if (glBufferData == NULL) return -1;
  if (glEnableVertexAttribArray == NULL) return -1;
  if (glVertexAttribPointer == NULL) return -1;
  if (glGenTextures == NULL) return -1;
  if (glBindTexture == NULL) return -1;
  if (glTexParameteri == NULL) return -1;
  if (glTexImage2D == NULL) return -1;
  if (glViewport == NULL) return -1;
  if (glDrawArrays == NULL) return -1;
  if (glEnable == NULL) return -1;
  if (glClear == NULL) return -1;
  if (glClearColor == NULL) return -1;
  if (glCreateContextAttribsARB == NULL) return -1;
  if (glChoosePixelFormatARB == NULL) return -1;

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
