rm MyWAM.js

emmake make

echo "AudioWorkletGlobalScope.WAM = AudioWorkletGlobalScope.WAM || {}; AudioWorkletGlobalScope.WAM.MyWAM = { ENVIRONMENT: 'WEB' };" > MyWAM.tmp.js;
cat MyWAM.js >> MyWAM.tmp.js
mv MyWAM.tmp.js MyWAM.js

emrun --no_emrun_detect --browser chrome MyWAM.html
