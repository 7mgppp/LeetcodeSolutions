# Write your MySQL query statement below
#find the people who have the most friends and the most friends number.

#APROACH
#HelperTable has count each requester_id and acceptor_id 

WITH helperTable1 AS(
    SELECT requester_id, COUNT(*) as cnt FROM RequestAccepted
    GROUP BY requester_id
), 
helperTable2 AS(
    SELECT accepter_id, COUNT(*) as cnt FROM RequestAccepted
    GROUP BY accepter_id
),
MainHelperTable AS(
    SELECT requester_id AS id, cnt FROM HelperTable1

    UNION ALL

    SELECT accepter_id AS id, cnt FROM HelperTable2
)

SELECT id, SUM(cnt) AS num FROM MainHelperTable 
GROUP BY id
ORDER BY num DESC
LIMIT 1
