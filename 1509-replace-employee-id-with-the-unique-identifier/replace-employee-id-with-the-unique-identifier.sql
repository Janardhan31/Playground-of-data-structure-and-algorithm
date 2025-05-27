# Write your MySQL query statement below
select eu.unique_id, e.name
From Employees e
left join EmployeeUNI eu
on e.id=eu.id