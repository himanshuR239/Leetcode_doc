# Write your MySQL query statement below
select
    d.name as department,
    e1.name as employee,
    e1.salary as salary
from employee e1
join department d on d.id = e1.departmentId
where 3 > (
    select count(distinct e2.salary) 
    from employee e2
    where
        e1.departmentId = e2.departmentId
    and e2.salary > e1.salary
)