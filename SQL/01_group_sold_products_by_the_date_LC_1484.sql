-- https://leetcode.com/problems/group-sold-products-by-the-date/ 

-- GROUP_CONCAT sorts the column in ascending order by default, when used with DISTINCT
select 
  sell_date, 
  count(distinct product) as num_sold, 
  group_concat(distinct product) as products
from Activities
group by sell_date;