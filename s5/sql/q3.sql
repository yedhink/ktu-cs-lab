# refer to question 2 for table creations

# question 1
update Section
set class_size = class_size + class_size * 0.1;

1)
CLASS_SIZE
----------
	43
	39

# question 2
insert into Section
values('3011236','1-6','TF','BLGNG103',35,0,'11113','CSIS240');
update Section
set time_offered = '2-4'
where section_id = '3011236';
update Section
set days_offered = 'MW'
where section_id = '3011236';

2)
SECTION TIME_OFFER DAYS_OFFER SECTION_ CLASS_SIZE NUMBER_ENROLLED INSTR COURSE_COD
------- ---------- ---------- -------- ---------- --------------- ----- ----------
3011255 2-4	   MW	      BLGNG102	       43		0 11113 CSIS240
3011236 2-4	   MW	      BLGNG102	       39		0 11113 CSIS240

# question 3
# wont be possible to delte since we have referred it as foreign key
# integrity constraint error
delete from Enrollment
where section_id = '3011236';
delete from Section
where section_id = '3011236';

3)
SECTION TIME_OFFER DAYS_OFFER SECTION_ CLASS_SIZE NUMBER_ENROLLED INSTR COURSE_COD
------- ---------- ---------- -------- ---------- --------------- ----- ----------
3011255 2-4	   MW	      BLGNG102	       43		0 11113 CSIS240

# question 4
# wont be possible to delte since we have referred it as foreign key
# integrity constraint error
delete from Course
where course_code = 'CSIS240';

4)
ORA-02292: integrity constraint (CS18616.FKEY_G1) violated - child record found

# question 5
select section_id,time_offered,days_offered,course_code
from Section
where class_size>=39 AND class_size<=50 AND days_offered LIKE 'M%';

5)
SECTION TIME_OFFER DAYS_OFFER COURSE_COD
------- ---------- ---------- ----------
3011255 2-4	   MW	      CSIS240

# question 6
select course_code,course_title,course_hrs
from Course
where course_hrs>=4
order by course_code DESC;

6)
COURSE_COD COURSE_TITLE 	     COURSE_HRS
---------- ------------------------- ----------
CSIS240    WEB DESIGN			      4

# question 7
select instructor_id,sum(class_size)
from Section
group by instructor_id
order by sum(class_size);

7)
INSTR SUM(CLASS_SIZE)
----- ---------------
11113		   82

# question 8
update Enrollment
set grade='-B'
where section_id='3011255';
select stud_no,section_id,grade
from Enrollment
where grade LIKE '%B%';

8)
STUD_NO   SECTION GRAD
--------- ------- ----
111111111 3011255 -B
9000	  3011255 -B

# question 9
select course_code,avg(class_size)
from Section
group by course_code;

9)
COURSE_COD AVG(CLASS_SIZE)
---------- ---------------
CSIS240 		41

# question 10
select i.instr_fname,i.instr_lname,s.time_offered,s.days_offered,s.section_room,c.course_code,c.course_title
from Instructor i,Section s,Course c
where s.instructor_id=i.instr_id and s.course_code = c.course_code;

10)
INSTR_FNAME	     INSTR_LNAME		    TIME_OFFER DAYS_OFFER SECTION_ COURSE_COD COURSE_TITLE
-------------------- ------------------------------ ---------- ---------- -------- ---------- -------------------------
Seven		     Ques			    2-4        MW	  BLGNG102 CSIS240    WEB DESIGN

# question 11
select stud_fname,stud_lname,section_id,grade
from Student s left join Enrollment e on (e.stud_no=s.stud_no);

11)
STUD_FNAME	     STUD_LNAME 		    SECTION GRAD
-------------------- ------------------------------ ------- ----
Yedhin		     Kizhakkethara		    3011255 -B
Ravi		     John			        3011255 -B

# question 12
insert into Student
values('1998','Man','Adhi','Aluva','Kochi','Kerala','683101');
select stud_fname||' '||stud_lname
from Student s,Enrollment e
where s.stud_no!=e.stud_no;

12)
STUD_FNAME||''||STUD_LNAME
---------------------------------------------------
Adhi		     Man

# question 13
insert into Student
values('9000','John','Ravi','Kadavantra','Kochi','Kerala','683101');
insert into Enrollment
values('9000','3011255',NULL,'2-4');
select s.stud_no,stud_fname||' '||stud_lname
from Student s,Enrollment e,Course c,Section se
where s.stud_no=e.stud_no and grade is NULL and c.course_code=se.course_code and se.section_id=e.section_id;

13)
STUD_NO   STUD_FNAME||''||STUD_LNAME
--------- ---------------------------------------------------
9000	  Ravi		       John

