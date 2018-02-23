# Jni的简单使用  
## demo的运行环境
eclipse（j2ee）+ MinGW-w64 + CDT（plugin）  
eclipse和CDT的安装这里就不赘述，主要说的是MinGW-w64的安装。
MinGW-w64的安装：  
1.到sourceforge上下载一个MinGW-builds  
![](https://raw.githubusercontent.com/CryChan/JniDemo/master/pic/1.png)

2.打开根据机子的配置安装32/64bit版本：  
![](https://raw.githubusercontent.com/CryChan/JniDemo/master/pic/2.png)   
x86_64:64位的版本  
i686：32位的版本  

3.在"环境变量"中配置"PATH",在"PATH"中加入"${MinGW-w64}\bin;"  
其中：`${MinGW-w64}:MinGW-w64的安装目录`  
上述几步就是MinGW的安装和配置，只要正确安装好，后面的编译就不会有太多的错误

## demo的建立
1.新建一个java工程，在其中新建一个类`SayHelloToCpp`,这个类要包含一下代码：
  
	static{  
	        System.loadLibrary("lib***");  
	}
这个`lib***`是c++编译生成的.dll文件，为了让程序执行时找到，有两种设置方式。  
方法一：放在project指定的java.library.path中，java.library.path的配置在project-->properties中：
![](https://raw.githubusercontent.com/CryChan/JniDemo/master/pic/3.png)  
方法二：设置运行时的参数，依次点击run as--->run configurations,在点击Arguments，在Vm arguments处填入如下:  
`-Djava.library.path="${workspace_loc}\JniTest\libs;${env_var:PATH}"`

2.使用cmd进入这个project所在的目录，输入命令：`javah -classpath . -jni 类路径.JNIOpKey(提供的接口)`，这时候会生成一个`类路径.JNIOpKey(提供的接口).h`文件

3.把/jdk/include中的jni.h和/jdk/include/win32中的jni_md.h这两个文件copy出来，放到`类路径.JNIOpKey(提供的接口).h`所在的文件目录下

4.新建一个c++工程,选择按图中的的指示选择  
![](https://raw.githubusercontent.com/CryChan/JniDemo/master/pic/4.png)  
新建一个source文件，要注意的是：在命名的时候要加上文件的后缀。在这个文件中编写java调用c++的接口，编写完成后，在project上选择build project。build完成后会生成一个.dll文件，把.dll文件用上述的方法放置。

5.编写一个测试类，运行相关的接口

## 问题
1.出现错误：Can't load IA 32-bit .dll on a AMD 64-bit platform  
原因是C编译器生成的.dll文件是32位的，要重新安装一个64位的MinGW，然后重新生成一下文件就好了  

2.出现错误：java.lang.UnsatisfiedLinkError: no ** in java.library.path  
请确认java.library.path下有`**.dll`文件,一定要.dll文件才可以正常运行，编译生成的其他文件(.exe、.o等)是不能使程序正常运行的。
  
3.出现错误：类路径.JNIOpKey(提供的接口).h: No such file or directory之类的错误
把`#include <类路径.JNIOpKey(提供的接口).h>`和`#include <jni.h>`改成用`""`括起来

