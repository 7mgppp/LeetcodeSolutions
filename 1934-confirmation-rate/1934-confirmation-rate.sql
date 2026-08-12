# Write your MySQL query statement below
SELECT s.user_id , 
ifnull(round((SUM(c.action = 'confirmed') / COUNT(s.user_id)),2),0) as confirmation_rate
from Signups as s
left join Confirmations as c
On s.user_id = c.user_id
group by s.user_id;