#include <stdio.h>
#include <emscripten.h>

//call to write to sync file system to IndexedDB
EMSCRIPTEN_KEEPALIVE void syncfs()
{
  EM_ASM({
    if(Module.syncdone == 1) {
      Module.syncdone = 0;
      FS.syncfs(false, function (err) {
        assert(!err);
        console.log("Synced to IDBFS...");
        Module.syncdone = 1;
      });
    }
  });
}

EMSCRIPTEN_KEEPALIVE void fsready()
{
  syncfs();
}

int main()
{
  EM_ASM(
     var name = "/ADC2018";
     FS.mkdir(name);
     FS.mount(IDBFS, {}, name);
     Module.syncdone = 0;
     FS.syncfs(true, function (err) {
      assert(!err);
      console.log("Synced from IDBFS...");
      Module.syncdone = 1;
      ccall('fsready', 'v');
    });
  );
  
  //TODO: check for HelloWorld.txt existance and print it!
  FILE* pFile;
  pFile = fopen("/ADC2018/HelloWorld.txt", "w");
  
  if (pFile != NULL)
  {
    fputs("HelloWorld", pFile);
    fclose(pFile);
    printf("wrote HelloWorld.txt");
    syncfs();
  }
  
  emscripten_exit_with_live_runtime();
  
  return 0;
}
