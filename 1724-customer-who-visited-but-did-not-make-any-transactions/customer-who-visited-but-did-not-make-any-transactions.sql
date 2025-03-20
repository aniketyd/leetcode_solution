# Write your MySQL query statement below
select visits.customer_id,count(visits.visit_id) as count_no_trans from visits
left join transactions on transactions.visit_id=visits.visit_id
where transactions.transaction_id is NULL group by customer_id;