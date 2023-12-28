        function valname()
        {
            if (document.forms["myform"]["mname"].value=="")
            {
                document.getElementById("pi").innerHTML="** Enter Name";
                return false;
            }
        }

        function valpass()
        {
            (document.forms["myform"]["pass"].value === document.forms["myform"]["repass"].value) ?true: false;
        }
        function validateform()
        {
            return valpass() & valname();
        }