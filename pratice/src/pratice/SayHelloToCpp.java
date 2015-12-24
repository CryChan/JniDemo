package pratice;

public class SayHelloToCpp {

	static{  
		System.out.println(System.getProperty("java.library.path"));
        System.loadLibrary("libHelloEnd");  
    }  
    public SayHelloToCpp(){  
    }  
    public static native void jniPrint(String str);
      
}
