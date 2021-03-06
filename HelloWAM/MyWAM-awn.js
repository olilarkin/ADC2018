class MyWAMController extends WAMController
{
  constructor (actx, options) {
    options = options || {};
    options.numberOfInputs  = 0;
    options.numberOfOutputs = 1;
    options.outputChannelCount = [2];

    super(actx, "MyWAM", options);
  }

  static importScripts (actx) {
    var origin = location.origin + "/";
    return new Promise( (resolve) => {
         actx.audioWorklet.addModule(origin + "MyWAM.js").then(() => {
          actx.audioWorklet.addModule(origin + "wam/wamsdk/wam-processor.js").then(() => {
            actx.audioWorklet.addModule(origin + "MyWAM-awp.js").then(() => {
              resolve();
      }) }) });
    })
  }

  onmessage(msg) {
    if(msg.type == "descriptor") {
      createGUI(msg.data.parameters);
    }
  }
}
