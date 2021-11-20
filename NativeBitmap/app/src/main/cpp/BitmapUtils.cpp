//
// Created by mi on 2021/11/12.
//

#include "BitmapUtils.h"

extern "C"
JNIEXPORT jint JNICALL
Java_com_hllwrld_nativebitmap_BitmapUtils_grey(JNIEnv *env, jclass clazz, jobject bitmap) {

    AndroidBitmapInfo bitmapInfo;
    int info_res = AndroidBitmap_getInfo(env, bitmap, &bitmapInfo);
    if (info_res != 0) {
        return -1;
    }

    void *pixels;
    AndroidBitmap_lockPixels(env, bitmap, &pixels);
    //f = 0.213f * r + 0.715f*g + 0.072f *b;
    int32_t *pixels_p = static_cast<int32_t *>(pixels);
    if (bitmapInfo.format == ANDROID_BITMAP_FORMAT_RGBA_8888) {
        for (int i = 0; i < bitmapInfo.height * bitmapInfo.width; i++) {
            int32_t pixel = *(pixels_p + i);
            int a = (pixel >> 24) & 0xff;
            int r = (pixel >> 16) & 0xff;
            int g = (pixel >> 8) & 0xff;
            int b = pixel & 0xff;
            int gery = (int) (0.213f * r + 0.715f * g + 0.072f * b);
            *(pixels_p+i) =  (a << 24) | (gery << 16) | (gery << 8) | gery;
        }
    } else {
        if (bitmapInfo.format == ANDROID_BITMAP_FORMAT_RGB_565) {
            for (int i = 0; i < bitmapInfo.height * bitmapInfo.width; i++) {
                int32_t pixel = *(pixels_p + i);
                int r = ((pixel >> 11) & 0x1f) << 3; // 5
                int g = ((pixel >> 5) & 0x3f) << 2; // 6
                int b = (pixel & 0x1f) << 3; // 5
                int gery = (int) (0.213f * r + 0.715f * g + 0.072f * b); // 8位
                *(pixels_p+i)  = ((gery >> 3) << 11) | ((gery >> 2) << 5) | (gery >> 3);
            }
        }
    }

    AndroidBitmap_unlockPixels(env, bitmap);
    return 1;
}