TARGET = index.html

SRC = main.c nanovg/src/nanovg.c #nanovg/example/perf.c

EXPORTS = "['_main','_nvgBeginFrame','_nvgCancelFrame','_nvgEndFrame','_nvgGlobalCompositeOperation','_nvgGlobalCompositeBlendFunc','_nvgGlobalCompositeBlendFuncSeparate','_nvgRGB','_nvgRGBf','_nvgRGBA','_nvgRGBAf','_nvgLerpRGBA','_nvgTransRGBA','_nvgTransRGBAf','_nvgHSL','_nvgHSLA','_nvgSave','_nvgRestore','_nvgReset','_nvgShapeAntiAlias','_nvgStrokeColor','_nvgStrokePaint','_nvgFillColor','_nvgFillPaint','_nvgMiterLimit','_nvgStrokeWidth','_nvgLineCap','_nvgLineJoin','_nvgGlobalAlpha','_nvgResetTransform','_nvgTransform','_nvgTranslate','_nvgRotate','_nvgSkewX','_nvgSkewY','_nvgScale','_nvgCurrentTransform','_nvgTransformIdentity','_nvgTransformTranslate','_nvgTransformScale','_nvgTransformRotate','_nvgTransformSkewX','_nvgTransformSkewY','_nvgTransformMultiply','_nvgTransformPremultiply','_nvgTransformInverse','_nvgTransformPoint','_nvgDegToRad','_nvgRadToDeg','_nvgImageSize','_nvgDeleteImage','_nvgLinearGradient','_nvgBoxGradient','_nvgRadialGradient','_nvgImagePattern','_nvgScissor','_nvgIntersectScissor','_nvgResetScissor','_nvgBeginPath','_nvgMoveTo','_nvgLineTo','_nvgBezierTo','_nvgQuadTo','_nvgArcTo','_nvgClosePath','_nvgPathWinding','_nvgArc','_nvgRect','_nvgRoundedRect','_nvgRoundedRectVarying','_nvgEllipse','_nvgCircle','_nvgFill','_nvgStroke','_nvgCreateGLES2','_nvgDeleteGLES2','_nvglCreateImageFromHandleGLES2','_nvglImageHandleGLES2','_nvgCreateFont','_nvgCreateFontMem','_nvgFindFont','_nvgAddFallbackFontId','_nvgAddFallbackFont','_nvgFontSize','_nvgFontBlur','_nvgTextLetterSpacing','_nvgTextLineHeight','_nvgTextAlign','_nvgFontFaceId','_nvgFontFace','_nvgText','_nvgTextBox','_nvgTextBounds','_nvgTextBoxBounds','_nvgTextGlyphPositions','_nvgTextMetrics','_nvgTextBreakLines']"

CFLAGS = -I./ -Inanovg/src/ -O2
LDFLAGS = -s EXPORTED_FUNCTIONS=$(EXPORTS) --emrun
JSFLAGS = -s BINARYEN_ASYNC_COMPILATION=1 -s ALLOW_MEMORY_GROWTH=1 -s WASM=1 -s USE_GLFW=3 -s USE_WEBGL2=1 -s FULL_ES3=1 -s ASSERTIONS=0 --preload-file resources/@/
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(JSFLAGS) -o $@ $(SRC)
