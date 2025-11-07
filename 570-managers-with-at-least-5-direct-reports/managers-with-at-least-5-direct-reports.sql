# Write your MySQL query statement below
select name from employee e1
where 5 <= (select count(*) from employee e2 where e1.id = e2.managerId);