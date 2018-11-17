rm MyWAM.js
rm MyWAM.wasm.js

emmake make

echo "
fs = require('fs');
let wasmData = fs.readFileSync(\"MyWAM.wasm\");
let wasmStr = wasmData.join(\",\");
let wasmOut = \"AudioWorkletGlobalScope.WAM = AudioWorkletGlobalScope.WAM || {}\\\n\";
wasmOut += \"AudioWorkletGlobalScope.WAM.MyWAM = { ENVIRONMENT: 'WEB' }\\\n\";
wasmOut += \"AudioWorkletGlobalScope.WAM.MyWAM.wasmBinary = new Uint8Array([\" + wasmStr + \"]);\";
fs.writeFileSync(\"MyWAM.wasm.js\", wasmOut);
" > encode-wasm.js
node encode-wasm.js
rm encode-wasm.js

emrun --browser chrome MyWAM.html
