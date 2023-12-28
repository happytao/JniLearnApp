//
// Created by Hille on 2022/12/28.
//
#include <string.h>
#include "hello-jni.h"
#include <jni.h>
#include <malloc.h>
#include <android/log.h>

#define LOG(...) __android_log_print(ANDROID_LOG_INFO, "Tag", __VA_ARGS__)

JNIEXPORT jstring JNICALL
Java_com_example_hellojni_HelloJni_stringFromJni(JNIEnv *env, jclass clazz) {
    char hello[] = "hello from jni";
    return (* env)->NewStringUTF(env,hello);
}

JNIEXPORT jbyteArray JNICALL
Java_com_example_hellojni_HelloJni_getBytesFromJni(JNIEnv *env, jclass clazz, jbyteArray my_bytes) {
    jbyte *java_bytes;
    jbyte *c_bytes;
    jint my_bytes_len = (* env)->GetArrayLength(env, my_bytes);
    LOG("c length = %d",my_bytes_len);
    java_bytes = (jbyte *)malloc(my_bytes_len * sizeof(jbyte));
    c_bytes = (jbyte *)malloc(my_bytes_len * sizeof(jbyte));
    (* env)->GetByteArrayRegion(env, my_bytes, 0, my_bytes_len, java_bytes);
    for(int i = 0; i < my_bytes_len; i++) {
        c_bytes[i] = java_bytes[my_bytes_len - i - 1];
    }
    jbyteArray ret_array = (* env)->NewByteArray(env, my_bytes_len);
    (* env)->SetByteArrayRegion(env,ret_array, 0, my_bytes_len, c_bytes);
    free(java_bytes);
    free(c_bytes);
    return ret_array;

}