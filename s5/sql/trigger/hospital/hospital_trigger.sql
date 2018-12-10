create or replace trigger hos_trigger
after
update of status on details
for each row
    when (new.status='yes')
        DECLARE
            name varchar(7);
            addr varchar(6);
        BEGIN
            select pname,paddr into name,addr from patient where pid=:new.pid;
            insert into history
            values(:old.pid,name,addr,:old.disease,:old.dname,sysdate);
            delete from patient where patient.pid=:new.pid;
        END;
