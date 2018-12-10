create table EMP(
	eid varchar(10) PRIMARY KEY,
	ename char(15) NOT NULL,
	desg char(5),
	doj date,
	dob date,
	address varchar(20),
    basic int,
    da int,
    oa int
);

insert into EMP
values('e1','Yedhin','dev','26-FEB-18','03-MAR-98','Zeenath,Aluva',25000,500,100);
insert into EMP
values('e2','Zach','web','23-DEC-17','21-APR-97','Kalady',35000,600,300);

# question 1
select ename,basic+da+oa "salary"
from EMP;

1)
ENAME		    salary
--------------- ----------
Yedhin		     25600
Zach		     35900

# question 2
select ename,basic*23/100 "salary"
from EMP;

2)
ENAME		    salary
--------------- ----------
Yedhin		      5750
Zach		      8050

# question 3
select ename
from EMP
where basic+da+oa<30000 and basic+da+oa>5000;

3)
ENAME
---------------
Yedhin

# question 4
#select 100*sum(basic)*da/sum(da)*basic
select da*100/basic
from EMP;

4)
DA*100/BASIC
------------
	   1
  .857142857

# question 5
update EMP
set da=0.5*da
where da < 700;

5)
	DA
----------
       125
       150

# question 6
select ename
from emp
where doj > '23-DEC-17';

6)
ENAME
---------------
Yedhin

# question 7
select ename
from emp
where address LIKE 'K%y';

7)
ENAME
---------------
Zach

# question 8
select sum(basic),avg(basic)
from emp
where (desg,oa) in (
    select desg,oa
    from emp
);

8)
SUM(BASIC) AVG(BASIC)
---------- ----------
     60000	30000

