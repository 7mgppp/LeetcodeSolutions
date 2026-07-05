# Write your MySQL query statement below
#employee who has at least 1 other employee reporting to them.
#report the ids and the names of all managers,
#the number of employees who report directly to them
#average age of the reports rounded to the nearest integer.

select mgr.employee_id, mgr.name, COUNT(emp.employee_id) as reports_count, ROUND(AVG(emp.age)) as average_age
from employees emp join employees mgr
on emp.reports_to = mgr.employee_id
group by employee_id
order by employee_id


