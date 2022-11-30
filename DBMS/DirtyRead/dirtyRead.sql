
use bank;
create table accounts(
	acc_id INT NOT NULL auto_increment,
    acc_name VARCHAR(255),
    acc_bal INT NOT NULL,
    primary key(acc_id)
    
);
insert into accounts(acc_name,acc_bal) values("Om Gharge",500),("Shrenik J",1000),("Daulatrao P",1500);

select * from accounts;