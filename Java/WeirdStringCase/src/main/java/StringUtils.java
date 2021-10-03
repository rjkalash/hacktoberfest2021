public class StringUtils
{
    public static boolean containsNonLettersAndNonWhitespace(String input)
    {
        for (int i = 0; i < input.length(); i++)
        {
            var inputChar = input.charAt(i);

            if (!Character.isLetter(inputChar) && !Character.isWhitespace(inputChar))
            {
                return true;
            }
        }

        return false;
    }
}
