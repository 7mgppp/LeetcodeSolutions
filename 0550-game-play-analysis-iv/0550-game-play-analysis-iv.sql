# Write your MySQL query statement below
#fraction of players that logged in again on the day after the day they first logged in, rounded to 2 decimal places.
#this is self join so we can figure out first login and second login
SELECT
ROUND(COUNT(*) /(SELECT COUNT(DISTINCT player_id) FROM Activity),2) AS fraction
FROM(SELECT player_id, MIN(event_date) AS first_login FROM Activity
GROUP BY player_id) f
JOIN Activity a
ON f.player_id = a.player_id
AND a.event_date = DATE_ADD(f.first_login, INTERVAL 1 DAY);