# ADC2018
A collection of examples using emscripten for the audio developers conference.
Code is mostly extracted and simplified from the emscripten tests.

* Check out this repository recursively using the following command:
```
git clone --recursive https://github.com/olilarkin/ADC2018
```
* [Download and install emscripten](http://kripken.github.io/emscripten-site/docs/getting_started/downloads.html), following the instructions carefully

* Add *source PATH_TO_EMSDK_DIR/emsdk_env.sh* to your .bash_profile, so that you get the toolchain environment variables Each time you launch the terminal. You should be able to type ```emcc -v``` in a terminal and get the version number.

* Edit /etc/mime.types to add a type for wasm. Add a single line as follows:

```application/wasm    wasm```

* Each folder has a shell script ```build.sh```, that should build and run the example.

Enjoy!

Oli Larkin


