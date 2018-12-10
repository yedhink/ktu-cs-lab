--create table stud(
--    roll number(3,0) primary key,
--    name varchar(6),
--    mark number(3),
--    grade varchar(2)
--);
--
--insert into stud
--values(1,'yedhin',90,NULL);
--insert into stud
--values(2,'zach',60,NULL);

DECLARE
    cursor user is
    select roll,name,mark,grade
    from STUD;
    no number(3);
    nm varchar(6);
    mrk number(3);
    grd varchar(2);
BEGIN
    --! standard way of looping through each row
    OPEN user;
    loop

        fetch user into no,nm,mrk,grd;
        --! break if no more user exists
        exit when user%notfound;
        set_grade(mrk,grd);
        update stud set grade=grd where roll=no;
        dbms_output.put_line('grade for '||nm||' is '||grd);
    end loop;
    CLOSE user;
END;

