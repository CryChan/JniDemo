/*
 * HelloEnd.cpp
 *
 *  Created on: 2015年12月23日
 *      Author: Administrator
 */
#include <iostream>
using namespace std;
#include "pratice_SayHelloToCpp.h"

JNIEXPORT void JNICALL Java_pratice_SayHelloToCpp_jniPrint
  (JNIEnv *env, jclass jthis, jstring str){
	jboolean iscopy = false;
	const char *charData = env->GetStringUTFChars(str, &iscopy);
	cout << "Hello, this is from JNI(dll)" <<endl;
	cout<<"The data from java is:"<<charData << endl;
	env->ReleaseStringUTFChars(str, charData);
}





