create table Student(
	stud_no char(9) PRIMARY KEY,
	stud_lname char(30),
	stud_fname char(20),
	address char(50),
	city char(30),
	state char(2),
	postal_code char(9)
);

create table Instructor(
	instr_id char(5) PRIMARY KEY,
	instr_lname char(30),
	instr_fname char(20),
	instr_phone char(8)
);

create table Course(
	course_code char(6) PRIMARY KEY,
	course_title char(25),
	course_hrs Number(2,0)
);

create table Section(
	section_id char(7),
	time_offered char(10),
	days_offered char(10),
	section_room char(8),
	class_size Number(3,0) CHECK(class_size >= 0),
	number_enrolled Number(3,0) CHECK(number_enrolled >= 0),
	instructor_id char(5),
	course_code char(6),
    CONSTRAINT pkey_g1 PRIMARY KEY(section_id,time_offered),
    CONSTRAINT fkey_instructor_id FOREIGN KEY(instructor_id) REFERENCES Instructor(instr_id),
    CONSTRAINT fkey_course_code FOREIGN KEY(course_code) REFERENCES Course(course_code)
);

create table Enrollment(
	stud_no char(9),
	section_id char(7),
	grade char(2),
	time_offered char(10),
    CONSTRAINT pkey_g2 PRIMARY KEY(stud_no,section_id),
    CONSTRAINT fkey_g1 FOREIGN KEY(section_id,time_offered) REFERENCES Section(section_id,time_offered),
    CONSTRAINT fkey_stud_no FOREIGN KEY(stud_no) REFERENCES Student(stud_no)
);

# question 2
alter table Enrollment modify Grade char(4);

# question 3
alter table Instructor add instr_mailid char(15);

# question 4
create view instructor_sections_view as
select Instructor.instr_fname,Instructor.instr_lname,Section.time_offered,Section.days_offered,Section.section_room,Course.course_code,Course.course_title
from Instructor,Section,Course
where Instructor.instr_id = Section.instructor_id and Section.course_code = Course.course_code;

# question 5
insert into Student
values('111111111','Kizhakkethara','Yedhin','Kizhakkethara(h),Zeenath,Aluva','Kochi','Kerala','683101');

# question 6
insert into Course
values('CSIS240','WEB DESIGN',4);

# question 7
# first insert into Instructor the id
insert into Instructor
values('11113','Ques','Seven','9119233451','q7@gmail.com');
insert into Section
values('3011255','2-4','MW','BLGNG102',35,0,'11113','CSIS240');

# question 8
insert into Enrollment
values('111111111','3011255',NULL,'2-4');
