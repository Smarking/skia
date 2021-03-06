/*
 * Copyright 2017 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SKSL_PIPELINESTAGECODEGENERATOR
#define SKSL_PIPELINESTAGECODEGENERATOR

#include "src/sksl/SkSLString.h"

// TODO: This can now be used in SKSL_STANDALONE, with shim code for all of the callbacks.
#if !defined(SKSL_STANDALONE) && SK_SUPPORT_GPU

namespace SkSL {

class FunctionDeclaration;
struct Program;
class VarDeclaration;

namespace PipelineStage {
    class Callbacks {
    public:
        virtual ~Callbacks() = default;
        virtual String declareUniform(const VarDeclaration*) = 0;
        virtual String defineFunction(const FunctionDeclaration*, String body) = 0;
        virtual String sampleChild(int index, String coords) = 0;
        virtual String sampleChildWithMatrix(int index, String matrix) = 0;
    };

    /*
     * Processes 'program' for use in a GrFragmentProcessor, or other context that wants SkSL-like
     * code as input. To support fragment processor usage, there are callbacks that allow elements
     * to be declared programmatically and to rename those elements (mangling to avoid collisions).
     *
     * - Any reference to the main coords builtin variable will be replaced with 'sampleCoords'.
     * - Each uniform variable declaration triggers a call to 'declareUniform', which should emit
     *   the declaration, and return the (possibly different) name to use for the variable.
     * - Each function definition triggers a call to 'defineFunction', which should emit the
     *   definition, and return the (possibly different) name to use for calls to that function.
     * - Each invocation of sample() triggers a call to 'sampleChild' or 'sampleChildWithMatrix',
     *   which should return the full text of the call expression.
     */
    void ConvertProgram(const Program& program,
                        const char* sampleCoords,
                        Callbacks* callbacks);
}  // namespace PipelineStage

}  // namespace SkSL

#endif

#endif
