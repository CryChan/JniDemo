package pratice;

public class Jnitest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		Bussiness b = new Bussiness();
//		System.out.println(b.getPrice("Apple"));
		SayHelloToCpp sayHelloToCpp = new SayHelloToCpp();
		sayHelloToCpp.jniPrint("2");
	}

}
