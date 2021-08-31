--
-- @lc app=leetcode.cn id=177 lang=mysql
--
-- [177] 第N高的薪水
--
-- @lc code=start
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT BEGIN RETURN (
  # Write your MySQL query statement below.
  select distinct Salary
  from Employee
  order by Salary desc
  limit N, 1
);
END
-- @lc code=end