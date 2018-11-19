class MyWAM_AWP extends AudioWorkletGlobalScope.WAMProcessor
{
  constructor(options) {
    options = options || {}
    options.mod = AudioWorkletGlobalScope.WAM.MyWAM;
    super(options);
  }
}

registerProcessor("MyWAM", MyWAM_AWP);
