#ifndef APPINIT_H
#define APPINIT_H

#include <QObject>

#include "decision/constantdirective.h"
#include "decision/directive.h"
#include "decision/variabledirective.h"

namespace App {

void init() {
    // Register Metatypes
    // qRegisterMetaType<Directive*>();
    // qRegisterMetaType<ConstantDirective>();
    // qRegisterMetaType<VariableDirective>();
}

}

#endif // APPINIT_H
