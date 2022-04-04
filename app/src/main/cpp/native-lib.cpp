#include <jni.h>
#include <string>
#define LOG_TAG "HelloStub"

#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <istream>
#include <unistd.h>
#include <string>
#define DEVICE_NAME "/dev/hello"
#define MODULE_NAME "Hello"
#define MODULE_AUTHOR "shyluo@gmail.com"

/*设备打开和关闭接口*/
static int hello_device_open(const struct hw_module_t* module, const char* name, struct hw_device_t** device);
static int hello_device_close(struct hw_device_t* device);

/*设备访问接口*/
static int hello_set_val(struct hello_device_t* dev, int val);
static int hello_get_val(struct hello_device_t* dev, int* val);



extern "C" JNIEXPORT jstring JNICALL
Java_com_vaca_myapplication_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    int val2=0;
    int *val=&val2;
    int fd=open(DEVICE_NAME, O_RDWR);
 //   write(fd, val, sizeof(*val));
    read(fd, val, sizeof(*val));
    close(fd);
    std::string hello = "Hello from C++"+std::to_string(val2);
    return env->NewStringUTF(hello.c_str());
}