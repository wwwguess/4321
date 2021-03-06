//  mo-shan-jue.c  □魔闪诀 
// dfbb@hero
                         

inherit SKILL;

string *dodge_msg = ({
        "$n身影一转，一式「动如参与商」轻易地避开了这一招。\n",
        "$n身法飘忽，一式「万事随转烛」左一点，右一顿，早已闪在一旁。\n",
        "但是$n身影一侧，一式「浮云终日行」在间不容发之际从容地避开了这一招。\n",
        "$n一式「心随雁飞灭」身形陡然拔高，使$N的攻势尽数落空。\n",
        "$n右足一点，一式「俯听闻惊风」身影向左滑开数尺，避了开去。\n",
});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练魔闪诀。\n");

        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 20
        ||      (int)me->query("gin") < 20 )
                return notify_fail("你的气或神不够，不能练魔闪诀。\n");
        me->receive_damage("kee", 10);
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("scholar") + "/mysterrier/" + action;
}
