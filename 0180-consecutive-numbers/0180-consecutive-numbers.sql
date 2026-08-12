# Write your MySQL query statement below
with hp as (
    select num,
    lead(num,1) over() num1,
    lead(num,2) over() num2
    from logs

)

select distinct num ConsecutiveNums from hp where (num=num1) and (num=num2)