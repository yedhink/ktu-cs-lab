create or replace trigger bank_trigger
before
insert on account
for each row
    DECLARE
        no number(2);
    BEGIN
        select count(*) into no from account where aname=:new.aname;
        dbms_output.put_line('count ======= '||no);
        if no = 3
            then
            dbms_output.put_line('trigger working');
            raise_application_error(-20001,'more than 3 accounts');
        end if;
    END;
