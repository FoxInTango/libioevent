/*
 * libioevent
 *
 * Copyright (C) 2021 FoxInTango <foxintango@yeah.net>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */
#include "../include/libioevent.h"
using namespace foxintango;
#include <iostream>

int libioevent_startup(const Model& model) {
    ME* engines = model.subelementAt("engines");

    if(engines) {
        std::cout <<"engines found."<<std::endl;
        for(int i = 0;i < engines->subelementCount();i ++) {
            ModelElement& e = *(engines->subelementAt(i));
            if(e) {
                const char* s = "path";
                char* path = *(e[s]);
                Module* m = new Module(path);
                ModuleInterface* interface = m->interface();

                if(interface) {
                    IOEngine* engine = static_cast<IOEngine*>(interface->createObject("engine"));
                }
            }
        }
    }
    return 0;
}

int libioevent_shutdown() {
    return 0;
}
