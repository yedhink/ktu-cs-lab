--create table employee(
--	eid number(3) PRIMARY KEY,
--  ename varchar(7),
--  salary number(7)
--);
--
--insert into employee
--values(1,'Yedhin',100000);
--insert into employee
--values(2,'Zach',20000);
set serverout on;
--declare
--    sal number(7);
--    id number(3);
--begin
--    id := &eid;
--    select salary into sal from employee where eid=id;
--    dbms_output.put_line('sal before: '||sal);
--    sal := increment_sal(id);
--    dbms_output.put_line('sal after : '||sal);
--    update employee set employee.salary=sal where employee.eid=id;
--end;

create or replace function increment_sal(id in number)
return number is new_sal number;
begin
    loop
        select salary into new_sal from employee where id=employee.eid;
        new_sal := new_sal + (new_sal * 0.1);
        return new_sal;
    end loop;
end;

--OUTPUT
SALARY BEFORE
----------
100000

SALARY AFTER
----------
110000
