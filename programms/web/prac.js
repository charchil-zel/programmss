



function factors(no)
{
    for (var i=1;i<=no;i++)
    {
        if (no%i==0)
        
            document.write(i+ " ");
        
    }
}
let no=prompt("No. to display Factor: ");
factors(no);
/*
function factorial(no)
{
  
    var a=1;
    for (var i=1;i<=no;i++)
    {
        a*=i;
    }
   document.write(a);
}
let no=prompt("Number: ");
factorial(no);

function fibonacci(no)
{
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
let no=prompt("No. of terms for the series: ");
fibonacci(no);

function palindrome(no)
{
   var rev=0,rem,no1;
    no1=no;
    while (no!=0)
    {
        rem=no%10;
        rev=rev*10+rem;
        no=parseInt(no/10);
   }

    return (no1==rev)?true:false;
}
let no=prompt("Number to check the palindrome: ");
(palindrome(no)==true)?document.write("yes palindrome"):document.write("no palindrome");
/*
function armstrong(no)
{
    let no1, rem,res=0,digit=0;
    no1=no;
    while (no!=0)
    {
        no=parseInt(no/10);
        digit++;
    }
    no=no1;
    while (no1!=0)
    {
        rem=no1%10;
        res+=rem**digit;
        no1=parseInt(no1/10);
    }
    return (res==no)?true:false;
}
    let no=prompt("Number to check Armstrong: ");

    if (armstrong(no))
    
        document.write("yes armstrong");
    
    else
    
        document.write("no armstrong"); 
    */



