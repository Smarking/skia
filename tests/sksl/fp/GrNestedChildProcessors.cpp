

/**************************************************************************************************
 *** This file was autogenerated from GrNestedChildProcessors.fp; do not modify.
 **************************************************************************************************/
#include "GrNestedChildProcessors.h"

#include "src/core/SkUtils.h"
#include "src/gpu/GrTexture.h"
#include "src/gpu/glsl/GrGLSLFragmentProcessor.h"
#include "src/gpu/glsl/GrGLSLFragmentShaderBuilder.h"
#include "src/gpu/glsl/GrGLSLProgramBuilder.h"
#include "src/sksl/SkSLCPP.h"
#include "src/sksl/SkSLUtil.h"
class GrGLSLNestedChildProcessors : public GrGLSLFragmentProcessor {
public:
    GrGLSLNestedChildProcessors() {}
    void emitCode(EmitArgs& args) override {
        GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;
        const GrNestedChildProcessors& _outer = args.fFp.cast<GrNestedChildProcessors>();
        (void) _outer;
        colorVar = args.fUniformHandler->addUniform(&_outer, kFragment_GrShaderFlag, kHalf4_GrSLType, "color");
        SkString _input1 = SkStringPrintf("%s * half4(0.5)", args.fUniformHandler->getUniformCStr(colorVar));
        SkString _sample1 = this->invokeChild(0, _input1.c_str(), args);
        SkString _input0 = SkStringPrintf("%s * %s", args.fUniformHandler->getUniformCStr(colorVar), _sample1.c_str());
        SkString _sample0 = this->invokeChild(1, _input0.c_str(), args);
        fragBuilder->codeAppendf(
R"SkSL(return %s;
)SkSL"
, _sample0.c_str());
    }
private:
    void onSetData(const GrGLSLProgramDataManager& pdman, const GrFragmentProcessor& _proc) override {
    }
    UniformHandle colorVar;
};
GrGLSLFragmentProcessor* GrNestedChildProcessors::onCreateGLSLInstance() const {
    return new GrGLSLNestedChildProcessors();
}
void GrNestedChildProcessors::onGetGLSLProcessorKey(const GrShaderCaps& caps, GrProcessorKeyBuilder* b) const {
}
bool GrNestedChildProcessors::onIsEqual(const GrFragmentProcessor& other) const {
    const GrNestedChildProcessors& that = other.cast<GrNestedChildProcessors>();
    (void) that;
    return true;
}
GrNestedChildProcessors::GrNestedChildProcessors(const GrNestedChildProcessors& src)
: INHERITED(kGrNestedChildProcessors_ClassID, src.optimizationFlags()) {
        this->cloneAndRegisterAllChildProcessors(src);
}
std::unique_ptr<GrFragmentProcessor> GrNestedChildProcessors::clone() const {
    return std::make_unique<GrNestedChildProcessors>(*this);
}
#if GR_TEST_UTILS
SkString GrNestedChildProcessors::onDumpInfo() const {
    return SkString();
}
#endif
