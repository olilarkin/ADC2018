# ADC2018
A collection of examples using emscripten for the audio developers conference.

```
git clone --recursive https://github.com/olilarkin/ADC2018
```

[Download and install emscripten](http://kripken.github.io/emscripten-site/docs/getting_started/downloads.html), following the instructions carefully

add *source ./emsdk_env.sh* to your .bash_profile, so that you get the toolchain environment variables, you should be able to type

```emcc -v```

in a terminal and get the version number.

each folder has a shell script build.sh, that should build and run the example

Oli Larkin


