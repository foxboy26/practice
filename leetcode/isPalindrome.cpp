bool isPalindrome(string s) {
  int len = s.length();
  int i = 0, j = len-1;
  while (i < j)
  {
    if (isalnum(s[i]) && isalnum(s[j]))
    {
      if (tolower(s[i]) == tolower(s[j]))
      {
        i++;
        j--;
      }
      else
        return false;
    }
    else
    {
      if (!isalnum(s[i])) i++;

      if (!isalnum(s[j])) j--;
    }
  }

  return true;
}
