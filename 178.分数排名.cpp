--
-- @lc app=leetcode.cn id=178 lang=mysql
--
-- [178] 分数排名
--
-- @lc code=start
select Score, 
    (select count(distinct Score) from Scores where Score >= s.Score) as 'Rank'
from Scores s
order by Score desc;
-- @lc code=end