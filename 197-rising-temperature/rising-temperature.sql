# Write your MySQL query statement below
select w1.id from weather as w1   left join
weather as w2 on w1.recordDate=(w2.recordDate + INTERVAL 1 DAY ) where w1.temperature>w2.temperature ;
