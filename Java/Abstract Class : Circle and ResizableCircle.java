import java.util.Scanner;
// Other imports go here
interface GeometricObject 
{
   public double getPerimeter();
   public double getArea();
}
interface Resizable 
{
   public void resize(int percent);
}
class Circle implements GeometricObject
{
  protected double radius;
  Circle(double rad) {
    radius = rad;
  }
  public double getPerimeter(){
    return 2*3.14*radius;
  }
  public double getArea(){
    return 3.14*radius*radius;
  }
  public String toString(){
   return("Circle[radius="+radius+"]");
  }
}

class ResizableCircle extends Circle implements Resizable
{
  
   ResizableCircle(double r){
	   super(r);
    }
  
  public double getPerimeter(){
  
  double d = (double)Math.round(2*3.14159*super.radius*100)/100;
    return d;
   
  }
  public double getArea(){
 
  double d = (double)Math.round(3.14159*super.radius*super.radius*100)/100;
    return d;
   
  }
  public void resize(int percent){
  super.radius = super.radius*percent/100;
  }
  
  public String toString(){
   return("Circle[radius="+super.radius+"]");
  }
  class Main{
  public static void main(String[] args)
  {
    double r;
    int p;
    Scanner s1=new Scanner(System.in);
    r=s1.nextDouble();
    Circle c1=new Circle(r);
    System.out.println(c1);
    System.out.println(String.format("%.2f", c1.getPerimeter()));
    System.out.println(String.format("%.2f", c1.getArea()));
    
    r=s1.nextDouble();
    ResizableCircle c2=new ResizableCircle(r);
    System.out.println(c2);
    System.out.println(String.format("%.2f", c2.getPerimeter()));
    System.out.println(String.format("%.2f", c2.getArea()));
    p=s1.nextInt();
    c2.resize(p);
    System.out.println(String.format("%.2f", c2.getPerimeter()));
    System.out.println(String.format("%.2f", c2.getArea()));
  }
}
