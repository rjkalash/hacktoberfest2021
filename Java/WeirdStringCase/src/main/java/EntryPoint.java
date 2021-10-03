public class EntryPoint
{
    public static void main(String[] args)
    {
        printResults("string");
        printResults("This word");
    }

    public static void printResults(String input)
    {
        System.out.printf("%s\t->\t%s%n", input, FunUtils.toWeirdCase(input));
    }
}
