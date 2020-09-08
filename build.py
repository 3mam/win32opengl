import subprocess
import sys

COMPILER = 'C:\\tcc\\x86_64-win32-tcc.exe'
NAME = 'engine.exe'
PATH_SRC = 'src/'
LIBS = ['-lopengl32', '-lgdi32']
FILES = ['gl.c', 'main.c']

var = [COMPILER, '-mwindows', '-o', NAME] + LIBS + [PATH_SRC + x for x in FILES]
# print(var)

try:
  subprocess.check_call(var)
  subprocess.check_call(NAME)
except subprocess.CalledProcessError:
  sys.exit(1)
