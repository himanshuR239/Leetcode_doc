with temp as (
    select 
        d.name as department,
        e.name as employee,
        e.salary as salary,
        dense_rank() over (
            partition by e.departmentId
            order by e.salary desc
        ) as rnk
    from employee e
    join department d on e.departmentId = d.id
)
select
    department, employee, salary
from temp
where rnk <= 3;