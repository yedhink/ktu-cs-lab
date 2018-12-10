create table patient(
    pid number(3) constraint pkey_p primary key,
    pname varchar(7),
    paddr varchar(6)
);

create table details(
    pid number(3) CONSTRAINT fkey_det REFERENCES patient,
    disease varchar(7),
    dname varchar(7),
    admission date,
    status varchar(3),
    amnt float
);

create table history(
    pid number(3) CONSTRAINT fkey_hist REFERENCES patient,
    pname varchar(7),
    paddr varchar(6),
    disease varchar(7),
    dname varchar(7),
    discharge date
);

insert into patient
values(1,'yedhin','aluva');
insert into details
values(1,'cough','doc1','01-JAN-2018','no',1000);

update details set status='yes' where pid=1;
