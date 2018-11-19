TARGET = ./MyWAM.js

SRC = MyWAM.cpp wam/wamsdk/processor.cpp

CFLAGS = -std=c++11 -I./wam/wamsdk

EXPORTS = "[\
  '_createModule','_wam_init','_wam_terminate','_wam_resize', \
  '_wam_onprocess', '_wam_onmidi', '_wam_onsysex', '_wam_onparam', \
  '_wam_onmessageN', '_wam_onmessageS', '_wam_onmessageA', '_wam_onpatch' \
  ]"

LDFLAGS = -s EXPORTED_FUNCTIONS=$(EXPORTS) -s EXTRA_EXPORTED_RUNTIME_METHODS="['ccall', 'cwrap', 'setValue']" -O2
JSFLAGS = -s EXPORT_NAME="'AudioWorkletGlobalScope.WAM.MyWAM'" -s ALLOW_MEMORY_GROWTH=1 -s BINARYEN_ASYNC_COMPILATION=0

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(JSFLAGS) -o $@ $(SRC)