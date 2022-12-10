#include <cstdio>
#include <iostream>

#include "FuzzedDataProvider.h"

#include "duckx.hpp"


extern "C" __attribute__((unused)) int LLVMFuzzerTestOneInput(const uint8_t *fuzz_data, size_t size) {
    FuzzedDataProvider fdp(fuzz_data, size);
    auto fuzz_file = fdp.ConsumeRemainingBytesAsFile();
    duckx::Document doc(fuzz_file.name);
    doc.open();

    for (auto p : doc.paragraphs()) {
        for(auto r : p.runs()) {
            r.get_text();
        }
    }
    return 0;
}