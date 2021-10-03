public class FunUtils
{
    public static String toWeirdCase(String input)
    {
        if (input == null)
        {
            throw new IllegalArgumentException("input cannot be null");
        }
        else if (StringUtils.containsNonLettersAndNonWhitespace(input))
        {
            throw new IllegalArgumentException("input can only contain whitespaces and letters");
        }

        var resultBuilder = new StringBuilder(input.length());

        for (int i = 0; i < input.length(); i++)
        {
            var inputChar = input.charAt(i);

            if (i % 2 == 0)
            {
                resultBuilder.append(Character.toUpperCase(inputChar));
            }
            else
            {
                resultBuilder.append(Character.toLowerCase(inputChar));
            }
        }

        return resultBuilder.toString();
    }
}
