DECLARE
    cursor user is
    select cnum,cur_read,prev_read,amount
    from BILL;
    amt integer;
    num integer;
    cur integer;
    prev integer;
    units integer;
BEGIN
    --! standard way of looping through each row
    OPEN user;
    loop
        fetch user into num,cur,prev,amt;
        --! break if no more user exists
        exit when user%notfound;
        units := cur-prev;
       if units < 50 and units >= 1
           then
           amt := 5*units;
       elsif units < 100 and units >= 50
           then
           amt := 10*units;
       elsif units < 200 and units >= 100
           then
           amt := 20*units;
	else
           then
           amt := 30*units;
       end if;
        update BILL set BILL.amount=amt where BILL.cnum=num;
        dbms_output.put_line('BILL');
        dbms_output.put_line('Consumer number : '||num||' has to pay '||amt||' rupees for '||units||' units');
    end loop;
    CLOSE user;
END;
