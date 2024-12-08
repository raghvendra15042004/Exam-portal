import java.util.*;
class Try
{
    public static void main(String args[])
    {
        Scanner in=new Scanner(System.in);
        int s=in.nextInt();
        char arr[][]=new char[s][s];
        String str=new String();
        for(int i=0;i<s;i++)
        {
            str=in.next();
            arr[i]=str.toCharArray();
        }
        int arr1[]=new int[100];
        int c=0;
        for(int i=0;i<s;i++)
        {
            for(int j=0;j<s;j++)
            {
                if(arr[i][j]!='.')
                {
                    if(arr[i+1][j]==arr[i-1][j] && arr[i][j+1]==arr[i][j-1])
                    {
                        arr1[c]=arr[i][j];
                    }
                }
            }
        }
        for(int k=0;k<)
    }
}