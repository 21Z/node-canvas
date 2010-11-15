
//
// ImageData.cc
//
// Copyright (c) 2010 LearnBoost <tj@learnboost.com>
//

#include "ImageData.h"

/*
 * Initialize ImageData.
 */

void
ImageData::Initialize(Handle<Object> target) {
  HandleScope scope;
  Local<FunctionTemplate> t = FunctionTemplate::New(ImageData::New);
  t->InstanceTemplate()->SetInternalFieldCount(1);
  t->SetClassName(String::NewSymbol("ImageData"));

  // Prototype
  Local<ObjectTemplate> proto = t->PrototypeTemplate();
  proto->SetAccessor(String::NewSymbol("width"), GetWidth);
  proto->SetAccessor(String::NewSymbol("height"), GetHeight);
  target->Set(String::NewSymbol("ImageData"), t->GetFunction());
}

/*
 * Initialize a new ImageData object.
 */

Handle<Value>
ImageData::New(const Arguments &args) {
  HandleScope scope;
  // TODO: arg assertions
  PixelArray *arr = ObjectWrap::Unwrap<PixelArray>(args[0]->ToObject());
  ImageData *imageData = new ImageData(arr);
  args.This()->Set(String::NewSymbol("data"), args[0]);
  imageData->Wrap(args.This());
  return args.This();
}

/*
 * Get width.
 */

Handle<Value>
ImageData::GetWidth(Local<String> prop, const AccessorInfo &info) {
  ImageData *imageData = ObjectWrap::Unwrap<ImageData>(info.This());
  return Number::New(imageData->pixelArray()->width());
}

/*
 * Get height.
 */

Handle<Value>
ImageData::GetHeight(Local<String> prop, const AccessorInfo &info) {
  ImageData *imageData = ObjectWrap::Unwrap<ImageData>(info.This());
  return Number::New(imageData->pixelArray()->height());
}
