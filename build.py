import subprocess
import sys
import os


COMPILER=''
if os.name == 'nt':
  COMPILER = 'C:\\tcc\\tcc.exe'
if os.name == 'posix':
  COMPILER = 'winegcc'

NAME = 'test.exe'
PATH_SRC = 'src/'
LIBS = ['-lopengl32', '-lgdi32']
FILES = ['gl.c', 'main.c']

var = [COMPILER, '-mwindows', '-lopengl32', '-o', NAME] + [PATH_SRC + x for x in FILES]

# print(var)

try:
  subprocess.check_call(var)
  if os.name == 'nt':
    subprocess.check_call(NAME)
  if os.name == 'posix':
    subprocess.check_call(['bash',NAME])
except subprocess.CalledProcessError:
  sys.exit(1)
