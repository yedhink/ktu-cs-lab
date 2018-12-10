create table DEPT(
	dnum varchar2(20) PRIMARY KEY,
	dname varchar2(33) NOT NULL,
	ecount int,
	dhod varchar2(33)
);


create table EMP(
	enum varchar(20) PRIMARY KEY CHECK(enum LIKE 'e%'),
	ename varchar(33),
	salary int CHECK(salary!=0),
	dnum varchar(20),
	mno varchar(20),
	dateOfJoin date,
	job varchar(20),
	address varchar(20),
	city varchar(20) CHECK(city in ('cochin','bombay','madras','delhi')),
	pin varchar(20),
    CONSTRAINT fkeyDnum FOREIGN KEY(dnum) REFERENCES DEPT(dnum)
);

insert into EMP
values('e1','Yedhin',1000,'1','e5','26-FEB-98','Dev','Zeenath,Aluva','cochin','683101');

insert into DEPT
values(1,'DevOps',3,'Pankaj');
insert into DEPT
values(2,'SystemAdministration',3,'Varun');
insert into DEPT
values(3,'HPC',3,'Mahesh');
insert into DEPT
values(4,'TOC',3,'Anirudh');
insert into DEPT
values(5,'FOSS',3,'Justin');
insert into DEPT
values(10,'Database',3,'Siraj');
insert into DEPT
values(30,'Sales',3,'Prashant');
insert into DEPT
values(6,'Misc',30,'Sarah');



insert into EMP
values('e1','Yedhin',1000,'1','e5','26-FEB-98','Dev','Zeenath,Aluva','cochin','683101');
insert into EMP
values('e2','Tommy',2000,'2','e4','12-MAR-98','System','Mookkanoor','bombay','683101');
insert into EMP
values('e3','Johnny',3000,'3','e1','10-JUN-98','IOT','Kalmassery','cochin','683101');
insert into EMP
values('e4','Ravi',4000,'4','e3','15-JUN-98','WebDev','Ankamaly','madras','683101');
insert into EMPJOB
values('e5','Ragini',5000,'5','e2','05-JUL-98','Backend','Kottayam','delhi','683101');
insert into EMP
values('e16','Sanjay',60000,'10','e12','05-JUL-98','Frontend','Madurai','delhi','683101');
insert into EMP
values('e17','Manisha',30000,'30','e1','05-JUL-98','RPM','Adayar','madras','683101');

insert into EMP
values('e6','Leha',10000,'1','e10','26-FEB-97','Dev','Zeenath,Aluva','cochin','683101');
insert into EMP
values('e7','Mythili',20000,'2','e9','12-MAR-97','System','Mookkanoor','bombay','683101');
insert into EMP
values('e8','Varun',30000,'3','e6','10-JUN-97','IOT','Kalmassery','cochin','683101');
insert into EMP
values('e9','Zach',40000,'4','e8','15-JUN-97','WebDev','Ankamaly','madras','683101');
insert into EMP
values('e10','Varsha',50000,'10','e7','05-JUL-97','Backend','Kottayam','delhi','683101');


insert into EMP
values('e11','Kiki',1000,'1','e15','26-FEB-96','Dev','Zeenath,Aluva','cochin','683101');
insert into EMP
values('e12','Teena',2000,'2','e14','12-MAR-96','System','High Town','bombay','683101');
insert into EMP
values('e13','Sandeep',3000,'3','e11','10-JUN-96','IOT','Kalmassery','cochin','683101');
insert into EMP
values('e14','Sayooj',4000,'4','e13','15-JUN-96','WebDev','Chennai','madras','683101');
insert into EMP
values('e15','Roby',5000,'10','e12','05-JUL-96','Backend','Jhansi','delhi','683101');
insert into EMP
values('e18','Samad',5000,'10',NULL,'05-JUL-96','NoManager','Jhansi','delhi','683101');
insert into EMP
values('e19','Janvi',5000,'30','e11','05-JUL-96','SalesForce','Jhansi','delhi','683101');
insert into EMP
values('e20','Jannath',56000,'6','e14','05-JUL-96','SalesForce','Jhansi','delhi','683101');
insert into EMP
values('e21','Juniah',36000,'6','e14','05-JUL-2001','SalesForce','Jhansi','delhi','683101');
insert into EMP
values('e22','Karthik',36000,'6','e18','07-JAN-2001','SalesForce','Jhansi','delhi','683101');
insert into EMP
values('e23','Leo',500,'6','e2','07-JAN-2001','Manager','Jhansi','delhi','683101');
insert into EMP
values('e25','Jibi',6500,'6','e6','07-JAN-2001','Manager','Jhansi','delhi','683101');
insert into EMP
values('e24','Shiva',400,'6','e10','07-JAN-2001','Clerk','Madurai','delhi','683101');


# question 1
select ename
from emp
where dnum='10' and dateOfJoin>'01-JAN-98';

1)
ENAME
---------------------------------
Sanjay


# question 2
select ename
from emp,dept
where emp.dnum = dept.dnum and emp.dnum!='30';

2)
ENAME
---------------------------------
Yedhin
Tommy
Johnny
Ravi
Sanjay


# question 3
select ename
from emp,dept
where emp.dnum = dept.dnum and dept.dname='Sales';

3)
ENAME
---------------------------------
Manisha


# question 4
select ename
from emp
where mno is NULL;

4)
nil

# question 5
select ename
from emp
where ename LIKE 'J_n%';

5)
ENAME
---------------------------------
Jannath


# question 6
select ename
from emp
where dateOfJoin>'31-DEC-2000';

6)
ENAME
---------------------------------
Juniah
Karthik
Leo
Jibi
Shiva


# question 7
select 'Every Year'||ename||'Earns'||salary
from emp;

7)
'EVERY YEAR'||ENAME||' EARNS '||SALARY
--------------------------------------------------------------------------------
Every Year Yedhin Earns 1000
Every Year Tommy Earns 2000
Every Year Johnny Earns 3000
Every Year Ravi Earns 4000
Every Year Sanjay Earns 60000
Every Year Manisha Earns 30000
Every Year Jannath Earns 56000
Every Year Juniah Earns 36000
Every Year Karthik Earns 36000
Every Year Leo Earns 500
Every Year Jibi Earns 6500



# question 8
select count(*)
from emp;

8)
  COUNT(*)
----------
	12


# question 9
select emp.job,min(salary)
from emp
group by emp.dnum;

9)


# question 10
select emp.job,min(salary)
from emp
group by emp.job
having min(salary)>1000;

# question 11
select min(salary)
from emp
where job='Manager';

# question 12
select ename,dname
from emp,dept
where emp.dnum=dept.dnum;

# question 13
select ename,to_char(dateOfJoin,'dd/mm/yy')
from emp;
