DECLARE
amst integer;
cube integer;
digit integer;
temp integer;
BEGIN
    amst := &amstrong;
    cube := 0;
    temp := amst;
    while (temp!=0)
    loop
        digit := mod(temp,10);
        digit := digit*digit*digit;
        cube := cube + digit;
        temp := trunc(temp/10);
    end loop;
    if cube = amst
        then
        dbms_output.put_line('Number is Amstrong');
    else
        dbms_output.put_line('Not Amstrong');
    end if;
END;

-- output
-- Enter value for amstrong: 153
-- Number is Amstrong

