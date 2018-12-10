DECLARE
str1 varchar(10);
str2 varchar(10);
len integer;
BEGIN
    str1 := '&first_string';
    len := length(str1);
    for i in reverse 1..len
        loop
            str2 := str2||substr(str1,i,1);
        end loop;
    str1 := lower(str1);
    str2 := lower(str2);
    dbms_output.put_line(str2);
    if str1 = str2
        then
        dbms_output.put_line('String is Palindrome');
    else
        dbms_output.put_line('Not Palindrome');
    end if;
END;

-- output
-- Enter value for first_string: malayalam
-- String is Palindrome


