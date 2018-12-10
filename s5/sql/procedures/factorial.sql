DECLARE
num integer;
pro integer;
BEGIN
    num := &factorial;
    pro := 1;
    while (num!=0)
        loop
            pro := pro * num;
            num := num -1;
        end loop;
    dbms_output.put_line('factorial = '||pro);
END;

-- output
-- Enter value for factorial: 3
-- factorial = 6

