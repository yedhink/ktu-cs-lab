create table Customer_Master(
	accnt_no number(5) CONSTRAINT pkey_cm PRIMARY KEY,
	customer_fname char(10) NOT NULL,
    customer_lname char(15) NOT NULL,
	address char(15),
	accnt_type_id CONSTRAINT fkey_cm REFERENCES Account_Master,
    balance number(5) CHECK(balance>=200)
);

create table Transaction(
	trans_date date,
	trans_accnt_no Number(15),
    trans_type_id CONSTRAINT fkey_trans REFERENCES Transaction_Master,
    trans_amt Number(5) NOT NULL CHECK(trans_amt>0)
);

create table Account_Master(
	accnt_type_id char(10) PRIMARY KEY,
    accnt_type char(5) NOT NULL,
    rate number(5) NOT NULL
);

create table Transaction_Master(
	type_id char(5) CONSTRAINT pkey_tm PRIMARY KEY,
    tm_type char(5) NOT NULL
);

insert into Account_Master
values('am1','fd',10);
insert into Customer_Master
values(1,'Yedhin','Kizhakkethara','Aluva','am1',1000);
insert into Customer_Master
values(2,'Zach','Joshy','Kalady','am1',2000);
insert into Transaction_Master
values('tm1','wd');
insert into Transaction_Master
values('tm2','dep');
insert into Transaction
values('24-APR-2017',1,'tm1',1000);
insert into Transaction
values('27-APR-2017',2,'tm1',2000);
insert into Transaction
values('24-APR-2017',1,'tm2',500);
insert into Account_Master
values('am2','rd',20);
insert into Customer_Master
values(3,'Yadhu','Krish','Calicut','am2',5000);
insert into Customer_Master
values(2001,'Tony','Stark','Aluva','am1',1000);

# question 1
select min(balance) Minimum,max(balance) Maximum,avg(balance) Average,sum(balance) Sum
from Customer_Master;
  MINIMUM    MAXIMUM	 AVERAGE	SUM
---------- ---------- ---------- ----------
      1000	 2000	    1500       3000

# question 2
select trans_type_id id,min(trans_amt) Minimum,max(trans_amt) Maximum,avg(trans_amt) Average,sum(trans_amt) Sum
from Transaction
group by trans_type_id;
ID	 MINIMUM    MAXIMUM    AVERAGE	      SUM
----- ---------- ---------- ---------- ----------
tm1	    1000       2000	  1500	     3000
tm2	     500	500	   500	      500

# question 3
select customer_fname||customer_lname customer,count(*)
from Transaction
group by trans_type_id;
  COUNT(*)
----------
 2
 1
    
# question 4
select max(trans_amt)-min(trans_amt) diff
from Transaction;
  DIFF
----------
      1500

# question 5
select customer_fname||customer_lname name,accnt_type_id type,balance bal
from Customer_Master
where balance in(
    select min(balance)
    from Customer_Master
    group by accnt_type_id
    having min(balance)>500
);
NAME			  TYPE		    BAL
------------------------- ---------- ----------
Yedhin	  Kizhakkethara   am1		   1000
Yadhu	  Krish 	  am2		   5000


# question 6
select accnt_type_id,min(balance) bal
from Customer_Master
group by accnt_type_id
having min(balance)>500
order by bal desc;
ACCNT_TYPE	  BAL
---------- ----------
am2		 5000
am1		 1000

# question 7
select accnt_type_id Name,count(*) no_of_customers,avg(balance) avg_amt
from Customer_Master
group by accnt_type_id;
NAME	   NO_OF_CUSTOMERS    AVG_AMT
---------- --------------- ----------
am1			 2	 1500
am2			 1	 5000

# question 8
select trans_type_id,sum(trans_amt)
from Transaction
where trans_date>'09-MAR-2017' and trans_date<'10-MAY-2017'
group by trans_type_id;
TRANS SUM(TRANS_AMT)
----- --------------
tm1		3000
tm2		 500

# question 9
select UPPER(customer_fname) ||' '|| UPPER(customer_lname) UPPERCASE from Customer_Master;
select LOWER(customer_fname) || LOWER(customer_lname) LOWERCASE from Customer_Master;
select INITCAP(customer_fname) || INITCAP(customer_lname) FIRSTCAPS from Customer_Master;
UPPERCASE
--------------------------
YEDHIN   KIZHAKKETHARA
ZACH         JOSHY
YADHU   Krish
LOWERCASE
-------------------------
yedhin  kizhakkethara
zach  joshy
yadhu            krish
FIRSTCAPS
-------------------------
Yedhin  Kizhakkethara
Zach  JOSHYy
Yadhu  Krish

# question 10
select lpad(substr(customer_fname,0,8),9,'X') from Customer_Master;
select rpad(substr(customer_fname,0,8),9,'X') from Customer_Master;
LPAD(SUBS
---------
XYedhin
XZach
XYadhu
RPAD(SUBS
---------
YedhinX
ZachX
YadhuX

# question 11
select customer_fname fn, customer_lname ln, 'from' fr, Address ad, 'has' ha, LENGTH(CONCAT(customer_fname,customer_lname)) le, 'letters in his/her name.' let from Customer_Master;
FN	   LN		   FR	AD		HA	    LE LET
---------- --------------- ---- --------------- --- ---------- ------------------------
Yedhin	   Kizhakkethara   from Aluva		has	    25 letters in his/her name.
Zach	   Joshy	   from Kalady		has	    25 letters in his/her name.
Yadhu	   Krish	   from Calicut 	has	    25 letters in his/her name.

# question 12
insert into TRANSACTION values('15-APR-2018',2001,'tm2',10000);
update Customer_Master set balance=balance+10000 where accnt_no=2001;
SELECT cm.balance+cm.balance*3.5*am.rate/100 AS bal_after_35_years from Customer_Master cm, Account_Master am where accnt_no=2001 AND am.accnt_type_id=cm.accnt_type_id;
BAL_AFTER_3.5_YEARS
------------------
     14850
