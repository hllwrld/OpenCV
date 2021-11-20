//
// Created by mi on 2021/11/12.
//

#ifndef NATIVEBITMAP_BITMAPUTILS_H
#define NATIVEBITMAP_BITMAPUTILS_H

#include <android/bitmap.h>
#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jint JNICALL
Java_com_hllwrld_nativebitmap_BitmapUtils_grey(JNIEnv *env, jclass clazz, jobject bitmap) ;


#endif //NATIVEBITMAP_BITMAPUTILS_H
