function factors()
{
    let no=prompt("No. to display Factor: ");
    //no=parseInt(no);
    for (var i=1;i<=no;i++)
    {
        if (no%i==0)
        {
            document.write(i+ " ");
        }
    }
}

factors();

function factorial()
{
    let no=prompt("Factorial: ");
  
    var a=1;
    for (var i=1;i<=no;i++)
    {
        a*=i;
    }
   document.write(a);
}
factorial();

function fibonacci()
{
    let no=prompt("No. of terms for Fibonacci Series: ");
    var a=0;
    var b=1;
    for (var i=1;i<=no;i++)
    {
        document.write(a+" ");
        var c=a+b;
        a=b;
        b=c;
    }
}
fibonacci();

function palindrome()
{
    let no=prompt("Number to check the palindrome: ");
    no=parseInt(no);
   var rev=0,rema,no1;
    no1=no;
    while (no!=0)
    {
        rem=no%10;
        rev=rev*10+rem;
        no=parseInt(no/10);
   }

    (no1==rev)?document.write("palindrome"):document.write("not palindrome");
}

palindrome();

function armstrong()
{
    let no,no1, rem,res=0,digit_count=0;
    no=prompt("Number to check Armstrong: ");
    no=parseInt(no);
    no1=no;
    while (no!=0)
    {
        no=parseInt(no/10);
        digit_count++;
    }

   no=no1;
    while (no1!=0)
    {
        rem=no1%10;
        res+=rem**digit_count;
        no1=parseInt(no1/10);
    }
    (res==no)?document.write("yes armstrong"):document.write("no armstrong");
}

armstrong();