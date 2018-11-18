# ADC2018
A collection of examples using emscripten for the audio developers conference.

1. Check out this repository recursively using the following command:
```
git clone --recursive https://github.com/olilarkin/ADC2018
```
2. [Download and install emscripten](http://kripken.github.io/emscripten-site/docs/getting_started/downloads.html), following the instructions carefully

3. add *source ./emsdk_env.sh* to your .bash_profile, so that you get the toolchain environment variables, you should be able to type ```emcc -v``` in a terminal and get the version number.

4. Edit /etc/mime.types to add a type for wasm. Add a single line as follows:

```application/wasm    wasm```

5. each folder has a shell script ```build.sh```, that should build and run the example

Oli Larkin


