set serverout on;

create or replace procedure set_grade(mark in number,grade out varchar)
is
begin
    if (mark < 45)
        then
        grade := 'F';
    elsif (mark < 60)
        then
        grade := 'C';
    elsif (mark < 70)
        then
        grade := 'B';
    elsif (mark < 80)
        then
        grade := 'A';
    elsif (mark < 90)
        then
        grade := 'A+';
    else
        grade := 'O';
    end if;
end;
