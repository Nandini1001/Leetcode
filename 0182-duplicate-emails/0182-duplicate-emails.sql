# Write your MySQL query statement below
select distinct a.email as Email from Person a
join Person b
on a.email=b.email
where a.id!=b.id