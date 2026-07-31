# Write your MySQL query statement below
SELECT tweet_id as tweet_id
FROM Tweets
WHERE LENGTH(content) > 15;