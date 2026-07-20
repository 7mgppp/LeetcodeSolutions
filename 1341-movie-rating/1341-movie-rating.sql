# Write your MySQL query statement below
#user who has rated the greatest number of movies.
#tie, return the lexicographically smaller user name.
#movie name with the highest average rating in February 2020
#tie, return the lexicographically smaller movie name.

#what kind of table do i need for checking most rating user -> user_id, MovieRating
#right join

#movie name with the highest average rating in February 2020 tables needed movies, MovingRating
#right join // use inner join its better thinking 

WITH HelperTable1 AS (
    SELECT u.user_id, u.name, COUNT(*) AS total_ratings FROM users AS u
    JOIN MovieRating AS mr
    ON u.user_id =  mr.user_id
    GROUP BY u.user_id, u.name
),
HelperTable2 AS (
    SELECT m.movie_id, m.title, AVG(mr.rating) AS Average_rating FROM movies AS m
    JOIN MovieRating AS mr
    on m.movie_id = mr.movie_id
    WHERE mr.created_at BETWEEN '2020-02-01' AND '2020-02-29'
    GROUP BY m.movie_id, m.title
)

(SELECT name AS results
FROM HelperTable1
ORDER BY total_ratings DESC, name ASC
LIMIT 1)

UNION ALL

(SELECT title AS results
FROM HelperTable2
ORDER BY average_rating DESC, title ASC
LIMIT 1)

