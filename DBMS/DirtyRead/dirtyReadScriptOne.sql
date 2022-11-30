use bank;
START TRANSACTION;
UPDATE accounts SET acc_bal = acc_bal - 100 where acc_id = 2;
SELECT Sleep(20);
ROLLBACK;
SELECT * FROM accounts WHERE acc_id = '2';
