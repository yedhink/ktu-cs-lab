create table BILL(
	cnum Number(7) PRIMARY KEY,
	cur_read Number(5),
	prev_read Number(5)
);

insert into BILL
values(1,20,10);

insert into BILL
values(2,70,10);

insert into BILL
values(3,120,10);

insert into BILL
values(4,220,10);

--! extra : to add update amount from procedure
alter table BILL add amount Number(7);
