# Write your MySQL query statement below
#report the sum of all total investment values in 2016 tiv_2016, for all policyholders
# same tiv_2015 value as one or more other policyholders
#not located in the same city as any other policyholder 

WITH HelperTable1 AS(
    SELECT tiv_2015, COUNT(*) as cnt FROM Insurance
    GROUP BY tiv_2015
),
HelperTable2 AS(
    SELECT lat, lon, COUNT(*) as location_cnt FROM Insurance 
    GROUP BY lat, lon 
),

MainTable AS(
SELECT i.pid,i.tiv_2015,i.tiv_2016,i.lat,i.lon,h1.cnt, h2.location_cnt FROM Insurance as i
JOIN HelperTable1 as h1
ON i.tiv_2015 = h1.tiv_2015

JOIN HelperTable2 h2
ON i.lat = h2.lat
AND i.lon = h2.lon
)

SELECT ROUND(SUM(tiv_2016),2) as tiv_2016 FROM MainTable 
WHERE cnt > 1 AND location_cnt = 1;