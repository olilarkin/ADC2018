emcc -s USE_GLFW=3 -s USE_WEBGL2=0 -s FULL_ES3=1 --emrun -o index.html main.c;
emrun --browser chrome index.html
