#ifndef NODECRF_HPP
#define NODECRF_HPP

#include <node.h>
#include "include/crfpp.h"

// Do not include this line. It's generally frowned upon to use namespaces
// in header files as it may cause issues with other code that includes your
// header file.
// using namespace v8;

class CRF : public node::ObjectWrap {
public:
    static v8::Persistent<v8::FunctionTemplate> constructor;
    static void Init(v8::Handle<v8::Object> target);

    //actual logic
    static v8::Handle<v8::Value> classify(const v8::Arguments& args);

protected:
    CRF();

    static v8::Handle<v8::Value> New(const v8::Arguments& args);
    static v8::Handle<v8::Value> getModel(const v8::Arguments& args);

    v8::Persistent<v8::String> model_;

    //Actual tagger
    v8::Persistent<CRFPP::Tagger> tagger;
private:
    static char *get(v8::Local<v8::Value> value, const char *fallback);
};

#endif
