create table account(
    accno number(3) constraint akey_p primary key,
    aname varchar(7),
    abal float check(abal>5000),
    branched varchar(3)
);

create table customer(
    cname varchar(7),
    caddr varchar(7)
);

create table branch(
    branched varchar(3),
    city varchar(7)
);

insert into customer
values('yedhin','aluva');
insert into customer
values('zach','kalady');
insert into branch
values('awy','aluva');

insert into account
values(1,'yedhin',6000,'awy');
insert into account
values(2,'yedhin',7000,'awy');
insert into account
values(3,'yedhin',8000,'awy');
insert into account
values(4,'yedhin',9000,'awy');
